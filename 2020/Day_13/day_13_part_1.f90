program day_13_part_1

  integer, parameter :: max_lin_len = 194
  integer            :: curr_time, bus_num, curr_bus
  integer            :: stat, j, i
  integer            :: diff, min_diff

  character(max_lin_len) :: in_str

  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"

  read(unit = 10, fmt = *, iostat=stat) curr_time
  if(istat.ne.0) stop "Error reading from file"


  read(unit = 10, fmt = '(A)', iostat = istat) in_str
  if(istat.ne.0) stop "Error reading from file"
  
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"


  i = 0
  min_diff = curr_time

  do j = 1, max_lin_len

     if (in_str(j:j).eq.",") then
        if(in_str(i+1:j-1).ne."x") then
           read(in_str(i+1:j-1), *, iostat=stat) bus_num
           diff = bus_num - modulo(curr_time, bus_num)
           if (diff.lt.min_diff) then
              min_diff = diff
              curr_bus = bus_num
           end if
        end if
        i = j
     end if
     
  end do

  print *, min_diff
  print *, curr_bus
  print *, min_diff*curr_bus
  
end program day_13_part_1
