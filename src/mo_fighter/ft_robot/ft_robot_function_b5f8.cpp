#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_B598(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_B5F8(void* object, short deleting) {
    if (object != 0) {
        fn_120_B598(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
