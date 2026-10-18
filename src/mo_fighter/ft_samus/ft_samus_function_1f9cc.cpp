#pragma force_active on
extern "C" void fn_94_47EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1F9CC(void* object, short deleting) {
    if (object != 0) {
        fn_94_47EC(static_cast<char*>(object) + 0x18, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
