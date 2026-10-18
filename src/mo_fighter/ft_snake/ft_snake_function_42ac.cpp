#pragma force_active on
extern "C" void fn_122_3E48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_42AC(void* object, short deleting) {
    if (object != 0) {
        fn_122_3E48(static_cast<char*>(object) + 0x14, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
