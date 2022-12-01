program day_1
  implicit none

!  integer, parameter :: dp = selected_real_kind(15,300)

!  integer, dimension(6)   :: data = (/1721, 979, 366, 299, 675, 1456/)
  integer, dimension(200) :: data
  integer                 :: i, j, k, len, istat

  len = size(data)

  open(unit=10, file = "in_data.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, len
     read(unit = 10, fmt = *, iostat = istat) data(i)
     if(istat.ne.0) stop "Error reading from file"
  end do

  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  
  outer: do i = 1, len
     do j = i, len
        do k = j, len
           if ((data(i)+data(j)+data(k)).eq.2020) then
              exit outer
           end if
        end do
     end do
  end do outer

  print *, data(i), data(j), data(k)
  print *, data(i)*data(j)*data(k)

  
end program day_1
