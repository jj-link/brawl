#pragma force_active on
extern "C" {
void* fn_125_220C(void*, short);
void* fn_125_22A8(void*, short);
void* fn_125_22E8(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_27E0(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_125_220C(members + 0xDC, flag);
        fn_125_22A8(members + 0xC0, flag);
        fn_125_22E8(members + 0x14, flag);
        if (object != 0) {
            fn_27_C7770(object, flag);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
