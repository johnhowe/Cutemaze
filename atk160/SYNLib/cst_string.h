/* ----------------------------------------------------------- */
/*                                                             */
/*                _ ___      /__      ___  _                   */
/*               /_\ | |_/  /|_  |  |  |  |_                   */
/*               | | | | \ / |   |_ |  |  |_                   */
/*               =========/ ================                   */
/*                                                             */
/*        ATK Compatible Version of Alan Black's FLite         */
/*                                                             */
/*       Machine Intelligence Laboratory (Speech Group)        */
/*        Cambridge University Engineering Department          */
/*                  http://mi.eng.cam.ac.uk/                   */
/*                                                             */
/*           ATK Specific Code Copyright CUED 2005             */
/*           All other code as per the header below            */
/* ----------------------------------------------------------- */
/*************************************************************************/
/*                                                                       */
/*                  Language Technologies Institute                      */
/*                     Carnegie Mellon University                        */
/*                        Copyright (c) 1999                             */
/*                        All Rights Reserved.                           */
/*                                                                       */
/*  Permission is hereby granted, free of charge, to use and distribute  */
/*  this software and its documentation without restriction, including   */
/*  without limitation the rights to use, copy, modify, merge, publish,  */
/*  distribute, sublicense, and/or sell copies of this work, and to      */
/*  permit persons to whom this work is furnished to do so, subject to   */
/*  the following conditions:                                            */
/*   1. The code must retain the above copyright notice, this list of    */
/*      conditions and the following disclaimer.                         */
/*   2. Any modifications must be clearly marked as such.                */
/*   3. Original authors' names are not deleted.                         */
/*   4. The authors' names are not used to endorse or promote products   */
/*      derived from this software without specific prior written        */
/*      permission.                                                      */
/*                                                                       */
/*  CARNEGIE MELLON UNIVERSITY AND THE CONTRIBUTORS TO THIS WORK         */
/*  DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING      */
/*  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   */
/*  SHALL CARNEGIE MELLON UNIVERSITY NOR THE CONTRIBUTORS BE LIABLE      */
/*  FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    */
/*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN   */
/*  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,          */
/*  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF       */
/*  THIS SOFTWARE.                                                       */
/*                                                                       */
/*************************************************************************/
/*             Author:  Alan W Black (awb@cs.cmu.edu)                    */
/*               Date:  December 1999                                    */
/*************************************************************************/
/*                                                                       */
/*    String manipulation functions                                      */
/*                                                                       */
/*************************************************************************/
#ifndef __CST_STRING_H__
#define __CST_STRING_H__

#include <string.h>

#if defined(UNDER_CE) && (UNDER_CE < 300)
#define isalnum(a) iswalnum((wint_t)(a))
#define isupper(a) iswupper((wint_t)(a))
#define islower(a) iswlower((wint_t)(a))
#endif

#define cst_strchr(str, c) strchr((str),(c))
char *cst_strrchr(const char *str, int c);
double cst_atof(const char *str);

char *cst_strdup(const char *s);
#define cst_streq(A,B) (strcmp(A,B) == 0)
#define cst_streqn(A,B,N) (strncmp(A,B,N) == 0)
int cst_member_string(const char *str, const char * const *slist);
char *cst_substr(const char *str,int start, int length);

char *cst_string_before(const char *s,const char *c);

char *cst_downcase(const char *str);
char *cst_upcase(const char *str);

#endif
