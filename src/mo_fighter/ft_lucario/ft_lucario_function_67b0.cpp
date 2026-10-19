#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_67B0(void* object, short deleting) {
    if (object != 0) {
        fn_27_C9EDC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
