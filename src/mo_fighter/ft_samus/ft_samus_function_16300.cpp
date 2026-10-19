#pragma force_active on
extern "C" void fn_94_15D34(void*, short);
extern "C" void fn_94_1636C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_16300(void* object, short deleting) {
    if (object) {
        fn_94_15D34(static_cast<unsigned char*>(object) + 0x2bc0, -1);
        fn_94_1636C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
