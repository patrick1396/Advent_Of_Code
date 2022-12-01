program day_4
  implicit none

  integer, parameter                        :: max_num_lin = 2248
  integer, parameter                        :: max_lin_len = 26

  logical                                   :: end_of_entry = .false.
  logical                                   :: check
  character(max_lin_len)                    :: in_string
  character(26)                             :: letters = "abcdefghijklmnopqrstuvwxyz"
  integer                                   :: current_line, istat, character_counter, i
  integer                                   :: sum_entries = 0, ppl_per_entry
  integer, dimension(26)                    :: fields_present

  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do while (current_line.lt.max_num_lin)
     end_of_entry=.false.
     fields_present(:) = 0
     ppl_per_entry = 0
     do while (end_of_entry.eqv..false.)
        read(unit = 10, fmt = '(A)', iostat = istat) in_string
        if(istat.ne.0) stop "Error reading from file"
        print *, in_string
        current_line = current_line+1
        

        if (trim(in_string) .eq. "") then
           end_of_entry = .true.
        else
           ppl_per_entry = ppl_per_entry+1
           do character_counter = 1, len(trim(in_string))
              i = index(letters, in_string(character_counter:character_counter))
              fields_present(i) = fields_present(i) + 1
              
           end do
        end if


     end do
     print *, sum(fields_present(:)/ppl_per_entry)
     sum_entries = sum_entries+sum(fields_present(:)/ppl_per_entry)
  end do

  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  print *, sum_entries

end program day_4
