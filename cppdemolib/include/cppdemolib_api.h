#ifndef CPPDEMOLIB_API_H
#define CPPDEMOLIB_API_H

#include "CoreExport.h"

extern "C" {

typedef struct {
    uint32_t major;
    uint32_t minor;
    uint32_t patch;
} demolib_version_struct;


CPPDEMOLIB_EXPORT demolib_version_struct demolib_get_version();

CPPDEMOLIB_EXPORT int add(int a, int b);

};


#endif
