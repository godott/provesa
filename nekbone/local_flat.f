      subroutine local_flat(ur,us,ut,u,n,D,Dt)
c     Output: ur,us,ut         Input:u,n,D,Dt
      double precision ur(0:n,0:n,0:n),us(0:n,0:n,0:n),ut(0:n,0:n,0:n)
      double precision u (0:n,0:n,0:n)
      double precision D (0:n,0:n),Dt(0:n,0:n)
      integer n

      integer i,j,k,l

      do l=0,n
        do j=0,n
          do i=0,n
            ur(i,j,l) = 0.0
            us(i,j,l) = 0.0
            ut(i,j,l) = 0.0
            do k=0,n
              ur(i,j,l) = ur(i,j,l) + D(i,k)*u(k,j,l)
              us(i,j,l) = us(i,j,l) + u(i,k,l)*Dt(k,j)
              ut(i,j,l) = ut(i,j,l) + u(i,j,k)*Dt(k,l)
            enddo
          enddo
        enddo
      enddo

      end
