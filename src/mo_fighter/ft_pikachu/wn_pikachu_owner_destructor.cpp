#include <new>

extern "C" {
void* fn_98_38F0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_98_17140(void*, short);
void* fn_27_1D81C8(void*, short);

void* fn_98_170B0(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_98_38F0(owner + 0xa5b8, memberDeleting);
        fn_27_1DBB60(owner + 0xa580, memberDeleting);
        fn_98_17140(owner + 0xcc, memberDeleting);
        fn_27_1D81C8(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
