/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_SOURCE = 258,
     KW_DESTINATION = 259,
     KW_LOG = 260,
     KW_OPTIONS = 261,
     KW_FILTER = 262,
     KW_INTERNAL = 263,
     KW_FILE = 264,
     KW_PIPE = 265,
     KW_UNIX_STREAM = 266,
     KW_UNIX_DGRAM = 267,
     KW_UDP = 268,
     KW_TCP = 269,
     KW_USER = 270,
     KW_SPOOF_SOURCE = 271,
     KW_SO_RCVBUF = 272,
     KW_DOOR = 273,
     KW_SUN_STREAMS = 274,
     KW_PROGRAM = 275,
     KW_REMCTRL = 276,
     KW_FLAGS = 277,
     KW_CATCHALL = 278,
     KW_FALLBACK = 279,
     KW_FINAL = 280,
     KW_FSYNC = 281,
     KW_MARK_FREQ = 282,
     KW_SYNC_FREQ = 283,
     KW_STATS_FREQ = 284,
     KW_CHAIN_HOSTNAMES = 285,
     KW_KEEP_HOSTNAME = 286,
     KW_CHECK_HOSTNAME = 287,
     KW_BAD_HOSTNAME = 288,
     KW_LOG_FIFO_SIZE = 289,
     KW_LOG_MSG_SIZE = 290,
     KW_TIME_REOPEN = 291,
     KW_TIME_REAP = 292,
     KW_TIME_SLEEP = 293,
     KW_USE_TIME_RECVD = 294,
     KW_USE_DNS = 295,
     KW_USE_FQDN = 296,
     KW_GC_BUSY_THRESHOLD = 297,
     KW_GC_IDLE_THRESHOLD = 298,
     KW_CREATE_DIRS = 299,
     KW_SANITIZE_FILENAMES = 300,
     KW_DIR_OWNER = 301,
     KW_DIR_GROUP = 302,
     KW_DIR_PERM = 303,
     KW_TEMPLATE = 304,
     KW_TEMPLATE_ESCAPE = 305,
     KW_OWNER = 306,
     KW_GROUP = 307,
     KW_PERM = 308,
     KW_KEEP_ALIVE = 309,
     KW_TCP_KEEP_ALIVE = 310,
     KW_MAX_CONNECTIONS = 311,
     KW_LOCALIP = 312,
     KW_IP = 313,
     KW_LOCALPORT = 314,
     KW_PORT = 315,
     KW_DESTPORT = 316,
     KW_COMPRESS = 317,
     KW_MAC = 318,
     KW_AUTH = 319,
     KW_ENCRYPT = 320,
     KW_DNS_CACHE = 321,
     KW_DNS_CACHE_SIZE = 322,
     KW_DNS_CACHE_EXPIRE = 323,
     KW_DNS_CACHE_EXPIRE_FAILED = 324,
     KW_REMOVE_IF_OLDER = 325,
     KW_LOG_PREFIX = 326,
     KW_PAD_SIZE = 327,
     KW_FACILITY = 328,
     KW_LEVEL = 329,
     KW_NETMASK = 330,
     KW_HOST = 331,
     KW_MATCH = 332,
     KW_YES = 333,
     KW_NO = 334,
     KW_REQUIRED = 335,
     KW_ALLOW = 336,
     KW_DENY = 337,
     DOTDOT = 338,
     IDENTIFIER = 339,
     NUMBER = 340,
     STRING = 341,
     KW_OR = 342,
     KW_AND = 343,
     KW_NOT = 344
   };
#endif
/* Tokens.  */
#define KW_SOURCE 258
#define KW_DESTINATION 259
#define KW_LOG 260
#define KW_OPTIONS 261
#define KW_FILTER 262
#define KW_INTERNAL 263
#define KW_FILE 264
#define KW_PIPE 265
#define KW_UNIX_STREAM 266
#define KW_UNIX_DGRAM 267
#define KW_UDP 268
#define KW_TCP 269
#define KW_USER 270
#define KW_SPOOF_SOURCE 271
#define KW_SO_RCVBUF 272
#define KW_DOOR 273
#define KW_SUN_STREAMS 274
#define KW_PROGRAM 275
#define KW_REMCTRL 276
#define KW_FLAGS 277
#define KW_CATCHALL 278
#define KW_FALLBACK 279
#define KW_FINAL 280
#define KW_FSYNC 281
#define KW_MARK_FREQ 282
#define KW_SYNC_FREQ 283
#define KW_STATS_FREQ 284
#define KW_CHAIN_HOSTNAMES 285
#define KW_KEEP_HOSTNAME 286
#define KW_CHECK_HOSTNAME 287
#define KW_BAD_HOSTNAME 288
#define KW_LOG_FIFO_SIZE 289
#define KW_LOG_MSG_SIZE 290
#define KW_TIME_REOPEN 291
#define KW_TIME_REAP 292
#define KW_TIME_SLEEP 293
#define KW_USE_TIME_RECVD 294
#define KW_USE_DNS 295
#define KW_USE_FQDN 296
#define KW_GC_BUSY_THRESHOLD 297
#define KW_GC_IDLE_THRESHOLD 298
#define KW_CREATE_DIRS 299
#define KW_SANITIZE_FILENAMES 300
#define KW_DIR_OWNER 301
#define KW_DIR_GROUP 302
#define KW_DIR_PERM 303
#define KW_TEMPLATE 304
#define KW_TEMPLATE_ESCAPE 305
#define KW_OWNER 306
#define KW_GROUP 307
#define KW_PERM 308
#define KW_KEEP_ALIVE 309
#define KW_TCP_KEEP_ALIVE 310
#define KW_MAX_CONNECTIONS 311
#define KW_LOCALIP 312
#define KW_IP 313
#define KW_LOCALPORT 314
#define KW_PORT 315
#define KW_DESTPORT 316
#define KW_COMPRESS 317
#define KW_MAC 318
#define KW_AUTH 319
#define KW_ENCRYPT 320
#define KW_DNS_CACHE 321
#define KW_DNS_CACHE_SIZE 322
#define KW_DNS_CACHE_EXPIRE 323
#define KW_DNS_CACHE_EXPIRE_FAILED 324
#define KW_REMOVE_IF_OLDER 325
#define KW_LOG_PREFIX 326
#define KW_PAD_SIZE 327
#define KW_FACILITY 328
#define KW_LEVEL 329
#define KW_NETMASK 330
#define KW_HOST 331
#define KW_MATCH 332
#define KW_YES 333
#define KW_NO 334
#define KW_REQUIRED 335
#define KW_ALLOW 336
#define KW_DENY 337
#define DOTDOT 338
#define IDENTIFIER 339
#define NUMBER 340
#define STRING 341
#define KW_OR 342
#define KW_AND 343
#define KW_NOT 344




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 62 "cfg-grammar.y"
typedef union YYSTYPE {
	UINT32 num;
	char *cptr;
	void *ptr;
	struct filter_expr_node *node;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 223 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



