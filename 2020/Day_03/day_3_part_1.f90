program day_3
  implicit none

  integer, parameter                        :: max_y = 323
  integer, parameter                        :: max_x = 31
  
  character(max_x)                          :: in_string
  character(1), dimension(0:max_x-1, max_y) :: track
  integer                                   :: i, j, istat
  integer                                   :: x_pos = 1, y_pos = 1
  integer                                   :: num_col = 0

  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, max_y
     read(unit = 10, fmt = *, iostat = istat) in_string
     if(istat.ne.0) stop "Error reading from file"

     do j = 0, max_x-1
        track(j, i) = in_string(j+1:j+1) 
     end do

  end do

  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  track = cshift(track, -1, 1)

  do i = 1, max_y
     print *, track(:, i)
  end do

  do while (y_pos .le. max_y)
     if (track(modulo(x_pos, max_x), y_pos).eq."#") then
        num_col = num_col+1
     end if

     x_pos = x_pos+3
     y_pos = y_pos+1
  end do

  print *, num_col

end program day_3
