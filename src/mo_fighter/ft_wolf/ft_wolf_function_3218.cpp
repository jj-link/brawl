#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_125_32A0(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_125_3218(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x14CA0, (short)-1);
        fn_125_32A0(static_cast<unsigned char*>(object) + 0x7c, (short)-1);
        fn_27_19F4C4(static_cast<unsigned char*>(object) + 0x20, (short)-1);
        fn_27_1A55B0(object, (short)-1);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
