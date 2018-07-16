#ifndef	_VSEDSCR_H
#define	_VSEDSCR_H
#include "vseglb.h"
#include "vsescr.h"

#ifdef	EXTERN_DEF
#undef	EXTERN_DEF
#endif
#ifdef	_VSEDSCR_C
#define	EXTERN_DEF
#define	INIT_ALL_PFS	=ALL_PFS
#else
#define	EXTERN_DEF	extern
#define	INIT_ALL_PFS
#endif	/* _VSEDSCR_C */

EXTERN_DEF	char ed_scr[2000];	/* Was overflowing at 1924 */
EXTERN_DEF	char ed_pfs[]	INIT_ALL_PFS;
EXTERN_DEF	char ed_pfcode[3];
EXTERN_DEF	char ed_status[3];
EXTERN_DEF	char ed_oa[4];

EXTERN_DEF	char ed_top1[81],ed_top2[81],ed_top3[81],ed_top4[81];

EXTERN_DEF	char ed_line[20][81];
EXTERN_DEF	char ed_num[20][7];
EXTERN_DEF	char ed_mod[20][9];
EXTERN_DEF	TEXT *ed_txt[20];

EXTERN_DEF	VSESCR_FLDS(ed_menu_flds)
#ifdef	_VSEDSCR_C
 = {
{LEN(0)	ROW(1)	COL(2)	FROM(ed_top1)},
{LEN(0)	ROW(2)	COL(2)	FROM(ed_top2)},
{LEN(0)	ROW(3)	COL(2)	FROM(ed_top3)},
{LEN(0)	ROW(4)	COL(2)	FROM(ed_top4)},
{LASTITEM} }
#endif	/* _VSEDSCR_C */
;
EXTERN_DEF	VSESCR_FLDS(ed_line_flds)
#ifdef	_VSEDSCR_C
 = {
{LEN(72)	ROW(5)	COL(2)	USING(ed_line[0])},
{LEN(72)	ROW(6)	COL(2)	USING(ed_line[1])},
{LEN(72)	ROW(7)	COL(2)	USING(ed_line[2])},
{LEN(72)	ROW(8)	COL(2)	USING(ed_line[3])},
{LEN(72)	ROW(9)	COL(2)	USING(ed_line[4])},
{LEN(72)	ROW(10)	COL(2)	USING(ed_line[5])},
{LEN(72)	ROW(11)	COL(2)	USING(ed_line[6])},
{LEN(72)	ROW(12)	COL(2)	USING(ed_line[7])},
{LEN(72)	ROW(13)	COL(2)	USING(ed_line[8])},
{LEN(72)	ROW(14)	COL(2)	USING(ed_line[9])},
{LEN(72)	ROW(15)	COL(2)	USING(ed_line[10])},
{LEN(72)	ROW(16)	COL(2)	USING(ed_line[11])},
{LEN(72)	ROW(17)	COL(2)	USING(ed_line[12])},
{LEN(72)	ROW(18)	COL(2)	USING(ed_line[13])},
{LEN(72)	ROW(19)	COL(2)	USING(ed_line[14])},
{LEN(72)	ROW(20)	COL(2)	USING(ed_line[15])},
{LEN(72)	ROW(21)	COL(2)	USING(ed_line[16])},
{LEN(72)	ROW(22)	COL(2)	USING(ed_line[17])},
{LEN(72)	ROW(23)	COL(2)	USING(ed_line[18])},
{LEN(72)	ROW(24)	COL(2)	USING(ed_line[19])},
{LASTITEM} }
#endif	/* _VSEDSCR_C */
;

EXTERN_DEF	VSESCR_FLDS(ed_num_flds)
#ifdef	_VSEDSCR_C
 = {
{LEN(6)	ROW(5)	COL(2)	FROM(ed_num[0])},
{LEN(6)	ROW(6)	COL(2)	FROM(ed_num[1])},
{LEN(6)	ROW(7)	COL(2)	FROM(ed_num[2])},
{LEN(6)	ROW(8)	COL(2)	FROM(ed_num[3])},
{LEN(6)	ROW(9)	COL(2)	FROM(ed_num[4])},
{LEN(6)	ROW(10)	COL(2)	FROM(ed_num[5])},
{LEN(6)	ROW(11)	COL(2)	FROM(ed_num[6])},
{LEN(6)	ROW(12)	COL(2)	FROM(ed_num[7])},
{LEN(6)	ROW(13)	COL(2)	FROM(ed_num[8])},
{LEN(6)	ROW(14)	COL(2)	FROM(ed_num[9])},
{LEN(6)	ROW(15)	COL(2)	FROM(ed_num[10])},
{LEN(6)	ROW(16)	COL(2)	FROM(ed_num[11])},
{LEN(6)	ROW(17)	COL(2)	FROM(ed_num[12])},
{LEN(6)	ROW(18)	COL(2)	FROM(ed_num[13])},
{LEN(6)	ROW(19)	COL(2)	FROM(ed_num[14])},
{LEN(6)	ROW(20)	COL(2)	FROM(ed_num[15])},
{LEN(6)	ROW(21)	COL(2)	FROM(ed_num[16])},
{LEN(6)	ROW(22)	COL(2)	FROM(ed_num[17])},
{LEN(6)	ROW(23)	COL(2)	FROM(ed_num[18])},
{LEN(6)	ROW(24)	COL(2)	FROM(ed_num[19])},
{LASTITEM} }
#endif	/* VSEDSCR_C */
;
EXTERN_DEF	VSESCR_FLDS(ed_mod_flds)
#ifdef	_VSEDSCR_C
 = {
{LEN(8)	ROW(5)	COL(2)	FROM(ed_mod[0])},
{LEN(8)	ROW(6)	COL(2)	FROM(ed_mod[1])},
{LEN(8)	ROW(7)	COL(2)	FROM(ed_mod[2])},
{LEN(8)	ROW(8)	COL(2)	FROM(ed_mod[3])},
{LEN(8)	ROW(9)	COL(2)	FROM(ed_mod[4])},
{LEN(8)	ROW(10)	COL(2)	FROM(ed_mod[5])},
{LEN(8)	ROW(11)	COL(2)	FROM(ed_mod[6])},
{LEN(8)	ROW(12)	COL(2)	FROM(ed_mod[7])},
{LEN(8)	ROW(13)	COL(2)	FROM(ed_mod[8])},
{LEN(8)	ROW(14)	COL(2)	FROM(ed_mod[9])},
{LEN(8)	ROW(15)	COL(2)	FROM(ed_mod[10])},
{LEN(8)	ROW(16)	COL(2)	FROM(ed_mod[11])},
{LEN(8)	ROW(17)	COL(2)	FROM(ed_mod[12])},
{LEN(8)	ROW(18)	COL(2)	FROM(ed_mod[13])},
{LEN(8)	ROW(19)	COL(2)	FROM(ed_mod[14])},
{LEN(8)	ROW(20)	COL(2)	FROM(ed_mod[15])},
{LEN(8)	ROW(21)	COL(2)	FROM(ed_mod[16])},
{LEN(8)	ROW(22)	COL(2)	FROM(ed_mod[17])},
{LEN(8)	ROW(23)	COL(2)	FROM(ed_mod[18])},
{LEN(8)	ROW(24)	COL(2)	FROM(ed_mod[19])},
{LASTITEM} }
#endif	/* _VSEDSCR_C */
;
#endif	/* _VSEDSCR_H */
