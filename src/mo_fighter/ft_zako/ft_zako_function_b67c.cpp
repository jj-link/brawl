#pragma force_active on
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void fn_126_B11C(void* object, short param);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_126_B67C(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x812C, -1);
        fn_126_B11C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
