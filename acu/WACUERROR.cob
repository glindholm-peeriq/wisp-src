000100**   Copyright (c) Shell Stream Software LLC, All rights reserved.
000200**
000300**
000400**   File:       WACUERROR.cob
000500**
000600**   Project:    WISP for Acucobol with Native Screens
000700**
000800**   Purpose:    Display a WISP error log error
000900**
001000**   Build:      ccbl -Da4 -o WACUERROR.acu WACUERROR.cob
001100**
001200**
001300
001400 IDENTIFICATION DIVISION.
001500 PROGRAM-ID.
001600     WACUERROR.
001700 REMARKS.
001800     This program will display an error string.
001900
002000 DATA DIVISION.
002100
002200 WORKING-STORAGE SECTION.
002300 01  NUM-LINES                PIC 99 VALUE 22.
002400
002500 LINKAGE SECTION.
002600 01  ERROR-STRING             PIC X(1500).
002700 01  FILLER REDEFINES ERROR-STRING.
002800     05  ERROR-LINE OCCURS 20 PIC X(75).
002900 01  ERROR-STRING-LEN         PIC 9999.
003000
003100 SCREEN SECTION.
003200 01  ERROR-SCREEN.
003300     05  LINE 1 COL 20 BOLD VALUE
003400         "**** RUNTIME ERROR DETECTED ****".
003500     05  LINE 2.
003600     05  LINE PLUS 1 COL 3 PIC X(75) OCCURS 20
003700         FROM ERROR-LINE BOLD.
003800     05  LINE 24 COL 20 BOLD VALUE
003900         "Press (ENTER) to continue.".
004000
004100 PROCEDURE DIVISION USING ERROR-STRING ERROR-STRING-LEN.
004200
004300 0000-START.
004400     COMPUTE NUM-LINES = (ERROR-STRING-LEN / 75) + 3.
004500     DISPLAY WINDOW LINE 1 COL 1 SIZE 80 LINES 24 ERASE.
004600     DISPLAY ERROR-SCREEN.
004700     DISPLAY BOX LINE 2 COL 2 SIZE 78 LINES NUM-LINES.
004800     ACCEPT OMITTED.
004900
005000 9999-EXIT.
005100     EXIT PROGRAM.
005200
005300 9999-STOP.
005400     STOP RUN.
