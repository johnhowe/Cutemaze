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
/*  Lexicon related functions                                            */
/*                                                                       */
/*************************************************************************/
#ifndef _CST_LEXICON_H__
#define _CST_LEXICON_H__

#include <stdio.h>

#include "cst_item.h"
#include "cst_lts.h"

typedef struct lexicon_entry_struct {
    char *word_pos;
    int phone_index;
} lexicon_entry;

typedef struct lexicon_struct {
    char *name;
    int num_entries;
    lexicon_entry *entry_index;
    unsigned char *phones;
    char **phone_table;

    cst_lts_rules *lts_rule_set;

    int (*syl_boundary)(const cst_item *i,const cst_val *p);

    cst_val *(*lts_function)(const struct lexicon_struct *l, const char *word, const char *pos);

    char ***addenda;
} cst_lexicon;

cst_lexicon *new_lexicon();
void delete_lexicon(cst_lexicon *lex);

lexicon_entry *lex_add_entry(cst_lexicon *l, const char *word, const char *pos,
			     const unsigned char *phones);
int lex_delete_entry(cst_lexicon *l, const char *word, const char *pos);

cst_val *lex_lookup(const cst_lexicon *l, const char *word, const char *pos);
int in_lex(const cst_lexicon *l, const char *word, const char *pos);

CST_VAL_USER_TYPE_DCLS(lexicon,cst_lexicon)

#endif
