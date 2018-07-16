#ifndef	_VSEGLB_H
#define	_VSEGLB_H
#include "vsegp.h"
#include "idsistd.h"

/*----
Language defaults
------*/

#define	NO_OF_TABS		10

#define	VSE_LANGUAGE_LEN	9

#define	COBOL_LANGUAGE		"COBOL    "
#define	C_LANGUAGE		"C        "
#define	TEXT_LANGUAGE		"TEXT     "
#define	SHELL_LANGUAGE		"SHELL    "
#define BASIC_LANGUAGE		"BASIC    "

#define	SHELL_TAB_STRING	"09 17 25 33 41 49 57 65 73 79"
#define	COBOL_TAB_STRING	"08 12 16 20 24 28 32 44 48 72"
#define	TEXT_TAB_STRING		"06 10 14 18 22 26 30 34 38 42"
#define DEFAULT_COB_TAB_STRING  "         X   X   X   X   X   X   X   X                                   X      "
#define DEFAULT_C_TAB_STRING    "            X   X   X   X   X   X   X   X   X                                   "
#define DEFAULT_BASIC_TAB_STRING  "         X   X   X   X   X   X   X   X                                   X      "
#define	C_TAB_STRING		TEXT_TAB_STRING
#define BASIC_TAB_STRING	COBOL_TAB_STRING

#define TAB_TO_FIELD 0
#define TAB_NORMAL 1

/* Added COBOL_MOD_COL_STRING, C_MOD_COL_STRING, and BASIC_MOD_COL_STRING
   to show mod fields when specified. Added by CIS: 07/22/93 AJA */

#define	COBOL_COL_STRING	"07 72"
#define	COBOL_MOD_COL_STRING	"07 69"
#define	TEXT_COL_STRING		"01 72"
#define	TEXT_MOD_COL_STRING	"01 69"
#define	C_COL_STRING		TEXT_COL_STRING
#define C_MOD_COL_STRING	TEXT_MOD_COL_STRING	
#define	SHELL_COL_STRING	TEXT_COL_STRING
#define SHELL_MOD_COL_STRING	TEXT_MOD_COL_STRING
#define BASIC_COL_STRING	COBOL_COL_STRING
#define BASIC_MOD_COL_STRING	COBOL_MOD_COL_STRING

#define	COBOL_CASE_MODE		"UPPER"
#define	C_CASE_MODE		"UPLOW"
#define	TEXT_CASE_MODE		"UPLOW"
#define	SHELL_CASE_MODE		"UPLOW"
#define BASIC_CASE_MODE		"UPPER"

#define	COBOL_MATCH_MODE	"EXACT"
#define	C_MATCH_MODE		"EXACT"
#define	TEXT_MATCH_MODE		"ANY  "
#define	SHELL_MATCH_MODE	"EXACT"
#define BASIC_MATCH_MODE	"EXACT"

#define	ALL_PFS			"000102030405060708091011121314151617181920212223242526272829303132X"
/*----
Setup so that these are defined in vseglb.c but declared everywhere
else
------*/

#ifdef	EXTERN_DEF 
#undef	EXTERN_DEF
#endif

#ifdef	_VSEGLB_C
#define	EXTERN_DEF	
#define	INIT_DEF_OA	={0x01,0xa0,0x00,0x00}
#define	INIT_LOCKED_OA	={0x01,0x00,0x00,0x00}
#define	INIT_100	=100L
#define	INIT_3_SPACES	="   "
#define	INIT_8_SPACES	="        "
#define	INIT_6_SPACES	="      "
#define	INIT_16_SPACES	="                "
#define	INIT_39_SPACES	="                                       "
#define	INIT_80_SPACES	="                                                                                "
#define	INIT_100_STRING	="100   "
#define	INIT_ALL_STRING	="ALL             "
#define	INIT_YES	="YES"
#define	INIT_NO		="NO "
#define	INIT_1		=1L
#define	INIT_ZERO	=0L
#define	INIT_15		=15
#define INIT_MINUS_ONE  = -1
#else
#define	EXTERN_DEF	extern
#define	INIT_DEF_OA
#define	INIT_LOCKED_OA
#define	INIT_100		
#define	INIT_3_SPACES
#define	INIT_8_SPACES
#define	INIT_6_SPACES
#define	INIT_16_SPACES
#define	INIT_39_SPACES
#define	INIT_80_SPACES
#define	INIT_100_STRING
#define	INIT_ALL_STRING
#define	INIT_YES
#define	INIT_NO
#define	INIT_ZERO
#define	INIT_1
#define	INIT_15
#define INIT_MINUS_ONE
#endif	/*_VSEGLB_C */

