program day_3
  implicit none

  integer, parameter                        :: max_y = 323
  integer, parameter                        :: max_x = 31
  
  character(max_x)                          :: in_string
  character(1), dimension(0:max_x-1, max_y) :: track
  integer                                   :: i, j, istat
  integer                                   :: x_pos = 1, y_pos = 1
  integer                                   :: num_col = 0
  integer, dimension(3, 5)                  :: move

  move = reshape((/1, 1, 0, 3, 1, 0, 5, 1, 0, 7, 1, 0, 1, 2, 0/), shape(move))

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


  do i = 1, 5
     num_col = 0
     x_pos = 1
     y_pos = 1
     do while (y_pos .le. max_y)
        if (track(modulo(x_pos, max_x), y_pos).eq."#") then
           num_col = num_col+1
        end if
        
        x_pos = x_pos+move(1,i)
        y_pos = y_pos+move(2,i)
     end do
     move(3,i) = num_col
  end do

  print*, move(3,:)
  

end program day_3
