#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_C2DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_C354(void* object, short deleting) {
    if (object != 0) {
        fn_118_C2DC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
