#include <so/so_module_accesser.h>
#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_105_2B80(void*, short);
void* fn_105_2BDC(void*, short);
void* fn_105_2C38(void*, short);
void* fn_105_2C94(void*, short);
void* fn_105_2CF0(void*, short);
void* fn_105_2D4C(void*, short);
void* fn_105_2E28(void*, short);
void* fn_105_2E84(void*, short);
void* fn_105_2EE0(void*, short);
void* fn_105_2F54(void*, short);
void* fn_105_2FEC(void*, short);
void* fn_105_3048(void*, short);
void* fn_105_3198(void*, short);
void* fn_105_634C(void*, short);
void* fn_105_63AC(void*, short);
void* fn_105_6424(void*, short);
void* fn_105_6F94(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_7070(void*, short);
void* fn_105_70E4(void*, short);
void* fn_105_71C0(void*, short);
void* fn_105_721C(void*, short);
void* fn_105_7288(void*, short);
void* fn_105_7334(void*, short);
void* fn_105_73A8(void*, short);
void* fn_105_7404(void*, short);
void* fn_105_7460(void*, short);
void* fn_105_74BC(void*, short);
void* fn_105_7518(void*, short);
void* fn_105_758C(void*, short);
void* fn_105_75F8(void*, short);
void* fn_105_7688(void*, short);
void* fn_105_7718(void*, short);
void* fn_105_779C(void*, short);
void* fn_105_7820(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_5370(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_7954(void*, short);
void* fn_105_7D18(void*, short);
void* fn_105_7DEC(void*, short);
void* fn_105_7EB8(void*, short);
void* fn_105_4958(void*, short);
void* fn_105_7F14(void*, short);
}
extern "C" void* fn_105_28E0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_105_2B80(storage + 0x1DF8C, destroy);
        fn_105_2BDC(storage + 0x1DF50, destroy);
        fn_105_2C38(storage + 0x1DEE8, destroy);
        fn_105_2C94(storage + 0x1DE9C, destroy);
        fn_105_2CF0(storage + 0x1DD48, destroy);
        fn_105_2D4C(storage + 0x1DC38, destroy);
        fn_105_2E28(storage + 0x1DBF0, destroy);
        fn_105_2E84(storage + 0x1DB70, destroy);
        fn_105_2EE0(storage + 0x1DAAC, destroy);
        fn_105_2F54(storage + 0x1D738, destroy);
        fn_105_2FEC(storage + 0x1D708, destroy);
        fn_105_3048(storage + 0x1D564, destroy);
        fn_105_3198(storage + 0x5A98, destroy);
        fn_105_634C(storage + 0x58D8, destroy);
        fn_105_63AC(storage + 0x55D0, destroy);
        fn_105_6424(storage + 0x474C, destroy);
        fn_105_6F94(storage + 0x4658, destroy);
        fn_105_4294(storage + 0x4624, destroy);
        fn_105_7070(storage + 0x45B0, destroy);
        fn_105_70E4(storage + 0x3E8C, destroy);
        fn_105_71C0(storage + 0x3E5C, destroy);
        fn_105_721C(storage + 0x3C90, destroy);
        fn_105_7288(storage + 0x3C20, destroy);
        fn_105_7334(storage + 0x3B88, destroy);
        fn_105_73A8(storage + 0x3B50, destroy);
        fn_105_7404(storage + 0x3B2C, destroy);
        fn_105_7460(storage + 0x3AF8, destroy);
        fn_105_74BC(storage + 0x3A94, destroy);
        fn_105_7518(storage + 0x38E4, destroy);
        fn_105_758C(storage + 0x3680, destroy);
        fn_105_75F8(storage + 0x2C14, destroy);
        fn_105_7688(storage + 0x29FC, destroy);
        fn_105_7718(storage + 0x20A0, destroy);
        fn_105_779C(storage + 0x19E4, destroy);
        fn_105_7820(storage + 0x1970, destroy);
        fn_105_4624(storage + 0x1934, destroy);
        fn_105_5370(storage + 0x188C, destroy);
        fn_105_4680(storage + 0x17D8, destroy);
        fn_105_7954(storage + 0x1444, destroy);
        fn_105_7D18(storage + 0x1184, destroy);
        fn_105_7DEC(storage + 0x115C, destroy);
        fn_105_7EB8(storage + 0xAC8, destroy);
        fn_105_4958(storage + 0xAB0, destroy);
        reinterpret_cast<soModuleAccesser*>(storage + 0x9D0)->soModuleAccesser::~soModuleAccesser();
        fn_105_7F14(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
