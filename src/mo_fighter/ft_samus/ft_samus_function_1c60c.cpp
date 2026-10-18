#pragma force_active on
void operator delete(void*);

extern "C" void* fn_94_1475C(void*, short);
extern "C" void* fn_94_147B8(void*, short);
extern "C" void* fn_94_14814(void*, short);
extern "C" void* fn_94_1C78C(void*, short);
extern "C" void* fn_94_14870(void*, short);
extern "C" void* fn_94_1C7EC(void*, short);
extern "C" void* fn_94_1C84C(void*, short);
extern "C" void* fn_94_149E4(void*, short);
extern "C" void* fn_94_4B58(void*, short);
extern "C" void* fn_94_15540(void*, short);
extern "C" void* fn_94_14A6C(void*, short);
extern "C" void* fn_94_14AD8(void*, short);
extern "C" void* fn_94_14B38(void*, short);
extern "C" void* fn_94_14B98(void*, short);
extern "C" void* fn_94_1C9A4(void*, short);
extern "C" void* fn_94_14BF4(void*, short);
extern "C" void* fn_94_4BF4(void*, short);
extern "C" void* fn_94_4C50(void*, short);
extern "C" void* fn_94_1CA84(void*, short);
extern "C" void* fn_94_14C80(void*, short);
extern "C" void* fn_94_14CEC(void*, short);
extern "C" void* fn_94_14D64(void*, short);
extern "C" void* fn_94_4D60(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_94_1CBE8(void*, short);

extern "C" void* fn_94_1C60C(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_94_1475C(p + 0x18D4, -1);
        fn_94_147B8(p + 0x1894, -1);
        fn_94_14814(p + 0x187C, -1);
        fn_94_1C78C(p + 0x1828, -1);
        fn_94_14870(p + 0x1694, -1);
        fn_94_1C7EC(p + 0x160C, -1);
        fn_94_1C84C(p + 0x1464, -1);
        fn_94_149E4(p + 0x13C0, -1);
        fn_94_4B58(p + 0x138C, -1);
        fn_94_15540(p + 0x1374, -1);
        fn_94_14A6C(p + 0x1210, -1);
        fn_94_14AD8(p + 0x11A8, -1);
        fn_94_14B38(p + 0x119C, -1);
        fn_94_14B98(p + 0x1174, -1);
        fn_94_1C9A4(p + 0xDF4, -1);
        fn_94_14BF4(p + 0xD90, -1);
        fn_94_4BF4(p + 0xD54, -1);
        fn_94_4C50(p + 0xC9C, -1);
        fn_94_1CA84(p + 0xB10, -1);
        fn_94_14C80(p + 0x930, -1);
        fn_94_14CEC(p + 0x900, -1);
        fn_94_14D64(p + 0x8F0, -1);
        fn_94_4D60(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_94_1CBE8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
