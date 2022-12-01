program day_10_part_1

  integer, parameter              :: max_num_lin = 107
  
  integer, dimension(max_num_lin) :: in_int
  integer                         :: i, istat
  integer                         :: thr_diff = 1, two_diff = 0, one_diff = 1
  
  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do i = 1, max_num_lin
     
     read(unit = 10, fmt = *, iostat = istat) in_int(i)
     if(istat.ne.0) stop "Error reading from file"
     
  end do
  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"
  
  call quick_sort(in_int, 1, max_num_lin)

  do i = 2, max_num_lin
     if((in_int(i)-in_int(i-1)).eq.1) then
        one_diff = one_diff+1
     elseif((in_int(i)-in_int(i-1)).eq.3) then
        thr_diff = thr_diff+1
     elseif((in_int(i)-in_int(i-1)).eq.2) then
        two_diff = two_diff+1
     end if
  end do

  print *, one_diff
  print *, two_diff
  print *, thr_diff
  print *, one_diff*thr_diff
  
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
