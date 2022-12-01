program day_8
  implicit none

  !integer, parameter                        :: max_num_lin = 9
  integer, parameter                       :: max_num_lin = 683

  
  character(3), dimension(max_num_lin)     :: in_string
  integer, dimension(max_num_lin)          :: in_int
  integer, dimension(max_num_lin)          :: steps
  integer                                  :: acc = 0
  integer                                  :: i, istat, current_pos=1
  logical                                  :: loop = .true.

  steps(:) = max_num_lin+1
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, max_num_lin
     
     read(unit = 10, fmt = *, iostat = istat) in_string(i), in_int(i)
     if(istat.ne.0) stop "Error reading from file"

  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  i = 0
  do while (loop.eqv..true.)
     !print*, current_pos
     if(any(steps.eq.current_pos)) then
        loop = .false.
     else
        i = i+1
        steps(i) = current_pos
        
        select case (in_string(current_pos))
        case("nop")
           current_pos = current_pos+1
           
        case("acc")
           acc = acc + in_int(current_pos)
           current_pos = current_pos+1
           
        case("jmp")
           current_pos = current_pos + in_int(current_pos)
           
        end select

     end if
  end do

  print*, acc

end program day_8
