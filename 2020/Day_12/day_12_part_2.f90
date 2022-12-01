program day_11_part_1

  integer, parameter                                   :: max_num_lin = 786
!  integer, parameter                                   :: max_num_lin = 5
  
  integer                                              :: x, y
  integer                                              :: size
  integer                                              :: index = 0
  integer, dimension(2)                                :: waypoint = (/10, 1/)
  integer, dimension(2, 2, 4)                          :: rotations
  character(1)                                         :: action
  character(4)                                         :: in_str

  rotations = reshape((/0, -1, 1, 0, -1, 0, 0, -1, 0, 1, -1, 0, 1, 0, 0, 1/), shape(rotations))
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, max_num_lin


     read(unit = 10, fmt = *, iostat = istat) in_str
     if(istat.ne.0) stop "Error reading from file"

     action = in_str(1:1)
     read(in_str(2:len(trim(in_str))), fmt=*, iostat = istat) size
     if(istat.ne.0) stop "Error reading from string"

     select case(action)
     case('N')
        waypoint(2) = waypoint(2)+size
     case('S')
        waypoint(2) = waypoint(2)-size
     case('E')
        waypoint(1) = waypoint(1)+size
     case('W')
        waypoint(1) = waypoint(1)-size
     case('L')
        index = size/90
        waypoint = matmul(transpose(rotations(:,:,index)), waypoint)
     case('R')
        index = size/90
        waypoint = matmul(rotations(:,:,index), waypoint)
     case('F')
        x = x + waypoint(1)*size
        y = y + waypoint(2)*size
     end select
     
  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  print *, abs(x)+abs(y)
end program day_11_part_1
