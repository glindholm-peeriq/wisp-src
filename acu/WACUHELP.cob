000100**   Copyright (c) Shell Stream Software LLC, All rights reserved.
000200**
000300**
000400**   File:       WACUHELP.cob
000500**
000600**   Project:    WISP for Acucobol with Native Screens
000700**
000800**   Purpose:    Process Wang style HELP key
000900**
001000**   Build:      ccbl -Da4 -o WACUHELP.acu WACUHELP.cob
001100**
001200**
001300
001400 IDENTIFICATION DIVISION.
001500 PROGRAM-ID.
001600     WACUHELP.
001700 DATA DIVISION.
001800
001900 WORKING-STORAGE SECTION.
002000
002500 PROCEDURE DIVISION.
002600
002700 0000-START.
002800     CALL "WISPHELP".
002810     DISPLAY WINDOW ERASE.
003200
003300 9999-EXIT.
003400     EXIT PROGRAM.
003500
003600 9999-STOP.
003700     STOP RUN.
