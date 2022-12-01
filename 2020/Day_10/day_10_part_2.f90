program day_10_part_1

  integer, parameter                          :: l_int = selected_int_kind(16)
  
!  integer, parameter                :: max_num_lin = 11
!  integer, parameter                :: max_num_lin = 31
  integer, parameter                :: max_num_lin = 107
  
  integer, dimension(-2:max_num_lin) :: in_int
  integer(kind=l_int), dimension(0:max_num_lin) :: permutations
  integer                           :: i, istat
  integer                           :: count = 0
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"

  in_int(-2:-1) = -3
  in_int(0) = 0
  permutations(0) = 1_l_int
  
  do i = 1, max_num_lin
     
     read(unit = 10, fmt = *, iostat = istat) in_int(i)
     if(istat.ne.0) stop "Error reading from file"
     
  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"
 
  call quick_sort(in_int, -2, max_num_lin)
  
 
  do i = 1, max_num_lin
     if((in_int(i)-in_int(i-3)).le.3) then
        permutations(i) = permutations(i-3)+permutations(i-2)+permutations(i-1)
     elseif((in_int(i)-in_int(i-2)).le.3) then
        permutations(i) = permutations(i-2)+permutations(i-1)
     elseif((in_int(i)-in_int(i-1)).le.3) then
        permutations(i) = permutations(i-1)
     end if

  end do

  print *, permutations(max_num_lin)
  
contains

  !Recursive subroutine that applies the quick sort algorithm to an array of type(tag_pair)
  !Comparisons for swapping done with the tag so that the tag_pair%index indicates the associated bosonic state
  !Pivot is always the final index of the array, not the most efficient way to do this
  recursive subroutine quick_sort(sort_array, min_indx, max_indx)

    integer, intent(in)                        :: min_indx, max_indx
    integer, dimension(min_indx:max_indx), intent(inout) :: sort_array
    
    integer :: swap_hold
    integer :: swap_indx
    integer :: i
 
    if (min_indx.le.max_indx) then
       swap_indx = min_indx
       do i = min_indx, max_indx-1
          if (sort_array(i).lt.sort_array(max_indx)) then
             swap_hold = sort_array(i)
             sort_array(i) = sort_array(swap_indx)
             sort_array(swap_indx) = swap_hold
             swap_indx = swap_indx + 1

          end if
       end do

       swap_hold = sort_array(max_indx)
       sort_array(max_indx) = sort_array(swap_indx)
       sort_array(swap_indx) = swap_hold

       !Once the position of the pivot is found, subroutine calls itself twice for the arrays either side of the pivot
       call quick_sort(sort_array(min_indx:swap_indx-1), min_indx, swap_indx-1)
       call quick_sort(sort_array(swap_indx+1: max_indx), swap_indx+1, max_indx)
    end if
  end subroutine quick_sort
  
end program day_10_part_1
