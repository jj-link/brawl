#pragma force_active on
extern "C" {
void* fn_27_1A262C(void*, short);
void* fn_114_4278(void*, short);
void* fn_114_42B8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_114_41F0(void* object, short deleting) {
    if (object != 0) {
        char* p = (char*)object;
        if (p + 0x24 != 0) {
            fn_27_1A262C(p + 0x34, -1);
            fn_114_4278(p + 0x24, 0);
        }
        fn_114_42B8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
