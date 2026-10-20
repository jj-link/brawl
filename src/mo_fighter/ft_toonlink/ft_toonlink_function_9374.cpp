#include <new>
#pragma force_active on

extern "C" {
void* fn_121_929C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_121_85C4(void*, short);

void* fn_121_9374(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_121_929C(owner + 0x18690, memberDeleting);
        fn_27_C74E8(owner + 0x18680, memberDeleting);
        fn_121_85C4(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
