#pragma force_active on
extern "C" {
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_4FAC(void*, short);
void* fn_104_3AF0(void*, short);
void* fn_104_3B4C(void*, short);
void* fn_104_3BA8(void*, short);
void* fn_104_3C04(void*, short);
void* fn_104_3D50(void*, short);
void* fn_104_3E4C(void*, short);
void* fn_104_3F88(void*, short);
void* fn_104_400C(void*, short);
void* fn_104_406C(void*, short);
void* fn_104_3DB0(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_104_5164(void*, short);
void* fn_104_4194(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_4324(void*, short);
void* fn_104_4380(void*, short);
void* fn_104_43EC(void*, short);
void* fn_104_444C(void*, short);
void* fn_104_44AC(void*, short);
void* fn_104_4508(void*, short);
void* fn_104_458C(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_4720(void*, short);
void* fn_104_51C0(void*, short);
void* fn_104_4894(void*, short);
void* fn_104_4900(void*, short);
void* fn_104_49B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_104_4A54(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dl__FPv(void*);
}

#pragma dont_inline on
extern "C" void* fn_104_4D90(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            unsigned char* p = static_cast<unsigned char*>(object);
            short d = -1;
            fn_104_3844(p + 0x1ed0, d);
            fn_27_1DBB60(p + 0x1e98, d);
            if (p + 0xcc != 0) {
                fn_104_4FAC(p + 0x18e8, d);
                if (p + 0xcc != 0) {
                    fn_104_3AF0(p + 0x18cc, d);
                    fn_104_3B4C(p + 0x188c, d);
                    fn_104_3BA8(p + 0x1874, d);
                    fn_104_3C04(p + 0x16d8, d);
                    fn_104_3D50(p + 0x1678, d);
                    fn_104_3E4C(p + 0x15c4, d);
                    if (p + 0x1400 != 0) {
                        fn_104_3F88(p + 0x1514, d);
                        fn_104_400C(p + 0x1500, d);
                        fn_104_5164(p + 0x14f0, d);
                        fn_104_406C(p + 0x144c, d);
                        if (p + 0x1410 != 0)
                            fn_104_3DB0(p + 0x1428, d);
                        fn_27_C74E8(p + 0x1400, d);
                    }
                    fn_104_4194(p + 0x135c, d);
                    fn_104_42C8(p + 0x1328, d);
                    fn_104_4324(p + 0x1310, d);
                    fn_104_4380(p + 0x11ac, d);
                    fn_104_43EC(p + 0x1144, d);
                    fn_104_444C(p + 0x1138, d);
                    fn_104_44AC(p + 0x1110, d);
                    fn_104_4508(p + 0xf40, d);
                    fn_104_458C(p + 0xedc, d);
                    fn_104_4658(p + 0xea0, d);
                    fn_104_4720(p + 0xde8, d);
                    fn_104_51C0(p + 0xbdc, d);
                    fn_104_4894(p + 0x9fc, d);
                    fn_104_4900(p + 0x9cc, d);
                    fn_104_49B8(p + 0x9bc, d);
                    fn_104_49F8(p + 0x9a4, d);
                    __dt__16soModuleAccesserFv(p + 0x8c4, d);
                    fn_104_4A54(p + 0xcc, d);
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
