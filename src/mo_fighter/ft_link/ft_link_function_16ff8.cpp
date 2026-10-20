#pragma force_active on
extern "C" {
void* fn_93_62F8(void*, short);
void* fn_93_62B8(void*, short);
void* fn_93_6394(void*, short);
void* fn_27_C7770(void*, short);
void* __dl__FPv(void*);
}

extern "C" void* fn_93_16FF8(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        char* members = (char*)object;
        fn_93_62F8(members + 0xDC, flag);
        fn_93_62B8(members + 0xC0, flag);
        fn_93_6394(members + 0x14, flag);
        if (object != 0) {
            fn_27_C7770(object, flag);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
