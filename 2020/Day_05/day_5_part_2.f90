program day_2
  implicit none

!  integer, parameter :: dp = selected_real_kind(15,300)

  integer, parameter             :: x = 799
  integer, parameter             :: seat_id_min = 89
  integer, parameter             :: seat_id_max = 888


  character(10)                               :: in_string
  integer                                     :: row_min, row_max, col_min, col_max
  integer                                     :: row, col, seat_id_curr
  integer, dimension(seat_id_min:seat_id_max) :: seats
  integer                                     :: i, j, istat

  seats(:) = 0
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"

  do i = 1, x
    
     read(unit = 10, fmt = *, iostat = istat) in_string
     if(istat.ne.0) stop "Error reading from file"
     row_min = 0
     row_max = 127
     col_min = 0
     col_max = 7

     do j = 1,7
        if (in_string(j:j) .eq. "F") then
           row_max = row_max-(row_max-row_min+1)/2
        else
           row_min = row_min+(row_max-row_min+1)/2
        end if
     end do
     row = row_min

     do j = 8,10
        if (in_string(j:j) .eq. "L") then
           col_max = col_max-(col_max-col_min+1)/2
        else
           col_min = col_min+(col_max-col_min+1)/2
        end if
     end do
     col = col_min

     seat_id_curr = row*8+col

     seats(seat_id_curr) = seat_id_curr
  end do
  
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  print *, findloc(seats, VALUE=0)+88
  
end program day_2
