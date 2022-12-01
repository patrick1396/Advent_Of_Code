program day_8
  implicit none

  !integer, parameter                        :: max_num_lin = 9
  integer, parameter                       :: max_num_lin = 683

  
  character(3), dimension(max_num_lin)     :: in_string
  character(3)                             :: hold_string
  integer, dimension(max_num_lin)          :: in_int
  integer, dimension(max_num_lin)          :: steps
  integer                                  :: acc = 0
  integer                                  :: i, j, istat, current_pos=1
  logical                                  :: loop = .true., fixed = .false.

  
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, max_num_lin
     
     read(unit = 10, fmt = *, iostat = istat) in_string(i), in_int(i)
     if(istat.ne.0) stop "Error reading from file"

  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  j=0
  do while (fixed.eqv..false.)
     j = j+1
     !print*, j
     loop = .true.

     hold_string = in_string(j)
     if (hold_string.eq."nop") then
        in_string(j) = "jmp"
     elseif (hold_string.eq."jmp") then
        in_string(j) = "nop"
     elseif (hold_string.eq."acc") then
        loop = .false.   
     end if
     
     i = 0
     acc = 0
     current_pos = 1
     steps(:) = -1
     do while (loop.eqv..true.)
        
        if(any(steps.eq.current_pos)) then
           loop = .false.
        elseif (current_pos.gt.max_num_lin) then
           loop = .false.
           fixed = .true.
        else
           i = i+1
           steps(i) = current_pos

           !print*, current_pos, in_string(current_pos)
           
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

     in_string(j) = hold_string
  end do
  
  print*, acc

end program day_8
