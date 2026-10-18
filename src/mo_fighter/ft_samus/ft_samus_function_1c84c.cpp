#pragma force_active on
extern "C" void* fn_94_4928(void*, short);
extern "C" void* fn_94_49AC(void*, short);
extern "C" void* fn_94_1C8E8(void*, short);
extern "C" void* fn_94_148FC(void*, short);
extern "C" void* fn_94_1C944(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_94_1C84C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_94_4928(static_cast<char*>(object) + 0xf8, -1);
        fn_94_49AC(members + 0xe4, -1);
        fn_94_1C8E8(members + 0xb4, -1);
        fn_94_148FC(members + 0x50, -1);
        fn_94_1C944(members + 0x10, -1);
        fn_27_C74E8(members, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
