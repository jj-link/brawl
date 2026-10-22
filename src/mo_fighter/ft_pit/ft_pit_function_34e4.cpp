#pragma force_active on
extern "C" {
void* fn_112_3698(void*, short);
void* fn_112_36F4(void*, short);
void* fn_27_BED74(void*, short);
void* fn_112_2E88(void*, short);
void* fn_112_3750(void*, short);
void* fn_112_37DC(void*, short);
void* fn_112_38D8(void*, short);
void* fn_112_3934(void*, short);
void* fn_112_3990(void*, short);
void* fn_112_39FC(void*, short);
void* fn_112_3A5C(void*, short);
void* fn_112_3ABC(void*, short);
void* fn_112_3B18(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_112_3BE4(void*, short);
void* fn_112_3C40(void*, short);
void* fn_112_3D68(void*, short);
void* fn_112_3DD4(void*, short);
void* fn_112_3E8C(void*, short);
void* fn_112_3ECC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_112_3F28(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_112_34E4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            if ((unsigned int)object + 0xcc != 0) {
                if ((unsigned int)object + 0xcc != 0) {
                    fn_112_3698(static_cast<unsigned char*>(object) + 0x14e8, (short)-1);
                    fn_112_36F4(static_cast<unsigned char*>(object) + 0x14d0, (short)-1);
                    if ((unsigned int)object + 0x1378 != 0)
                        fn_27_BED74(static_cast<unsigned char*>(object) + 0x1378, (short)-1);
                    fn_112_2E88(static_cast<unsigned char*>(object) + 0x132c, (short)-1);
                    fn_112_3750(static_cast<unsigned char*>(object) + 0x1194, (short)-1);
                    fn_112_37DC(static_cast<unsigned char*>(object) + 0x1134, (short)-1);
                    fn_112_38D8(static_cast<unsigned char*>(object) + 0x10f8, (short)-1);
                    fn_112_3934(static_cast<unsigned char*>(object) + 0x10e0, (short)-1);
                    fn_112_3990(static_cast<unsigned char*>(object) + 0xf7c, (short)-1);
                    fn_112_39FC(static_cast<unsigned char*>(object) + 0xf14, (short)-1);
                    fn_112_3A5C(static_cast<unsigned char*>(object) + 0xf08, (short)-1);
                    fn_112_3ABC(static_cast<unsigned char*>(object) + 0xee0, (short)-1);
                    fn_112_3B18(static_cast<unsigned char*>(object) + 0xe70, (short)-1);
                    if ((unsigned int)object + 0xe24 != 0)
                        fn_27_252D0(static_cast<unsigned char*>(object) + 0xe28, (short)-1);
                    if ((unsigned int)object + 0xbdc != 0) {
                        fn_27_13C90(static_cast<unsigned char*>(object) + 0xcb4, (short)-1);
                        fn_27_21038(static_cast<unsigned char*>(object) + 0xca0, (short)-1);
                        fn_112_3BE4(static_cast<unsigned char*>(object) + 0xc64, (short)-1);
                        fn_112_3C40(static_cast<unsigned char*>(object) + 0xbdc, (short)-1);
                    }
                    fn_112_3D68(static_cast<unsigned char*>(object) + 0x9fc, (short)-1);
                    fn_112_3DD4(static_cast<unsigned char*>(object) + 0x9cc, (short)-1);
                    fn_112_3E8C(static_cast<unsigned char*>(object) + 0x9bc, (short)-1);
                    fn_112_3ECC(static_cast<unsigned char*>(object) + 0x9a4, (short)-1);
                    __dt__16soModuleAccesserFv(static_cast<unsigned char*>(object) + 0x8c4, (short)-1);
                    fn_112_3F28(static_cast<unsigned char*>(object) + 0xcc, (short)-1);
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
