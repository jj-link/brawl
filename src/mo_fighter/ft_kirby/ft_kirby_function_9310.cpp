#pragma force_active on
extern "C" {
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_6C64(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_4CE8(void*, short);
void* fn_96_4C88(void*, short);
void* fn_27_1A301C(void*, short);
void* fn_96_7D5C(void*, short);
void* fn_96_8C1C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_6E04(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_24BC(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_96_6FB8(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_96_7F18(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_96_9310(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            unsigned char* p = static_cast<unsigned char*>(object);
            if (p + 0xcc != 0) {
                if (p + 0x1770 != 0) {
                    if (p + 0x1770 != 0) {
                        short d = -1;
                        fn_96_6B10(p + 0x184c, d);
                        fn_96_6AD0(p + 0x1830, d);
                        fn_96_6BAC(p + 0x1784, d);
                        if (p + 0x1770 != 0)
                            fn_27_C7770(p + 0x1770, d);
                    }
                }
                if (p + 0xcc != 0) {
                    short e = -1;
                    fn_96_7C18(p + 0x172c, e);
                    fn_96_6C08(p + 0x1714, e);
                    fn_96_6C64(p + 0x15bc, e);
                    fn_96_7C74(p + 0x1424, e);
                    fn_96_6D1C(p + 0x13c4, e);
                    if (p + 0x1200 != 0) {
                        fn_96_4CE8(p + 0x1314, e);
                        fn_96_4C88(p + 0x1300, e);
                        if (p + 0x12ec != 0)
                            fn_27_1A301C(p + 0x12ec, e);
                        short f = -1;
                        fn_96_7D5C(p + 0x1248, f);
                        fn_96_8C1C(p + 0x1210, f);
                        fn_27_C74E8(p + 0x1200, f);
                    }
                    short g = -1;
                    fn_96_6D7C(p + 0x115c, g);
                    fn_96_27B8(p + 0x1128, g);
                    fn_96_6E04(p + 0x1110, g);
                    fn_96_6E60(p + 0xfac, g);
                    fn_96_7DE4(p + 0xf44, g);
                    fn_96_6ECC(p + 0xf38, g);
                    fn_96_7E44(p + 0xf10, g);
                    fn_96_6F2C(p + 0xea0, g);
                    fn_96_24BC(p + 0xde8, g);
                    if (p + 0xbdc != 0) {
                        short h = -1;
                        fn_27_13C90(p + 0xc78, h);
                        fn_27_21038(p + 0xc64, h);
                        fn_96_6FB8(p + 0xbdc, h);
                    }
                    short k = -1;
                    fn_96_7040(p + 0x9fc, k);
                    fn_96_70AC(p + 0x9cc, k);
                    fn_96_7124(p + 0x9bc, k);
                    fn_96_2460(p + 0x9a4, k);
                    __dt__16soModuleAccesserFv(p + 0x8c4, k);
                    fn_96_7F18(p + 0xcc, k);
                }
            }
            fn_27_1D81C8(object, (short)0);
        }
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
