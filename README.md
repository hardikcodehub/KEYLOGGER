# KEYLOGGER

BEGINNER KEYBOARD ACTIVITY LOGGER
================================

Files:
1. keylog.c
2. keystrokes.log   (created after running the program)

-------------------------------------------------------------------------------------------------------------------------
WHAT THIS PROJECT DOES
-----------------------
I made a small keyboard activity logger in C for typing analysis.

It records keyboard input from its own console window and stores:
- time of every key
- printable characters
- SPACE
- ENTER
- BACKSPACE
- TAB
- ESC
- other unknown keys as a simple [KEY_number] format

I kept the program simple because I am still learning C.
-------------------------------------------------------------------------------------------------------------------------
HOW TO USE
----------
1. Start the program.
2. Type in the console.
3. Press ESC when you want to stop.
4. The program prints the session statistics.
5. It creates keystrokes.log.
-------------------------------------------------------------------------------------------------------------------------
WHAT THE PROGRAM SHOWS
----------------------
1. Total keystrokes
2. Number of letters
3. Number of backspaces
4. Estimated WPM
5. Backspace percentage
6. Active runtime
7. Key frequency table
8. A simple text heatmap
