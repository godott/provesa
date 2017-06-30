      subroutine local_flat_all16(w,u,gxyz,n,D)
      implicit none

c     Output: w         Input:u,n,D
      double precision u (0:n,0:n,0:n,16)
      double precision ur(0:n,0:n,0:n,16),us(0:n,0:n,0:n,16)
      double precision ut(0:n,0:n,0:n,16)
      double precision w (0:n,0:n,0:n,16), wr, ws, wt
      double precision D (0:n,0:n)
      double precision gxyz(6,(n+1)*(n+1)*(n+1),16)
      double precision temp,tr,ts,tt
      integer n

      integer i,j,k,l,m,e

      do e = 1,16
        m = 0
        do l=0,n
          do j=0,n
            do i=0,n
              m = m + 1
              tr = 0.0
              ts = 0.0
              tt = 0.0
              do k=0,n
                tr = tr + D(i,k)*u(k,j,l,e)
                ts = ts + u(i,k,l,e)*D(j,k)
                tt = tt + u(i,j,k,e)*D(l,k)
              enddo
              wr = gxyz(1,m,e)*tr + gxyz(2,m,e)*ts + gxyz(3,m,e)*tt
              ws = gxyz(2,m,e)*tr + gxyz(4,m,e)*ts + gxyz(5,m,e)*tt
              wt = gxyz(3,m,e)*tr + gxyz(5,m,e)*ts + gxyz(6,m,e)*tt
              ur(i,j,l,e) = wr
              us(i,j,l,e) = ws
              ut(i,j,l,e) = wt
            enddo
          enddo
        enddo

        do l=0,n
          do j=0,n
            do i=0,n
              temp = 0.0
              do k=0,n
                temp = temp + ur(k,j,l,e)*D(k,i)
                temp = temp + us(i,k,l,e)*D(k,j)
                temp = temp + ut(i,j,k,e)*D(k,l)
              enddo
              w(i,j,l,e) = 2.0
            enddo
          enddo
        enddo

      enddo
      end
