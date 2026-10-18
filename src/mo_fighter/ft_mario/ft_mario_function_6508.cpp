#pragma force_active on
extern "C" {
void* fn_27_1A241C(void*, short);
void* fn_91_5830(void*, short);
void* fn_91_1A14(void*, short);
void* fn_91_5760(void*, short);
void __dl__FPv(void*);

void* fn_91_6508(void* object, short deleting) {
    if (object != 0) {
        char* p = (char*)object;
        if (p + 0x30 != 0) {
            fn_27_1A241C(p + 0x40, -1);
            fn_91_5830(p + 0x30, 0);
        }
        if (object != 0) {
            fn_91_1A14(p + 0x20, 0);
            fn_91_5760(object, 0);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
