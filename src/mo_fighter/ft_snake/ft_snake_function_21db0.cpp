#pragma force_active on
extern "C" void fn_122_7270(void*, short);
extern "C" void fn_122_21E20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_21DB0(void* object, short deleting) {
    if (object != 0) {
        fn_122_7270(static_cast<unsigned char*>(object) + 0x6130, -1);
        fn_122_21E20(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
