#pragma force_active on
extern "C" {
void* fn_93_7140(void*, short);
void* fn_93_63F0(void*, short);
void* fn_93_644C(void*, short);
void* fn_93_719C(void*, short);
void* fn_93_6564(void*, short);
void* fn_93_2240(void*, short);
void* fn_93_664C(void*, short);
void* fn_93_66A8(void*, short);
void* fn_93_7284(void*, short);
void* fn_93_6714(void*, short);
void* fn_93_72E4(void*, short);
void* fn_93_6774(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_19FFEC(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_93_6800(void*, short);
void* fn_93_6888(void*, short);
void* fn_93_68F4(void*, short);
void* fn_93_696C(void*, short);
void* fn_93_1F54(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_93_7340(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_93_79F0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            unsigned char* p = static_cast<unsigned char*>(object);
            if (p + 0xcc != 0) {
                if (p + 0xcc != 0) {
                    short d = -1;
                    fn_93_7140(p + 0x1498, d);
                    fn_93_63F0(p + 0x1480, d);
                    fn_93_644C(p + 0x1328, d);
                    fn_93_719C(p + 0x1190, d);
                    fn_93_6564(p + 0x1130, d);
                    fn_93_2240(p + 0x10f4, d);
                    fn_93_664C(p + 0x10dc, d);
                    fn_93_66A8(p + 0xf78, d);
                    fn_93_7284(p + 0xf10, d);
                    fn_93_6714(p + 0xf04, d);
                    fn_93_72E4(p + 0xedc, d);
                    fn_93_6774(p + 0xe6c, d);
                    if (p + 0xde8 != 0) {
                        fn_27_252D0(p + 0xe24, d);
                        if (p + 0xde8 != 0)
                            fn_27_19FFEC(p + 0xde8, d);
                    }
                    if (p + 0xbdc != 0) {
                        short e = -1;
                        fn_27_13C90(p + 0xc78, e);
                        fn_27_21038(p + 0xc64, e);
                        fn_93_6800(p + 0xbdc, e);
                    }
                    short f = -1;
                    fn_93_6888(p + 0x9fc, f);
                    fn_93_68F4(p + 0x9cc, f);
                    fn_93_696C(p + 0x9bc, f);
                    fn_93_1F54(p + 0x9a4, f);
                    __dt__16soModuleAccesserFv(p + 0x8c4, f);
                    fn_93_7340(p + 0xcc, f);
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
