#pragma force_active on
void operator delete(void*);
extern "C" void fn_118_521C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_51BC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_118_521C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
