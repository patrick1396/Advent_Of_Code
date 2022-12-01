program day_11_part_1

  integer, parameter                                   :: max_num_lin = 91
  integer, parameter                                   :: max_lin_len = 90
  
  integer                                              :: num_occ = 0, neighb_sum, num_loops = 0 
  integer                                              :: i, j, istat
  logical                                              :: changes

  character(max_lin_len)                               :: in_str
  integer, dimension(0:max_lin_len+1, 0:max_num_lin+1) :: seats
  integer, dimension(max_lin_len, max_num_lin)         :: seats_hold
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"

  seats(:,:) = -1
  seats_hold(:,:) = -1
  
  do i = 1, max_num_lin
     
     read(unit = 10, fmt = *, iostat = istat) in_str
     if(istat.ne.0) stop "Error reading from file"
     
     do j = 1, max_lin_len
        if(in_str(j:j).eq."L") then
           seats(j, i) = 0
        end if
     end do

     
     
  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"


  changes = .true.
  do while (changes.eqv..true.)
     num_loops = num_loops+1
     changes = .false.
     do i = 1, max_num_lin
        do j = 1, max_lin_len

           if (seats(j,i).eq.-1) then
              cycle
           end if
           neighb_sum = sum(seats(j-1:j+1, i-1:i+1), mask=seats(j-1:j+1, i-1:i+1).ge.0)-seats(j,i)
           
           if((neighb_sum.ge.4).and.(seats(j,i).eq.1)) then
              seats_hold(j,i) = 0
              changes = .true.
              num_occ = num_occ-1
           elseif((neighb_sum.eq.0).and.(seats(j,i).eq.0)) then
              seats_hold(j,i) = 1
              changes = .true.
              num_occ = num_occ+1
           else
              seats_hold(j,i) = seats(j,i)
           end if
        end do
     end do
     seats(1:max_lin_len, 1:max_num_lin) = seats_hold(:,:)
  end do

  print *, num_loops
  print *, num_occ
  
end program day_11_part_1
