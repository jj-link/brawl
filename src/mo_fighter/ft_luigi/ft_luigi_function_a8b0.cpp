#pragma force_active on
extern "C" void* fn_99_A854(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_A8B0(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_A854(static_cast<unsigned char*>(object) + 0x4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
