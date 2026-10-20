#include <new>
#pragma force_active on

extern "C" {
void* fn_104_17384(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_104_179B0(void*, short);
}

extern "C" {
void* fn_104_17300(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_104_17384(owner + 0x1E258, memberDeleting);
        fn_27_C74E8(owner + 0x1E248, memberDeleting);
        fn_104_179B0(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
