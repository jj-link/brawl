#include <new>
#pragma force_active on

extern "C" {
void* fn_110_2104(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_110_1E4A0(void*, short);

void* fn_110_1E41C(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_110_2104(owner + 0x94A0, memberDeleting);
        fn_27_C74E8(owner + 0x9490, memberDeleting);
        fn_110_1E4A0(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
