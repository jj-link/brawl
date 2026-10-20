#include <new>
#pragma force_active on

extern "C" {
void* fn_98_42F8(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_4270(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_42F8(object + 0x8c, memberDeleting);
        char* m = object + 0x20;
        if (m)
            if (m)
                if (m)
                    fn_27_1A1E70(m, memberDeleting);
        fn_27_CD934(object, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
