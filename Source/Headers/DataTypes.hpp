#ifndef __GOLJ_DATATYPES_HPP__
#define __GOLJ_DATATYPES_HPP__

#include <stddef.h>
#include <stdint.h>

typedef signed char		GOL_SCHAR;
typedef unsigned char	GOL_UCHAR;
typedef int8_t			GOL_SINT8;
typedef uint8_t			GOL_UINT8;
typedef int16_t			GOL_SINT16;
typedef uint16_t		GOL_UINT16;
typedef int32_t			GOL_SINT32;
typedef uint32_t		GOL_UINT32;
typedef int64_t			GOL_SINT64;
typedef uint64_t		GOL_UINT64;
typedef float			GOL_FLOAT32;
typedef double			GOL_FLOAT64;
typedef size_t			GOL_MEMSIZE;

typedef GOL_UCHAR	GOL_BYTE;
typedef GOL_UINT32	GOL_BOOL;

const GOL_UINT32 GOL_TRUE	= 1;
const GOL_UINT32 GOL_FALSE	= 0;

const GOL_UINT32 GOL_OK		= 0x00000000;
const GOL_UINT32 GOL_FAIL	= 0xFFFFFFFF;

#define GOL_NULL nullptr

#endif // __GOLJ_DATATYPES_HPP__

