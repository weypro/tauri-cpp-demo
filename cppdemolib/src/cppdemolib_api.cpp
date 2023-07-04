
#include <iostream>
#include <fmt/format.h>
#include "cppdemolib_api.h"


//std::string version;

const char* str="1.2.3";

demolib_version_struct demolib_get_version() {
    return demolib_version_struct{1, 2, 3};
}

const char *demolib_get_version_str() {
    return str;
}

int add(int a, int b) {
    return a + b;
}
