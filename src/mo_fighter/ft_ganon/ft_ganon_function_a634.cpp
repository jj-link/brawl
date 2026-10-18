#pragma force_active on
extern "C" void fn_109_A5D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_A634(void* object, short deleting) {
    if (object != 0) {
        fn_109_A5D8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
