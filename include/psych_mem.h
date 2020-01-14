#ifndef PSYCH_MEM_H
#define PSYCH_MEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#if defined(UINT_MAX) && UINT_MAX == 0xffffffff
#  define PSYCH_CCHECK_INT_32BIT
#else // defined(UINT_MAX) && UINT_MAX == 0xffffffff
#  if defined(UINT_MAX) && UINT_MAX == 0xffff 
#    define PSYCH_CCHECK_INT_16BIT
#  endif // defined(UINT_MAX) && UINT_MAX == 0xffff
#endif // !defined(UINT_MAX) && UINT_MAX == 0xffffffff

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#else
#  include <stdint.h>
#endif


#ifdef PSYCH_MEM_DEBUG
#  define _Psych_alloc(ptr, size) \
                     (ptr) = calloc(1, size); \
                     printf("Psych DEBUG: size %lu (Alloc) -> %p\n", (unsigned long)size, ptr)
#else // !PSYCH_MEM_DEBUG
#  define _Psych_alloc(ptr, size) (ptr) = calloc(1, size)
#endif

#ifdef PSYCH_MEM_DEBUG
#  define _Psych_malloc(ptr, size) \
                     (ptr) = malloc(size); \
                     printf("Psych DEBUG: size %lu (Malloc) -> %p\n", (unsigned long)size, ptr)
#else // !PSYCH_MEM_DEBUG
#  define _Psych_malloc(ptr, size) (ptr) = malloc(size)
#endif

#ifdef PSYCH_MEM_DEBUG
#  define _Psych_realloc(new_ptr, old_ptr, new_size) \
                     (new_ptr) = (realloc((old_ptr), (new_size))); \
                     printf("Psych DEBUG: size %lu (Realloc) %p -> %p\n", (unsigned long)new_size, old_ptr, new_ptr)
#else // !PSYCH_MEM_DEBUG
#  define _Psych_realloc(new_ptr, old_ptr, new_size) (new_ptr) = (realloc((old_ptr), (new_size)))
#endif                     



#ifdef PSYCH_MEM_DEBUG
#  define _Psych_free(ptr) \
                     printf("Psych DEBUG: (Free) -> %p\n", ptr); \
                     free(ptr)
#else // !PSYCH_MEM_DEBUG
#  define _Psych_free(ptr) free(ptr)
#endif

#ifndef PSYCH_ASSERT_EXIT_CODE
#define PSYCH_ASSERT_EXIT_CODE 33
#endif            

#ifndef _MSC_VER
#   define _Psych_assert(exp) if (!(exp)) { \
                     fprintf(stderr, "FATAL: exp '%s' asserts at line: %u, file:%s\n", \
                     #exp, \
                     	(unsigned)__LINE__, __FILE__);  \
                     exit(PSYCH_ASSERT_EXIT_CODE); \
                      }
#else // !_MSC_VER
#   define _Psych_assert(exp) if (!(exp) && fprintf(stderr, "FATAL: file:%s, line:%u\n", \
                                       __FILE__, (unsigned)__LINE__) > 0) \
                                      assert(exp)
#endif // MSC_VER
                     
#endif // PSYCH_MEM_H