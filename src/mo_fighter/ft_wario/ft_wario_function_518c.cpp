#pragma force_active on
extern "C" void* fn_110_3F20(void*, short);
extern "C" void* fn_110_3FA4(void*, short);
extern "C" void* fn_110_5228(void*, short);
extern "C" void* fn_110_5284(void*, short);
extern "C" void* fn_110_5C9C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_110_518C(void* object, short deleting) {
    if (object != 0) {
        void* p = object;
        fn_110_3F20(static_cast<char*>(p) + 0xe14, static_cast<short>(-1));
        fn_110_3FA4(static_cast<char*>(p) + 0xe00, static_cast<short>(-1));
        fn_110_5228(static_cast<char*>(p) + 0x930, static_cast<short>(-1));
        fn_110_5284(static_cast<char*>(p) + 0xbc, static_cast<short>(-1));
        fn_110_5C9C(static_cast<char*>(p) + 0x10, static_cast<short>(-1));
        fn_27_C74E8(p, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
