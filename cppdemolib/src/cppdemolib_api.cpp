
#include <iostream>
#include <fmt/format.h>
#include "cppdemolib_api.h"


demolib_version_struct demolib_get_version(){
    return demolib_version_struct{1, 2, 3};
}


int add(int a, int b) {
    return a + b;
}
