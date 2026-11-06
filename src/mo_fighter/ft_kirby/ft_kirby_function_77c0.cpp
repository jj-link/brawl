#include <so/so_module_accesser.h>
#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_96_7A08(void*, short);
void* fn_96_7A74(void*, short);
void* fn_96_7B00(void*, short);
void* fn_96_7B8C(void*, short);
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_4CE8(void*, short);
void* fn_96_4C88(void*, short);
void* fn_27_1A4778(void*, short);
void* fn_96_7D5C(void*, short);
void* fn_96_4E2C(void*, short);
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
void* fn_96_7EA0(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* fn_96_7F18(void*, short);
void* fn_27_1D81C8(void*, short);
}
extern "C" void* fn_96_77C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (object != 0) {
            if (p + 0xcc != 0) {
                if (p + 0x162c != 0) {
                    short d = -1;
                    fn_96_7A08(p + 0x1adc, d);
                    fn_96_7A74(p + 0x19b0, d);
                    fn_96_7B00(p + 0x1884, d);
                    fn_96_7B8C(p + 0x1758, d);
                    if (p + 0x162c != 0) {
                        fn_96_6B10(p + 0x1708, d);
                        fn_96_6AD0(p + 0x16ec, d);
                        fn_96_6BAC(p + 0x1640, d);
                        if (p + 0x162c != 0) fn_27_C7770(p + 0x162c, d);
                    }
                }
                if (p + 0xcc != 0) {
                    short d = -1;
                    fn_96_7C18(p + 0x15e8, d);
                    fn_96_6C08(p + 0x15d0, d);
                    fn_96_7C74(p + 0x1434, d);
                    fn_96_6D1C(p + 0x13d4, d);
                    if (p + 0x1200 != 0) {
                        fn_96_4CE8(p + 0x1324, d);
                        fn_96_4C88(p + 0x1310, d);
                        if (p + 0x12f4 != 0) fn_27_1A4778(p + 0x12f4, d);
                        short e = -1;
                        fn_96_7D5C(p + 0x1250, e);
                        if (p + 0x1210 != 0) fn_96_4E2C(p + 0x122c, e);
                        fn_27_C74E8(p + 0x1200, (short)-1);
                    }
                    short f = -1;
                    fn_96_6D7C(p + 0x115c, f);
                    fn_96_27B8(p + 0x1128, f);
                    fn_96_6E04(p + 0x1110, f);
                    fn_96_6E60(p + 0xfac, f);
                    fn_96_7DE4(p + 0xf44, f);
                    fn_96_6ECC(p + 0xf38, f);
                    fn_96_7E44(p + 0xf10, f);
                    fn_96_6F2C(p + 0xea0, f);
                    fn_96_24BC(p + 0xde8, f);
                    fn_96_7EA0(p + 0xbdc, f);
                    fn_96_7040(p + 0x9fc, f);
                    fn_96_70AC(p + 0x9cc, f);
                    fn_96_7124(p + 0x9bc, f);
                    fn_96_2460(p + 0x9a4, f);
                    reinterpret_cast<soModuleAccesser*>(p + 0x8c4)->soModuleAccesser::~soModuleAccesser();
                    fn_96_7F18(p + 0xcc, f);
                }
            }
            fn_27_1D81C8(object, (short)0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
