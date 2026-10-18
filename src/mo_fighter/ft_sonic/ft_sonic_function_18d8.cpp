#include <new>
#pragma force_active on

extern "C" {
void* fn_123_1978(char*, short);
void* fn_123_1DB0(char*, short);
void* fn_123_1E4C(char*, short);
void* fn_123_1F84(char*, short);
void fn_27_125E20(char*, short);

void* fn_123_18D8(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_123_1978(owner + 0xD51C, memberDeleting);
        fn_123_1DB0(owner + 0xD064, memberDeleting);
        fn_123_1E4C(owner + 0xD028, memberDeleting);
        fn_123_1F84(owner + 0x194, memberDeleting);
        fn_27_125E20(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
