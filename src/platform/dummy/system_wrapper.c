/**
 * @file system_wrapper.c
 * @brief System interface implementation for various system functions.
 *
 * Implements the system interface used by the Tuya SDK.
 * This ports the SDK to the system layer of the platform.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "system_interface.h"


void* system_malloc(size_t n)
{
    return malloc(n);
}

void* system_calloc(size_t n, size_t size)
{
    return calloc(n, size);
}

void  system_free(void *ptr)
{
    free(ptr);
}

uint32_t system_ticks(void)
{
    return 0;
}

uint32_t system_timestamp(void)
{
    return 0;
}

void system_sleep( uint32_t time_ms )
{
}

uint32_t system_random(void)
{
    return (uint32_t)rand();
}

#ifdef __cplusplus
}
#endif
