      *
      * --- START OF COPYBOOK:  WCLINKX.COB ---
      *
       DATA DIVISION.

       LINKAGE SECTION.
       01  PROGRAM-NAME PIC X(8).
       01  PARM-1       PIC X.
       01  PARM-2       PIC X.
       01  PARM-3       PIC X.
       01  PARM-4       PIC X.
       01  PARM-5       PIC X.
       01  PARM-6       PIC X.
       01  PARM-7       PIC X.
       01  PARM-8       PIC X.
       01  PARM-9       PIC X.
       01  PARM-10      PIC X.
       01  PARM-11      PIC X.
       01  PARM-12      PIC X.
       01  PARM-13      PIC X.
       01  PARM-14      PIC X.
       01  PARM-15      PIC X.
       01  PARM-16      PIC X.
       01  PARM-17      PIC X.
       01  PARM-18      PIC X.
       01  PARM-19      PIC X.
       01  PARM-20      PIC X.
       01  PARM-21      PIC X.
       01  PARM-22      PIC X.
       01  PARM-23      PIC X.
       01  PARM-24      PIC X.
       01  PARM-25      PIC X.
       01  PARM-26      PIC X.
       01  PARM-27      PIC X.
       01  PARM-28      PIC X.
       01  PARM-29      PIC X.
       01  PARM-30      PIC X.
       01  PARM-31      PIC X.
       01  PARM-32      PIC X.
       01  RETURN-VALUE PIC 9(9) COMP.

       PROCEDURE DIVISION USING
                          PROGRAM-NAME,
                          PARM-1,  PARM-2,  PARM-3,  PARM-4,
                          PARM-5,  PARM-6,  PARM-7,  PARM-8,
                          PARM-9,  PARM-10, PARM-11, PARM-12,
                          PARM-13, PARM-14, PARM-15, PARM-16,
                          PARM-17, PARM-18, PARM-19, PARM-20,
                          PARM-21, PARM-22, PARM-23, PARM-24,
                          PARM-25, PARM-26, PARM-27, PARM-28,
                          PARM-29, PARM-30, PARM-31, PARM-32,
                          RETURN-VALUE.

       WISP-LINK-SUBROUTINE-BEGIN.

           MOVE 1 TO RETURN-VALUE.
           CALL PROGRAM-NAME USING
                          PARM-1,  PARM-2,  PARM-3,  PARM-4,
                          PARM-5,  PARM-6,  PARM-7,  PARM-8,
                          PARM-9,  PARM-10, PARM-11, PARM-12,
                          PARM-13, PARM-14, PARM-15, PARM-16,
                          PARM-17, PARM-18, PARM-19, PARM-20,
                          PARM-21, PARM-22, PARM-23, PARM-24,
                          PARM-25, PARM-26, PARM-27, PARM-28,
                          PARM-29, PARM-30, PARM-31, PARM-32
                ON EXCEPTION MOVE 0 TO RETURN-VALUE
                NOT ON EXCEPTION CANCEL PROGRAM-NAME.
           EXIT PROGRAM.
      *
      * --- END OF COPYBOOK ---
      *
