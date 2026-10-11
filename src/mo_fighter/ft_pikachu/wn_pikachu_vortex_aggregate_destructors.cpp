#include <so/so_module_accesser.h>

extern "C" {
void* fn_98_3F10(void*, short);
void* fn_98_418C(void*, short);
void* fn_98_4210(void*, short);
void* fn_98_1B1C0(void*, short);
void* fn_98_4270(void*, short);
void* fn_98_4398(void*, short);
void* fn_27_C74E8(void*, short);

// Embedded members use the nondeleting destructor flag; only the complete
// object's positive signed-short flag releases its allocation.
void* fn_98_1B0C4(void* object, int deleting) {
    if (object) {
        fn_98_3F10(static_cast<char*>(object) + 0x3c, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}

void* fn_98_1B124(void* object, int deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_418C(static_cast<char*>(object) + 0x118, memberDeleting);
        fn_98_4210(static_cast<char*>(object) + 0x104, memberDeleting);
        fn_98_1B1C0(static_cast<char*>(object) + 0xec, memberDeleting);
        fn_98_4270(static_cast<char*>(object) + 0x48, memberDeleting);
        fn_98_4398(static_cast<char*>(object) + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
}
