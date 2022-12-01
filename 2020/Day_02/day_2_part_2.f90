program day_2
  implicit none

!  integer, parameter :: dp = selected_real_kind(15,300)

  integer, parameter          :: x = 1000
  


  character(1),  dimension(x) :: check_char
  character(30), dimension(x) :: char_list
  character(8)                :: range_hold
  character(2)                :: check_hold
  integer,  dimension(2, x)   :: num_range
  integer                     :: i, istat, allowed_strings = 0
  integer                     :: dash_index, blank_index
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, x
     read(unit = 10, fmt = *, iostat = istat) range_hold, check_hold, char_list(i)
     if(istat.ne.0) stop "Error reading from file"

     dash_index = scan(range_hold, "-")
     blank_index = scan(range_hold, " ")
     
     read(range_hold(1:dash_index-1), *) num_range(1,i)
     read(range_hold(dash_index+1:blank_index-1), *) num_range(2,i)
     check_char(i) = check_hold(1:1)

  end do

  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  do i = 1, x

     if ((char_list(i)(num_range(1,i):num_range(1,i)).eq.check_char(i))& !)then
          &.neqv.(char_list(i)(num_range(2,i):num_range(2,i)).eq.check_char(i)))then
        allowed_strings = allowed_strings+1
     end if
     
  end do

  print *, allowed_strings
  
  
end program day_2
