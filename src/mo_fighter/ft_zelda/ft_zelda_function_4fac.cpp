#pragma force_active on
extern "C" {
void* fn_104_38E0(void*, short);
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_22AC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_104_50D8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_104_4FAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_104_38E0(p + 0x4b0, d);
        if (p + 0x384 != 0) {
            fn_104_21D0(p + 0x460, d);
            fn_104_226C(p + 0x444, d);
            fn_104_22AC(p + 0x398, d);
            if (p + 0x384 != 0)
                fn_27_C7770(p + 0x384, d);
        }
        if (p + 0x258 != 0) {
            short e = -1;
            fn_104_21D0(p + 0x334, e);
            fn_104_226C(p + 0x318, e);
            fn_104_22AC(p + 0x26c, e);
            if (p + 0x258 != 0)
                fn_27_C7770(p + 0x258, e);
        }
        if (p + 0x12c != 0) {
            short e = -1;
            fn_104_21D0(p + 0x208, e);
            fn_104_226C(p + 0x1ec, e);
            fn_104_22AC(p + 0x140, e);
            if (p + 0x12c != 0)
                fn_27_C7770(p + 0x12c, e);
        }
        fn_104_50D8(object, (short)-1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}