/*----
Globals for vse. Includes default parameters etc.
Eventually some of these will be modifiable by getparms or
some other method.

Some getparms have defaults that are only valid as Compile or Link
Options, these are included in the globals, but will have no
validity and are not issued as part of the getparms.
(unless this program is modified to include a compiel and
link option which is not intended for now)
------*/

/*----
INPUT GETPARM

Does not use output options
------*/
#define	VSE_FILENAME_LEN	8
#define	VSE_LIBNAME_LEN		8
#define	VSE_VOLNAME_LEN		6
#define	VSE_EXT_LEN		3

EXTERN_DEF 	char vse_gp_input_language[VSE_LANGUAGE_LEN+1];
EXTERN_DEF	char vse_gp_input_file[VSE_FILENAME_LEN+1]	INIT_8_SPACES;
EXTERN_DEF	char vse_gp_input_library[VSE_LIBNAME_LEN+1]	INIT_8_SPACES;
EXTERN_DEF	char vse_gp_input_volume[VSE_VOLNAME_LEN+1]	INIT_6_SPACES;
EXTERN_DEF	char vse_gp_input_ext[VSE_EXT_LEN+1]		INIT_3_SPACES;

/*----
The actual resulting system name
------*/

#define	VSE_SYSNAME_LEN	81	

EXTERN_DEF	char vse_sysname[VSE_SYSNAME_LEN+1]	INIT_80_SPACES;


/*----
RENUMBER GETPARM
------*/
EXTERN_DEF	char vse_gp_renumber_number[]	INIT_100_STRING;
EXTERN_DEF	char vse_gp_renumber_incr[]	INIT_100_STRING;
EXTERN_DEF	char vse_gp_renumber_start[]	INIT_ALL_STRING;
EXTERN_DEF	char vse_gp_renumber_end[]	INIT_16_SPACES;

/*----
REPLACE GETPARM

COMPRESS (output file) is not valid but included as a possible way of
indicating that a file should be hard-tabbed.
Not currently used
------*/
EXTERN_DEF	char vse_gp_replace_number[]	INIT_YES;
EXTERN_DEF 	char vse_gp_replace_compress[]	INIT_NO;

/*----
OPTIONS GETPARM
Does not use SCRATCH (scratch listing and OBJ before compile)
Does not use REPLACE (replace SOURCE with edited text before compile)
------*/
EXTERN_DEF	char vse_gp_options_scratch[]	INIT_YES;
EXTERN_DEF	char vse_gp_options_replace[]	INIT_NO;
EXTERN_DEF	char vse_gp_options_renumber[]	INIT_NO;
EXTERN_DEF	char vse_gp_options_number[]	INIT_100_STRING;
EXTERN_DEF	char vse_gp_options_incr[]	INIT_100_STRING;
EXTERN_DEF	char vse_gp_options_modcode[]	INIT_8_SPACES;

/*----
DEFAULTS GETPARM
------*/
#define	TABS_LEN	(NO_OF_TABS * 3)
#define	MODE_LEN	5
#define	CASE_LEN	5
#define	COLS_LEN	5

EXTERN_DEF	char vse_gp_defaults_tabs[TABS_LEN+1];
EXTERN_DEF	char vse_gp_defaults_mode[MODE_LEN+1];
EXTERN_DEF	char vse_gp_defaults_case[CASE_LEN+1];
EXTERN_DEF	char vse_gp_defaults_columns[COLS_LEN+1];
EXTERN_DEF	char vse_gp_defaults_showmod[]	INIT_NO;

EXTERN_DEF	char vse_defaults_modcol[COLS_LEN+1];

/*----
C versions of the numerics
------*/
EXTERN_DEF	int4 vse_renumber_number	INIT_100;
EXTERN_DEF	int4 vse_renumber_incr		INIT_100;
EXTERN_DEF	int4 vse_renumber_start		INIT_ZERO;
EXTERN_DEF	int4 vse_renumber_end		INIT_ZERO;


