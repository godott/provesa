      program test_vector
          implicit none
          double precision :: u 
          double precision :: ur(10, 10)
          integer :: i, j
          u = 3.0
          do i = 1, 10
            do j = 1, 10
                ur(i,j) = 1.0
            enddo
          enddo
          call my_test(ur ,u)
          do i = 1, 10
            do j = 1, 10
                write (*, *) "haha", ur(i,j) 
            enddo
          enddo
         end program test_vector

      subroutine my_test(ur, u)
          double precision :: u(10, 10), ur(10, 10)

          do i = 1, 10
            do j = 1, 10
                ur(i,j) = u(i, j)
            enddo
          enddo

          end subroutine my_test

