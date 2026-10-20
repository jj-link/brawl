#include <types.h>
#pragma force_active on

extern "C" void* fn_114_4150(void*, short);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_40C8(void* object, short arg2) {
    if (object) {
        fn_114_4150((char*)object + 0x8c, -1);
        void* p = (char*)object + 0x20;
        if (p)
            if (p)
                if (p)
                    fn_27_1A1E70(p, -1);
        fn_27_CD934(object, -1);
        if (arg2 > 0)
            __dl__FPv(object);
    }
    return object;
}
