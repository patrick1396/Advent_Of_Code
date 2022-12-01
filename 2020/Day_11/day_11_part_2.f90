program day_11_part_1

  integer, parameter                                   :: max_num_lin = 91
  integer, parameter                                   :: max_lin_len = 90

!  integer, parameter                                   :: max_num_lin = 10
!  integer, parameter                                   :: max_lin_len = 10

  
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

           neighb_sum = line_of_sight(j, i, seats, max_num_lin, max_lin_len)

           if((neighb_sum.ge.5).and.(seats(j,i).eq.1)) then
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

contains

  function line_of_sight(x, y, seats, max_num_lin, max_lin_len)

    integer, intent(in)                                              :: x, y, max_num_lin, max_lin_len
    integer, dimension(0:max_lin_len+1, 0:max_num_lin+1), intent(in) :: seats

    integer, dimension(2, 8)                                         :: direct
    integer, dimension(8)                                            :: neighb
    integer                                                          :: curr_x, curr_y, i

    direct = reshape((/1, 0, -1, 0, 0, 1, 0, -1, 1, 1, -1, 1, 1, -1, -1, -1/), shape(direct))

    neighb(:) = 0

    do i = 1,8
       curr_x = x
       curr_y = y
       
       do while (((curr_x.gt.0).and.(curr_x.le.max_lin_len)).and.((curr_y.gt.0).and.(curr_y.le.max_num_lin)))

          curr_x = curr_x + direct(1,i)
          curr_y = curr_y + direct(2,i)

          if ((seats(curr_x, curr_y).eq.1).or.(seats(curr_x, curr_y).eq.0)) then
             neighb(i) = seats(curr_x, curr_y)
             exit
          end if
          
       end do
    end do

    
    line_of_sight = sum(neighb)
    
    
  end function line_of_sight
  
end program day_11_part_1
