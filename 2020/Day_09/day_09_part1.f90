program day_8
  implicit none

  integer, parameter                          :: l_int = selected_int_kind(16)

!  integer, parameter                        :: max_num_lin = 20
  integer, parameter                          :: max_num_lin = 1000

  integer, parameter                          :: preamble = 25

  integer(kind=l_int), dimension(max_num_lin) :: in_int
  integer(kind=l_int)                         :: i, j, crnt_num, istat, cont_sum
  logical(kind=l_int)                         :: sum = .true., loop = .true.
  

  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, max_num_lin
     
     read(unit = 10, fmt = *, iostat = istat) in_int(i)
     if(istat.ne.0) stop "Error reading from file"
     
  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  crnt_num = preamble
  
  do while (sum.eqv..true.)
     crnt_num = crnt_num+1
     sum = .false.
     outer_1: do i = crnt_num-preamble, crnt_num-1
        do j = i, crnt_num-1
           if(in_int(crnt_num).eq.in_int(i)+in_int(j)) then
              sum = .true.
              exit outer_1
           end if
           
        end do
     end do outer_1

  end do
  print *, in_int(crnt_num)

  outer_2: do i = 1, max_num_lin
     loop = .true.
     j = i
     cont_sum = in_int(j)
     do while (loop.eqv..true.)
        j = j+1
        cont_sum = cont_sum+in_int(j)
        if (cont_sum.gt.in_int(crnt_num))then
           loop=.false.
        elseif (cont_sum.eq.in_int(crnt_num)) then
           exit outer_2
        end if
     end do
  end do outer_2

  print *, minval(in_int(i:j))+maxval(in_int(i:j))
  
  
end program day_8
