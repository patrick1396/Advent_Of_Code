program day_4
  implicit none

  integer, parameter                        :: max_num_lin = 1031
  integer, parameter                        :: max_lin_len = 100

  logical                                   :: end_of_line = .false., end_of_entry = .false.
  logical, dimension(7)                     :: fields_present
  character(max_lin_len)                    :: in_string
  character(3)                              :: field
  integer                                   :: i, valid_entry=0, istat, space_pos, prev_space_pos, current_line = 0
!  integer                                   :: year


  open(unit=10, file = "input.txt", status = "old", iostat = istat)
  if(istat.ne.0) stop "Error opening file"
  
  do while (current_line.lt.max_num_lin)
     end_of_entry=.false.
     fields_present(:) = .false.
     do while (end_of_entry.eqv..false.)
        read(unit = 10, fmt = '(A)', iostat = istat) in_string
        if(istat.ne.0) stop "Error reading from file"
        !print *, in_string
        current_line = current_line+1
        !print *, current_line

        if (trim(in_string) .eq. "") then
           end_of_entry = .true.
        else
           space_pos = 0
           end_of_line = .false.
           do while (end_of_line.eqv..false.)
              field = trim(in_string(space_pos+1:space_pos+3))

              select case(field)
              case ("byr")

                 fields_present(1) = .true.
              case ("iyr")
                 read(trim(in_string(space_pos+5:space_pos+8))) year
                 fields_present(2) = .true.
              case ("eyr")
                 read(trim(in_string(space_pos+5:space_pos+8))) year
                 fields_present(3) = .true.
              case ("hgt")
                 fields_present(4) = .true.
              case ("hcl")
                 fields_present(5) = .true.
              case ("ecl")
                 fields_present(6) = .true.
              case ("pid")
                 fields_present(7) = .true.
              end select
              prev_space_pos = space_pos
              space_pos = index(trim(in_string(prev_space_pos+1:)), " ")
              if (space_pos.eq.0) then
                 end_of_line = .true.
              end if
              space_pos = space_pos+prev_space_pos
           end do
        end if
        !print *, fields_present
        if (all(fields_present).eqv..true.) then
           !print *,"<>"
           valid_entry = valid_entry+1
           fields_present(:) = .false.
        end if
     end do
  end do

  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  print *, valid_entry

end program day_4
