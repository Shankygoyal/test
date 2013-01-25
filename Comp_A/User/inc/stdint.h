/* Copyright (C) ARM Ltd., 1999 */
/* All rights reserved */

/*
 * RCS $Revision: 137748 $
 * Checkin $Date: 2008-09-11 17:34:24 +0100 (Thu, 11 Sep 2008) $
 * Revising $Author: agrant $
 */

#ifndef __stdint_h
#define __stdint_h
#ifdef __cplusplus
 extern "C" {
#endif 
/*
 * 'signed' is redundant below, except for 'signed char' and if
 * the typedef is used to declare a bitfield.
 * '__int64' is used instead of 'long long' so that this header
 * can be used in --strict mode.
 */

    /* 7.18.1.1 */

    /* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
    /* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           long int uint32_t;

#ifdef __cplusplus
}
#endif

#endif /* __stdint_h */

/* end of stdint.h */


