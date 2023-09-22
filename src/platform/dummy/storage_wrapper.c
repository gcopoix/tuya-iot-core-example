/**
 * @file storage_wrapper.c
 * @brief Storage interface implementation for storing and reading data.
 *
 * Implements the storage interface used by the Tuya SDK to read and store data/settings.
 * This ports the SDK to the storage layer of the platform.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "log.h"
#include "tuya_error_code.h"
#include "storage_interface.h"
#include "system_interface.h"


int local_storage_set(const char* key, const uint8_t* buffer, size_t length)
{
    return OPRT_NOT_SUPPORTED;
}

int local_storage_get(const char* key, uint8_t* buffer, size_t* length)
{
    return OPRT_NOT_SUPPORTED;
}

int local_storage_del(const char* key)
{
    return OPRT_NOT_SUPPORTED;
}

#ifdef __cplusplus
}
#endif
