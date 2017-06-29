#define NUMDIM 3
c#define NUMGP 10
c#define NUMEL 7040

      program csatest

      integer ldim
      parameter (ldim = NUMDIM)
      integer nx1, ny1, nz1, nelt
      parameter (nx1=NUMGP, ny1=NUMGP, nz1=NUMGP, nelt=NUMEL)
      integer nxyz
      parameter (nxyz=nx1*ny1*nz1)
      double precision dxm1(nx1,nx1), dxtm1(nx1,nx1)

      double precision w(nx1*ny1*nz1,nelt),u(nx1*ny1*nz1,nelt)
      double precision gxyz(2*ldim,nx1*ny1*nz1,nelt)
      integer n, thread, numth, i, j, k
      integer fel, lel, find, lind
      integer omp_get_thread_num, omp_get_num_threads

      common /dxyz/ dxm1, dxtm1
 
      write(*,*) "nx1 = ", nx1
      write(*,*) "nelt = ", nelt

      n = nx1*ny1*nz1

      w = 1.0
      do j = 1,nelt
        do i= 1,n
          u(i,j) = 1.0 + 1.0 / (1.0*(i+j)) 
          do k=1,6
            gxyz(k,i,j) = 1.0 + 1.0 / (1.0*i+2.0*j+3.0*k) 
          enddo
        enddo
      enddo
      do i = 1, nx1
        do j = 1,nx1
          dxm1(j,i) = 1.0 + 1.0 / (1.0*(i+2*j))
          dxtm1(i,j) = 1.0 + 1.0 / (1.0*(i+2*j))
        enddo
      enddo

      write(*,*) "Data initialized"

c$OMP PARALLEL DEFAULT(shared) PRIVATE(thread,numth,find,lind,fel,lel)

      thread = 0
      numth = 1
#ifdef _OPENMP
      thread = omp_get_thread_num()
      numth = omp_get_num_threads()
#endif

      if (numth < nelt) then
        fel = (thread*nelt)/numth + 1
        lel = ((thread+1)*nelt)/numth
      else
        if (thread < nelt) then
          fel = thread + 1
          lel = fel
        else
          fel = nelt+1
          lel = nelt
        end if
      end if

      find = (fel-1) *(nx1*ny1*nz1)+1
      lind = lel * (nx1*ny1*nz1)

      if (thread == 1) then
        write(*,*) "threads = ", numth
        write(*,*) "Calling axi()"
c       write(*,*) "thread ", thread, fel, lel, find, lind
      end if

      call axi(w,u,gxyz,n,fel,lel,find,lind)

c$OMP END PARALLEL

      write(*,*) "simulation complete"

      end program csatest

c-----------------------------------------------------------------------
      subroutine axi(w,u,gxyz,n,fel,lel,find,lind) ! Matrix-vector product: w=A*u
      implicit none

c     imports dxm1, dxtm1, nx1, ny1, nz1, nelt, ldim, nxyz
      integer ldim
      parameter (ldim = NUMDIM)
      integer nx1, ny1, nz1, nelt
      parameter (nx1=NUMGP, ny1=NUMGP, nz1=NUMGP, nelt=NUMEL)
      integer nxyz
      parameter (nxyz=nx1*ny1*nz1)

      double precision w(nx1*ny1*nz1,nelt),u(nx1*ny1*nz1,nelt)
      double precision gxyz(2*ldim,nx1*ny1*nz1,nelt)
      integer n
      integer fel, lel, find, lind

      double precision ur(nx1*ny1*nz1,16),us(nx1*ny1*nz1,16)
      double precision ut(nx1*ny1*nz1,16)
      double precision ur2(nx1*ny1*nz1,16),us2(nx1*ny1*nz1,16)
      double precision ut2(nx1*ny1*nz1,16)
      double precision ur3(nx1*ny1*nz1,16),us3(nx1*ny1*nz1,16)
      double precision ut3(nx1*ny1*nz1,16)
      double precision w2(nx1*ny1*nz1,16)
      double precision w3(nx1*ny1*nz1,16)
      double precision w4(nx1*ny1*nz1,16)
      double precision wr, ws, wt
      integer e,i,j,e16

      double precision dxm1(nx1,nx1), dxtm1(nx1,nx1)
      common /dxyz/ dxm1, dxtm1

c     write(*,*) "axi", fel, lel
c     write(*,*) "nx1= ", nx1, " ny1 = ", ny1, " nz1 = ", nz1

      do e= fel, lel
          call local_grad3(ur(1,j),us(1,j),ut(1,j),u(1,e),
     +         nx1-1,dxm1,dxtm1)

        do i=1,nxyz
          wr = gxyz(1,i,e)*ur(i,j) + gxyz(2,i,e)*us(i,j) + 
     +         gxyz(3,i,e)*ut(i,j)
          ws = gxyz(2,i,e)*ur(i,j) + gxyz(4,i,e)*us(i,j) + 
     +         gxyz(5,i,e)*ut(i,j)
          wt = gxyz(3,i,e)*ur(i,j) + gxyz(5,i,e)*us(i,j) + 
     +         gxyz(6,i,e)*ut(i,j)
          ur(i,j) = wr
          us(i,j) = ws
          ut(i,j) = wt
        enddo

            call local_grad3_t(w(1,e),ur(1,j),us(1,j),ut(1,j),
     +           nx1-1,dxm1,dxtm1)
      enddo

      return
      end
