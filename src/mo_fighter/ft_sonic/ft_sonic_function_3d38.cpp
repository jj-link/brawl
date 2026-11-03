#pragma force_active on
extern "C" {
void* fn_123_3E1C(void*, short);
void* fn_123_3EA0(void*, short);
void* fn_123_3F00(void*, short);
void* fn_123_3BFC(void*, short);
void* fn_27_1A4778(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_123_3D38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_123_3E1C(p + 0x11c, d);
        fn_123_3EA0(p + 0x108, d);
        if (p + 0xec != 0) {
            fn_27_1A4778(p + 0xec, d);
        }
        if (p + 0x48 != 0) {
            fn_123_3F00(p + 0xd4, d);
            if (p + 0x68 != 0) {
                if (p + 0x68 != 0) {
                    if (p + 0x68 != 0) {
                        fn_27_1A1E70(p + 0x68, d);
                    }
                }
            }
            fn_27_CD934(p + 0x48, d);
        }
        if (p + 0x10 != 0) {
            fn_123_3BFC(p + 0x24, d);
        }
        fn_27_C74E8(object, d);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
}