#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_4D08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_4CAC(void* object, short deleting) {
    if (object != 0) {
        fn_126_4D08(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
