      subroutine local_flat_t(u,ur,us,ut,n,D,Dt)
c     Output: ur,us,ut         Input:u,n,D,Dt
      double precision ur(0:n,0:n,0:n),us(0:n,0:n,0:n),ut(0:n,0:n,0:n)
      double precision u (0:n,0:n,0:n)
      double precision D (0:n,0:n),Dt(0:n,0:n)
      double precision temp
      integer n

      integer i,j,k,l

      do l=0,n
        do j=0,n
          do i=0,n
            temp = 0.0
            do k=0,n
              temp = temp + ur(k,j,l)*D(k,i)
              temp = temp + us(i,k,l)*D(k,j)
              temp = temp + ut(i,j,k)*D(k,l)
            enddo
            u(i,j,l) = temp
          enddo
        enddo
      enddo

      end
