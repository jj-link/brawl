#include <new>
#pragma force_active on

extern "C" {
void* fn_119_1A30(void*, short);
void* fn_119_1E10(void*, short);
void* fn_119_1EAC(void*, short);
void* fn_119_1FE4(void*, short);
void* fn_27_125E20(void*, short);

void* fn_119_1990(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_119_1A30((char*)object + 0xAAC0, memberDeleting);
        fn_119_1E10((char*)object + 0xA608, memberDeleting);
        fn_119_1EAC((char*)object + 0xA5CC, memberDeleting);
        fn_119_1FE4((char*)object + 0x194, memberDeleting);
        fn_27_125E20(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
