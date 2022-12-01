
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
  end subroutine tag_quick_sort


  !Changes to be made, shouldn't just be divided by 2, it should be the difference of the upper and lower indices divided by 2 added to the lower index
  recursive function tag_search(search_array, search_item, min_indx, max_indx) result(indx)
    
    integer, intent(in)                                         :: min_indx, max_indx
    type(tag_pair), dimension(min_indx:max_indx), intent(inout) :: search_array
    real(kind=dp), intent(in)                                   :: search_item

    integer                                                     :: indx
    print *, min_indx, max_indx
    if (search_array(max_indx/2)%tag.eq.search_item) then
       indx = search_array(max_indx/2)%indx
    elseif(max_indx.eq.min_indx) then
       indx = (-1)
    elseif(search_array(max_indx/2)%tag.gt.search_item) then
       indx = tag_search(search_array(min_indx:max_indx/2), search_item, min_indx, max_indx/2)
    elseif(search_array(max_indx/2)%tag.lt.search_item) then
       indx = tag_search(search_array((max_indx/2)+1:max_indx), search_item, (max_indx/2)+1, max_indx)
    end if
    
  end function tag_search
  
