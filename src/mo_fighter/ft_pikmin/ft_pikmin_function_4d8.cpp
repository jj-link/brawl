#include <new>
#pragma force_active on

extern "C" {
void fn_113_578(void*, short);
void fn_113_958(void*, short);
void fn_113_9F4(void*, short);
void fn_113_B80(void*, short);
void fn_27_125E20(void*, short);

void* fn_113_4D8(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_113_578(owner + 0x20000 - 0x3a4, memberDeleting);
        fn_113_958(owner + 0x20000 - 0x85c, memberDeleting);
        fn_113_9F4(owner + 0x20000 - 0x898, memberDeleting);
        fn_113_B80(owner + 0x194, memberDeleting);
        fn_27_125E20(owner, 0);
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
