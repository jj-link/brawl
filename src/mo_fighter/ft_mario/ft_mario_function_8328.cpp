#pragma force_active on
extern "C" {
void* fn_27_CB048(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void* fn_27_197EF4(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_8328(void* object, short deleting) {
    if (object != 0) {
        fn_27_CB048(static_cast<unsigned char*>(object) + 0x220, static_cast<short>(-1));
        fn_27_199214(static_cast<unsigned char*>(object) + 0x94, static_cast<short>(-1));
        fn_27_A78FC(static_cast<unsigned char*>(object) + 0x78, static_cast<short>(-1));
        fn_27_14E050(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        if (object != 0) fn_27_197EF4(object, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
