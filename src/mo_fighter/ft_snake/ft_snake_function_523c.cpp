#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void* fn_122_5438(void*, short);
void* fn_122_38FC(void*, short);
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_5494(void*, short);
void* fn_122_3BC4(void*, short);
void* fn_122_5754(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_57B0(void*, short);
void* fn_122_5844(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_449C(void*, short);
void* fn_122_593C(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4754(void*, short);
void* fn_122_5998(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_4978(void*, short);
void* fn_122_49E4(void*, short);
void* fn_122_5A1C(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_122_523C(void* object, short deleting) {
    char* p = static_cast<char*>(object);
    if (p) {
        if (p + 4) {
            short d = -1;
            fn_122_5438(p + 0x221c, d);
            fn_122_38FC(p + 0x21f4, static_cast<short>(0));
            if (p + 4) {
                fn_122_3958(p + 0x21b0, d);
                fn_27_1DBB60(p + 0x2178, d);
                if (p + 0xd0) {
                    fn_122_5494(p + 0x1bc8, d);
                    if (p + 0xd0) {
                        fn_122_3BC4(p + 0x1bac, d);
                        fn_122_5754(p + 0x1b6c, d);
                        fn_122_3C7C(p + 0x1b54, d);
                        fn_122_3D5C(p + 0x19b8, d);
                        fn_122_3DE8(p + 0x1958, d);
                        fn_122_57B0(p + 0x18a4, d);
                        fn_122_5844(p + 0x16dc, d);
                        fn_122_430C(p + 0x1638, d);
                        fn_122_4440(p + 0x1604, d);
                        fn_122_449C(p + 0x15e8, d);
                        fn_122_593C(p + 0x15b4, d);
                        fn_122_4558(p + 0x1450, d);
                        fn_122_45C4(p + 0x13e8, d);
                        fn_122_4624(p + 0x13dc, d);
                        fn_122_4754(p + 0x11dc, d);
                        fn_122_5998(p + 0x1010, d);
                        fn_122_4850(p + 0xfac, d);
                        fn_122_4978(p + 0xf00, d);
                        fn_122_49E4(p + 0xdec, d);
                        fn_122_5A1C(p + 0xbe0, d);
                        fn_122_4B58(p + 0xa00, d);
                        fn_122_4BC4(p + 0x9d0, d);
                        fn_122_4C7C(p + 0x9c0, d);
                        fn_122_4CBC(p + 0x9a8, d);
                        reinterpret_cast<soModuleAccesser*>(p + 0x8c8)
                            ->soModuleAccesser::~soModuleAccesser();
                        fn_122_4D18(p + 0xd0, d);
                    }
                }
                fn_27_1D81C8(p + 4, static_cast<short>(0));
            }
        }
        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
