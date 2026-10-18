#pragma force_active on
extern "C" void* fn_27_1A220C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1F8DC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A220C(static_cast<char*>(object) + 0x10, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
