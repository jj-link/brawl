#pragma force_active on
extern "C" void fn_109_5874(void*, short);
extern "C" void fn_109_3ED8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_5808(void* object, short deleting) {
    if (object != 0) {
        fn_109_5874(static_cast<unsigned char*>(object) + 0x24, -1);
        fn_109_3ED8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
