      subroutine local_grad3_t(u,ur,us,ut,N,D,Dt)
      implicit none
c     Output: ur,us,ut         Input:u,N,D,Dt
      double precision u (0:N,0:N,0:N)
      double precision  ur(0:N,0:N,0:N),us(0:N,0:N,0:N),ut(0:N,0:N,0:N)
      double precision D (0:N,0:N),Dt(0:N,0:N)
      double precision w (0:N,0:N,0:N)
      integer e,m1,m2,m3,N,k

      m1 = N+1
      m2 = m1*m1
      m3 = m1*m1*m1

      call mxm(Dt,m1,ur,m1,u,m2)

      do k=0,N
         call mxm(us(0,0,k),m1,D ,m1,w(0,0,k),m1)
      enddo
      call add2(u,w,m3)

      call mxm(ut,m2,D ,m1,w,m1)
      call add2(u,w,m3)

      return
      end
