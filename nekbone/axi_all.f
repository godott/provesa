#define NUMDIM 3

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

      do e16= fel, lel, 16
        do j=1,16
          e = e16 + j - 1
            call local_flat_all(w3(1,j),u(1,e),gxyz(1,1,e),nx1-1,dxm1)
        enddo
      enddo

      return
      end
