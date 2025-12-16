#ifndef __khrplatform_h_
#define __khrplatform_h_

#ifdef __cplusplus
extern "C" {
#endif

typedef signed char khronos_int8_t;
typedef unsigned char khronos_uint8_t;
typedef signed short int khronos_int16_t;
typedef unsigned short int khronos_uint16_t;
typedef signed int khronos_int32_t;
typedef unsigned int khronos_uint32_t;
typedef signed long long int khronos_int64_t;
typedef unsigned long long int khronos_uint64_t;
typedef signed long khronos_intptr_t;
typedef unsigned long khronos_uintptr_t;
typedef signed long khronos_ssize_t;
typedef unsigned long khronos_usize_t;
typedef float khronos_float_t;
typedef double khronos_double_t;
typedef khronos_uint32_t khronos_utime_nanoseconds_t;
typedef khronos_int64_t khronos_stime_nanoseconds_t;

typedef enum {
    KHRONOS_FALSE = 0,
    KHRONOS_TRUE = 1
} khronos_boolean_enum_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
