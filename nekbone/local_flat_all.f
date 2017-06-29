      subroutine local_flat_all(w,u,gxyz,n,D)
      implicit none

c     Output: w         Input:u,n,D
      double precision u (0:n,0:n,0:n)
      double precision ur(0:n,0:n,0:n),us(0:n,0:n,0:n),ut(0:n,0:n,0:n)
      double precision w (0:n,0:n,0:n), wr, ws, wt
      double precision D (0:n,0:n)
      double precision gxyz(6,n*n*n)
      double precision temp,tempr,temps,tempt
      integer n

      integer i,j,k,l,m

      m = 0
      do l=0,n
        do j=0,n
          do i=0,n
            m = m + 1
            tempr = 0.0
            temps = 0.0
            tempt = 0.0
            do k=0,n
              tempr = tempr + D(i,k)*u(k,j,l)
              temps = temps + u(i,k,l)*D(j,k)
              tempt = tempt + u(i,j,k)*D(l,k)
            enddo
            wr = gxyz(1,m)*tempr + gxyz(2,m)*temps + gxyz(3,m)*tempt
            ws = gxyz(2,m)*tempr + gxyz(4,m)*temps + gxyz(5,m)*tempt
            wt = gxyz(3,m)*tempr + gxyz(5,m)*temps + gxyz(6,m)*tempt
            ur(i,j,l) = wr
            us(i,j,l) = ws
            ut(i,j,l) = wt
          enddo
        enddo
      enddo

      do l=0,n
        do j=0,n
          do i=0,n
            temp = 0.0
            do k=0,n
              temp = temp + ur(k,j,l)*D(k,i)
              temp = temp + us(i,k,l)*D(k,j)
              temp = temp + ut(i,j,k)*D(k,l)
            enddo
            w(i,j,l) = temp
          enddo
        enddo
      enddo

      end