EXTERN_DEF	int4 vse_tab[NO_OF_TABS];

EXTERN_DEF	int4 vse_column[2];
EXTERN_DEF	int4 vse_text_width;

/* Added vse_mod_text_width for the width of text when mod codes are displayed.
   Added by CIS: 07/23/93 AJA */
EXTERN_DEF	int4 vse_mod_text_width;
EXTERN_DEF	int4 vse_append;

EXTERN_DEF	int4 vse_options_number		INIT_100;
EXTERN_DEF	int4 vse_options_incr		INIT_100;

/*----
Some WISP LIB required globals
------*/
EXTERN_DEF	char WISPFILEXT[]		INIT_39_SPACES;

/*----
Some switches that control program behaviour
------*/
EXTERN_DEF	int4 vse_native			INIT_ZERO;
EXTERN_DEF	int4 vse_new_file		INIT_ZERO;
EXTERN_DEF	int4 vse_numbering		INIT_1;
EXTERN_DEF	int4 vse_text_col;
EXTERN_DEF	int4 vse_num_col;
EXTERN_DEF	int4 vse_page_size		INIT_15;

/* Use vse_show_mod to specify if mode codes are displayed.
   Added by CIS: 07/22/93 AJA */
EXTERN_DEF	int4 vse_show_mod		INIT_ZERO;

/*----
Globals used in getparms
------*/

EXTERN_DEF int4 GPINT[255];
EXTERN_DEF GPARG gparg;
EXTERN_DEF int4 gpcnt;
EXTERN_DEF int4 gppfkeys;
EXTERN_DEF int4 gppfkey;
EXTERN_DEF char gppfrcvr[1];

/*----
The result codes of each getparm
------*/

EXTERN_DEF	int4	vse_input_pick;
EXTERN_DEF	int4	vse_create_pick;
EXTERN_DEF	int4	vse_edit_pick;
EXTERN_DEF	int4	vse_special_pick;
EXTERN_DEF	int4	vse_set_command_pick;


/*----
The pointer structure used for loading up a file
------*/
typedef struct _text{
	struct _text *next;
	struct _text *prev;
	char *text;
	char *modfld;
	int4	lineno;
	} TEXT;

EXTERN_DEF	TEXT	*text_first;
EXTERN_DEF	TEXT	*text_last;
EXTERN_DEF	TEXT	*scr_first;

/*
Pointer structure used to keep track of embedded line numbers in BASIC
*/
typedef struct _line_num
{
	TEXT *line;
	char start_state;
	int start_pos;
	int length;
	int4 branch;
	int4 old_branch;
	struct _line_num *next;
} line_num;

EXTERN_DEF line_num *head_linenum;

/*---
Some shorthand
------*/

#define	CLEAR_GLOBAL(x)	(memset(x,' ',sizeof(x)-1))
#define	CLEAR_FIELD(x)	(memset(x,' ',sizeof(x)-1))

/*----
More bloody globals
------*/

#define RESP_STARTNUM 1
#define RESP_INCR 2
#define RESP_RANGE 3

#define RENUM_INVAL_INCR -1
#define RENUM_BAD_RANGE -2

#define	EDIT_MENU	0L
#define	SPECIAL_MENU	1L

EXTERN_DEF int4 vse_renum_range_hi;
EXTERN_DEF int4 vse_renum_range_low;

EXTERN_DEF	int4 vse_menu;
EXTERN_DEF	char vse_default_oa[4]	INIT_DEF_OA;
EXTERN_DEF	char vse_locked_oa[4]	INIT_LOCKED_OA;
EXTERN_DEF	int4 vse_lines;
EXTERN_DEF	char vse_lines_message[81];
EXTERN_DEF	char vse_file_message[81];

EXTERN_DEF char vse_stat_message[81] INIT_80_SPACES;

EXTERN_DEF      char vse_tab_setting[81];

EXTERN_DEF int4 vse_file_linecount INIT_ZERO;

EXTERN_DEF int4 vse_save_row INIT_MINUS_ONE;
EXTERN_DEF int4 vse_save_col INIT_MINUS_ONE;

EXTERN_DEF int4 show_col_flag INIT_ZERO;

EXTERN_DEF int4 vse_file_changed INIT_ZERO;

#endif	/*_VSEGLB_H */

