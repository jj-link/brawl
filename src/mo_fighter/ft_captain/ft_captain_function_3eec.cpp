#pragma force_active on
extern "C" {
void* fn_27_1A262C(void*, short);
void* fn_100_3F74(void*, short);
void* fn_100_3FB4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_3EEC(void* object, short deleting) {
    if (object != 0) {
        char* p = (char*)object;
        if (p + 0x24 != 0) {
            fn_27_1A262C(p + 0x34, -1);
            fn_100_3F74(p + 0x24, 0);
        }
        fn_100_3FB4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
