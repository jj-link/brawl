#pragma force_active on
extern "C" void* fn_94_147B8(void*, short);
extern "C" void* fn_94_14814(void*, short);
extern "C" void* fn_94_14870(void*, short);
extern "C" void* fn_94_15434(void*, short);
extern "C" void* fn_94_1F864(void*, short);
extern "C" void* fn_94_1F93C(void*, short);
extern "C" void* fn_94_149E4(void*, short);
extern "C" void* fn_94_4B58(void*, short);
extern "C" void* fn_94_15540(void*, short);
extern "C" void* fn_94_14A6C(void*, short);
extern "C" void* fn_94_14AD8(void*, short);
extern "C" void* fn_94_14B38(void*, short);
extern "C" void* fn_94_14BF4(void*, short);
extern "C" void* fn_94_4BF4(void*, short);
extern "C" void* fn_94_6560(void*, short);
extern "C" void* fn_94_4C50(void*, short);
extern "C" void* fn_94_1FA2C(void*, short);
extern "C" void* fn_94_1559C(void*, short);
extern "C" void* fn_94_14CEC(void*, short);
extern "C" void* fn_94_14D64(void*, short);
extern "C" void* fn_94_4D60(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_94_1FA98(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1F6FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_147B8(storage + 0x10FC, -1);
        fn_94_14814(storage + 0x10E4, -1);
        fn_94_14870(storage + 0xF48, -1);
        fn_94_15434(storage + 0xEE8, -1);
        fn_94_1F864(storage + 0xE7C, -1);
        fn_94_1F93C(storage + 0xD04, -1);
        fn_94_149E4(storage + 0xC60, -1);
        fn_94_4B58(storage + 0xC2C, -1);
        fn_94_15540(storage + 0xC14, -1);
        fn_94_14A6C(storage + 0xAB0, -1);
        fn_94_14AD8(storage + 0xA48, -1);
        fn_94_14B38(storage + 0xA3C, -1);
        fn_94_14BF4(storage + 0x9CC, -1);
        fn_94_4BF4(storage + 0x990, -1);
        fn_94_6560(storage + 0x8E8, -1);
        fn_94_4C50(storage + 0x834, -1);
        fn_94_1FA2C(storage + 0x6A8, -1);
        fn_94_1559C(storage + 0x598, -1);
        fn_94_14CEC(storage + 0x568, -1);
        fn_94_14D64(storage + 0x558, -1);
        fn_94_4D60(storage + 0x540, -1);
        __dt__16soModuleAccesserFv(storage + 0x460, -1);
        fn_94_1FA98(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
