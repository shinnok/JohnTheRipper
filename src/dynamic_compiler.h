/*
 * This software was written by Jim Fougeron jfoug AT cox dot net
 * in 2015. No copyright is claimed, and the software is hereby
 * placed in the public domain. In case this attempt to disclaim
 * copyright and place the software in the public domain is deemed
 * null and void, then the software is Copyright (c) 2015 Jim Fougeron
 * and it is hereby released to the general public under the following
 * terms:
 *
 * This software may be modified, redistributed, and used for any
 * purpose, in source and binary forms, with or without modification.
 *
 * Expression to Generic 'scriptable' compiler/builder for the
 * existing dynamic format.
 */

#if !defined (__DYNAMIC_COMPILER_H__)
#define __DYNAMIC_COMPILER_H__

typedef void *DC_HANDLE;

extern int dynamic_compile(const char *expr, DC_HANDLE *pH);
extern int dynamic_assign_script_to_format(DC_HANDLE H, struct fmt_main *pFmt);
extern char *dynamic_compile_split(char *inp);
extern char *dynamic_compile_prepare(char *fld0, char *fld1);
extern void dynamic_compile_done();
extern DC_HANDLE dynamic_compile_library(const char *expr, uint32_t crc32);

#define DC_MAGIC 0x654d7baf

/* this structure is WHAT is pointed to by a DC_HANDLE */
typedef struct DC_struct {
	uint32_t magic;
	uint32_t crc32; // hash of pExpr
	struct fmt_main *pFmt;
	char *pExpr;
	char *pExtraParams;
	char *pScript;
	char *pSignature;
	char *pLine1;
	char *pLine2;
	char *pLine3;
} DC_struct;

#endif // __DYNAMIC_COMPILER_H__
