#include <types.h>

extern "C" int fn_111_C8E4() {
    return 1;
}

extern "C" void fn_111_C8EC() {
}

extern "C" int fn_111_C8F0() {
    return 0;
}

extern "C" void fn_111_C8F8() {
}

extern "C" int fn_111_C8FC() {
    return 0;
}

extern "C" void fn_111_C904() {
}

extern "C" void fn_111_C908() {
}

extern "C" void fn_111_C90C() {
}

extern "C" void fn_111_C910() {
}

extern "C" void fn_111_C914() {
}

extern "C" void fn_111_C918() {
}

extern "C" void* fn_111_C91C(void* object, s16 deleting) {
    if (object && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void fn_111_C95C() {
}
