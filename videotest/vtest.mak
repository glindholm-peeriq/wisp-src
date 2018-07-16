#\************************************************************************\
#\*									*\
#\*		 Copyright (c) 1988, 1989, 1990, 1991, 1992		*\
#\*	 An unpublished work of International Digital Scientific Inc.	*\
#\*			    All rights reserved.			*\
#\*									*\
#\************************************************************************\
#
#
#	File:		vtest.mak
#
#	Function:	Makefile for VTEST on MS-DOS using Intel Code Builder
#
# 	History:
#			06\04\92	Changed to use make.include GSL
#			06\09\92	Removed copy. GSL
#			11/19/92	Changed for Intel C Code Builder

CDEBUG = /g

!include $(WISP)\src\port\dosmake.mak

PROGRAM = vtest.exe
OBJS = 	vtest0.obj vtesta.obj vtestb.obj vtestc.obj vtestd.obj vteste.obj \
vtestf.obj vtestg.obj vtesth.obj vtesti.obj vtestj.obj vtestk.obj vtestl.obj   \
vtestm.obj vtestn.obj vtesto.obj vtestp.obj vtestq.obj vtestr.obj vtests.obj   \
vtestt.obj vtestu.obj vtestv.obj vtestw.obj vtestx.obj vtesty.obj vtestz.obj \
$(STDLIB)\VIDEO.LIB
LINKFLAGS = -e $(PROGRAM) $(CDEBUG) graphics.lib

all:	$(STDBIN)\$(PROGRAM)

$(STDBIN)\$(PROGRAM):	$(PROGRAM) $(STDBIN)
	copy $(PROGRAM) $@

$(STDBIN):
	mkdir $(STDBIN)

!include $(CBPATH)\bin\link.mak


dump_map.obj: dump_map.c  $(V)\video.h
vtest0.obj:   vtest0.c    $(V)\video.h
vtesta.obj:   vtesta.c    $(V)\video.h
vtestb.obj:   vtestb.c    $(V)\video.h
vtestc.obj:   vtestc.c    $(V)\video.h
vtestd.obj:   vtestd.c    $(V)\video.h
vteste.obj:   vteste.c    $(V)\video.h
vtestf.obj:   vtestf.c    $(V)\video.h
vtestg.obj:   vtestg.c    $(V)\video.h
vtesth.obj:   vtesth.c    $(V)\video.h
vtesti.obj:   vtesti.c    $(V)\video.h
vtestj.obj:   vtestj.c    $(V)\video.h
vtestk.obj:   vtestk.c    $(V)\video.h
vtestl.obj:   vtestl.c    $(V)\video.h
vtestm.obj:   vtestm.c    $(V)\video.h
vtestn.obj:   vtestn.c    $(V)\video.h
vtesto.obj:   vtesto.c    $(V)\video.h   $(V)\vlocal.h
vtestp.obj:   vtestp.c    $(V)\video.h
vtestq.obj:   vtestq.c    $(V)\video.h
vtestr.obj:   vtestr.c    $(V)\video.h
vtests.obj:   vtests.c    $(V)\video.h
vtestt.obj:   vtestt.c    $(V)\video.h
vtestu.obj:   vtestu.c    $(V)\video.h
vtestv.obj:   vtestv.c    $(V)\video.h
vtestw.obj:   vtestw.c    $(V)\video.h
vtestx.obj:   vtestx.c    $(V)\video.h
vtesty.obj:   vtesty.c    $(V)\video.h
vtestz.obj:   vtestz.c    $(V)\video.h

