program day_11_part_1

  integer, parameter                                   :: max_num_lin = 786

  integer                                              :: x, y
  integer                                              :: size
  integer                                              :: index = 0
  integer, dimension(2,0:3)                            :: moves
  character(1)                                         :: action
  character(4)                                         :: in_str

  moves = reshape((/1, 0, 0, -1, -1, 0, 0, 1/), shape(moves))
  
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
        y = y+size
     case('S')
        y = y-size
     case('E')
        x = x+size
     case('W')
        x = x-size
     case('L')
        index = index - size/90
     case('R')
        index = index + size/90
     case('F')
        x = x + moves(1, modulo(index, 4))*size
        y = y + moves(2, modulo(index, 4))*size
     end select
     
  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  print *, abs(x)+abs(y)
end program day_11_part_1
