      subroutine add2(a,b,n)
      implicit none
      double precision a(1),b(1)
      integer n, i

      do i=1,n
         a(i)=a(i)+b(i)
      enddo
      return
      end
