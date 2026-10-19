#include <new>
#pragma force_active on

extern "C" {
void fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_6888(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_614C4(static_cast<char*>(object) + 0xAC, memberDeleting);
        if (object) fn_27_D3080(object, memberDeleting);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
