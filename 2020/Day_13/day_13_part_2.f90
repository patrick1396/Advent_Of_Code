program day_13_part_2

  integer, parameter :: j15 = selected_int_kind(15)
  integer(kind=j15), parameter :: max_lin_len = 195
  integer(kind=j15)  :: num_x, l_mulp, check_num, next_time = 0
  
  integer(kind=j15)  :: bus_num, prev_bus
  integer            :: stat, j, i
  integer            :: diff, min_diff
  logical            :: first_bus = .true., found

  character(max_lin_len) :: in_str

  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"

  read(unit = 10, fmt = *, iostat=stat) in_str
  if(istat.ne.0) stop "Error reading from file"


  read(unit = 10, fmt = '(A)', iostat = istat) in_str
  if(istat.ne.0) stop "Error reading from file"
  
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  
  i = 0
  num_x = 0

  do j = 1, max_lin_len

     if ((in_str(j:j).eq.",").or.(j.eq.max_lin_len)) then
        if(in_str(i+1:j-1).ne."x") then
           read(in_str(i+1:j-1), *, iostat=stat) bus_num
           print *, bus_num
           
           if (first_bus.eqv..true.) then
              l_mulp = bus_num
              !check_num = l_mulp
              first_bus = .false.
           else

              next_time = find_lcm(l_mulp, bus_num, next_time, num_x)

              l_mulp = l_mulp*bus_num
!              l_mulp = find_lcm(l_mulp, bus_num, l_mulp, 0_j15)
              

           end if

        end if
        i = j
        num_x = num_x+1
     end if
     
  end do

  print *, next_time

contains

  function find_lcm(int_1, int_2, start, offset) result(lcm)
    implicit none

    integer, parameter :: j15 = selected_int_kind(15)
    integer(kind=j15), intent(in) :: int_1, int_2, offset, start
    integer(kind=j15)             :: lcm

    integer(kind=j15)             :: l_mulp, check_num
    logical                       :: found

    found = .false.


    check_num = start
    do while(found.eqv..false.)
       
       if (modulo(check_num+offset, int_2).eq.0) then
          lcm = check_num
          
          found = .true.
       else
          check_num = check_num+int_1
       end if

    end do
    

    

  end function find_lcm
  
end program day_13_part_2
