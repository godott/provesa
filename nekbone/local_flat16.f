      subroutine local_flat16(ur,us,ut,u,n,D,Dt)
c     Output: ur,us,ut         Input:u,n,D,Dt
      double precision ur(0:n,0:n,0:n,16),us(0:n,0:n,0:n,16)
      double precision u (0:n,0:n,0:n,16),ut(0:n,0:n,0:n,16)
      double precision D (0:n,0:n),Dt(0:n,0:n)
      integer n

      integer i,j,k,l,e

      do e=1,16
        do l=0,n
          do j=0,n
            do i=0,n
              ur(i,j,l,e) = 0.0
              us(i,j,l,e) = 0.0
              ut(i,j,l,e) = 0.0
              do k=0,n
                ur(i,j,l,e) = ur(i,j,l,e) + u(k,j,l,e)*D(i,k)
                us(i,j,l,e) = us(i,j,l,e) + u(i,k,l,e)*D(j,k)
                ut(i,j,l,e) = ut(i,j,l,e) + u(i,j,k,e)*D(l,k)
              enddo
            enddo
          enddo
        enddo
      enddo

      end
