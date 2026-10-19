#pragma force_active on
extern "C" {
void* fn_91_6308(void*, short);
void* fn_91_6364(void*, short);
void* fn_91_63C0(void*, short);
void* fn_91_64A8(void*, short);
void* fn_91_2258(void*, short);
void* fn_91_6714(void*, short);
void* fn_91_6770(void*, short);
void* fn_91_67DC(void*, short);
void* fn_91_683C(void*, short);
void* fn_91_689C(void*, short);
void* fn_91_68F8(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_91_6984(void*, short);
void* fn_91_6A0C(void*, short);
void* fn_91_6A78(void*, short);
void* fn_91_6AF0(void*, short);
void* fn_91_1F00(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_91_6B30(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_7C00(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            if ((unsigned int)object + 0xcc != 0) {
                if ((unsigned int)object + 0xcc != 0) {
                    fn_91_6308(static_cast<unsigned char*>(object) + 0x130c, (short)-1);
                    fn_91_6364(static_cast<unsigned char*>(object) + 0x12f4, (short)-1);
                    fn_91_63C0(static_cast<unsigned char*>(object) + 0x1158, (short)-1);
                    fn_91_64A8(static_cast<unsigned char*>(object) + 0x10f8, (short)-1);
                    fn_91_2258(static_cast<unsigned char*>(object) + 0x10bc, (short)-1);
                    fn_91_6714(static_cast<unsigned char*>(object) + 0x10a4, (short)-1);
                    fn_91_6770(static_cast<unsigned char*>(object) + 0xf40, (short)-1);
                    fn_91_67DC(static_cast<unsigned char*>(object) + 0xed8, (short)-1);
                    fn_91_683C(static_cast<unsigned char*>(object) + 0xecc, (short)-1);
                    fn_91_689C(static_cast<unsigned char*>(object) + 0xea4, (short)-1);
                    fn_91_68F8(static_cast<unsigned char*>(object) + 0xe34, (short)-1);
                    if ((unsigned int)object + 0xde8 != 0)
                        fn_27_252D0(static_cast<unsigned char*>(object) + 0xdec, (short)-1);
                    if ((unsigned int)object + 0xbdc != 0) {
                        fn_27_13C90(static_cast<unsigned char*>(object) + 0xc78, (short)-1);
                        fn_27_21038(static_cast<unsigned char*>(object) + 0xc64, (short)-1);
                        fn_91_6984(static_cast<unsigned char*>(object) + 0xbdc, (short)-1);
                    }
                    fn_91_6A0C(static_cast<unsigned char*>(object) + 0x9fc, (short)-1);
                    fn_91_6A78(static_cast<unsigned char*>(object) + 0x9cc, (short)-1);
                    fn_91_6AF0(static_cast<unsigned char*>(object) + 0x9bc, (short)-1);
                    fn_91_1F00(static_cast<unsigned char*>(object) + 0x9a4, (short)-1);
                    __dt__16soModuleAccesserFv(static_cast<unsigned char*>(object) + 0x8c4, (short)-1);
                    fn_91_6B30(static_cast<unsigned char*>(object) + 0xcc, (short)-1);
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
