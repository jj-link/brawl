#include <new>
#pragma force_active on

extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_98_4048(void*, short);
extern "C" void* fn_98_1EF4(void*, short);
extern "C" void* fn_98_4088(void*, short);

extern "C" void* fn_98_3FAC(void* object, short deleting) {
    if (object) {
        char* members = static_cast<char*>(object);
        if (members + 0x30) {
            fn_27_1A241C(members + 0x40, -1);
            fn_98_4048(members + 0x30, 0);
        }
        if (object) {
            fn_98_1EF4(members + 0x20, 0);
            fn_98_4088(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
