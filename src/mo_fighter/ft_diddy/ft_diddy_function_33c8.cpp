#pragma force_active on
extern "C" void fn_115_3434(void*, short);
extern "C" void fn_115_3E30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_33C8(void* object, short deleting) {
    if (object != 0) {
        fn_115_3434(static_cast<char*>(object) + 0x1CC4, -1);
        fn_115_3E30(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
