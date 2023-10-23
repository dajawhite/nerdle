# Project Details
C++ recreation of Nerdle
Write a version of Nerdle using SDL Plotter graphics object
- limit game to keyboard use
  
**Parts of Nerdle:**
  - tiles (length, width, value to display, color)
  - 6 rows of 8 tiles
  - 7th row with 10 tiles (for numbers 1 – 0)
  - 8th row with 7 tiles (operators, delete, enter)
  - each character entered needs to be checked with the puzzle
    - change color of tile if character is in correct position, if exists in puzzle but incorrect position, or not in puzzle at all
  - precondition of evaluation:
    - every input stream has 8 character (for the 8 tiles)
    - only 1 equal sign exists
    - no operators exist after the equal sign
  - there will either be one or two operators on left side

**Main Process:**
  1) prompt user to start
  2) read user input
  3) validate input using a while loop: 
      - 8 characters, one equal sign, no operators after equal sign, begin with a number
      - if all are true --> valid input
      - if any are false ask user to enter a different input
  4) once a valid input is given, exit while loop
  5) enter a for loop to match if each character exists in puzzle:
      - if string.find() returns true and index matches index of character being checked – tile should indicate correct position and character
      - if string.find() returns true and index doesn’t match index of character being checked – tile should indicate correct character, incorrect position
      - if string.find() returns string::npos – tile should return incorrect character and position
  6) once all locations in string have been checked, allow user to enter a new string in next row
  7) continue process until the user string completely matches the puzzle
  8) indicate when successfully guess
     
**Back End Process:**
  - Tile object
    - location on plotter, color, character to display
