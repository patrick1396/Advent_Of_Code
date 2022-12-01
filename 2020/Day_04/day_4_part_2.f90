program day_4
  implicit none

  integer, parameter                        :: max_num_lin = 1031
  integer, parameter                        :: max_lin_len = 100

  logical                                   :: end_of_line = .false., end_of_entry = .false.
  logical                                   :: check
  logical, dimension(7)                     :: fields_present
  character(max_lin_len)                    :: in_string
  character(3)                              :: field, eye_colour
  character(7)                              :: hair_colour
  character(9)                              :: pass_id
  character(10)                             :: in_height, num_vals = "0123456789"
  character(16)                             :: hex_vals = "0123456789abcdef"
  character(21)                             :: colours = "ambblubrngrygrnhzloth"
  integer                                   :: i, valid_entry=0, istat, space_pos, prev_space_pos, current_line = 0
  integer                                   :: year, height


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
              
              prev_space_pos = space_pos
              space_pos = index(in_string(prev_space_pos+1:), " ")
              select case(field)
              case ("byr")
                 
                 read(in_string(prev_space_pos+5:space_pos+prev_space_pos-1), *) year
                 if ((year.ge.1920).and.(year.le.2002)) then
                    fields_present(1) = .true.
                 end if
                 
              case ("iyr")
                 read(in_string(prev_space_pos+5:space_pos+prev_space_pos-1), *) year
                 if ((year.ge.2010).and.(year.le.2020)) then
                    fields_present(2) = .true.
                 end if
                 
              case ("eyr")
                 read(in_string(prev_space_pos+5:space_pos+prev_space_pos-1), *) year
                 if ((year.ge.2020).and.(year.le.2030)) then
                    fields_present(3) = .true.
                 end if
                 
              case ("hgt")
                 in_height = in_string(prev_space_pos+5:space_pos+prev_space_pos-1)

                 if (index(in_height, "cm").ne.0) then
                    read(in_height(1:index(in_height, "cm")-1), *) height
                    if ((height.ge.150).and.(height.le.193)) then
                       fields_present(4) = .true.
                    end if
                    
                 elseif (index(in_height, "in").ne.0) then
                    read(in_height(1:index(in_height, "in")-1), *) height
                    if ((height.ge.59).and.(height.le.76)) then
                       fields_present(4) = .true.
                    end if
                 end if
                 
              case ("hcl")
                 check = .true.
                 if (len(in_string(prev_space_pos+5:space_pos+prev_space_pos-1)).eq.7) then
                    
                    hair_colour = in_string(prev_space_pos+5:space_pos+prev_space_pos-1)
                    if (hair_colour(1:1).ne."#") then
                       check = .false.
                    end if
                    do i = 2,7
                       if (index(hex_vals, hair_colour(i:i)).eq.0) then
                          !print *, i
                          check = .false.
                       end if
                    end do
                 else
                    check = .false.
                 end if
                    fields_present(5) = check
                 
              case ("ecl")
                 eye_colour = in_string(prev_space_pos+5:space_pos+prev_space_pos-1)
                 if (index(colours, eye_colour).ne.0) then
                    fields_present(6) = .true.
                 end if
                 
              case ("pid")
                 check = .true.
                 if (len(in_string(prev_space_pos+5:space_pos+prev_space_pos-1)).eq.9) then
                    pass_id = in_string(prev_space_pos+5:space_pos+prev_space_pos-1)
                   
                    do i = 1,9
                       if (index(num_vals, pass_id(i:i)).eq.0) then
                          check = .false.
                       end if
                    end do
                 else
                    check = .false.
                 end if
                 fields_present(7) = check
              end select
              
              space_pos = index(trim(in_string(prev_space_pos+1:)), " ")
              if (space_pos.eq.0) then
                 end_of_line = .true.
              end if
              space_pos = space_pos+prev_space_pos
           end do
        end if


     end do

     if (all(fields_present).eqv..true.) then
        valid_entry = valid_entry+1
     end if
     print *, fields_present(:)
  end do

  close(unit = 10, iostat=istat)
  if(istat.ne.0) stop "error closing file"

  print *, valid_entry

end program day_4
