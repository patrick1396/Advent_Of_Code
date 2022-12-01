program day_2
  implicit none

!  integer, parameter :: dp = selected_real_kind(15,300)

  integer, parameter          :: x = 1000
  


  character(1),  dimension(x) :: check_char
  character(30), dimension(x) :: char_list
  character(8)                :: range_hold
  character(2)                :: check_hold
  integer,  dimension(2, x)   :: num_range
  integer                     :: i, istat, instance_counter, allowed_strings = 0, index, prev_index
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
     instance_counter = 0
     prev_index = 0
     index = scan(char_list(i)(1:), check_char(i))
     do while (index.gt.0)
        instance_counter = instance_counter+1
        prev_index = prev_index+index
        index = scan(char_list(i)(prev_index+1:), check_char(i))
        !index = 0
     end do

     if ((instance_counter.ge.num_range(1,i)).and.(instance_counter.le.num_range(2,i))) then
        allowed_strings = allowed_strings+1
     end if
     
  end do

  print *, allowed_strings
  
  
end program day_2
