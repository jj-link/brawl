#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BB68(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_BD00(void* object, short deleting) {
    if (object != 0) {
        fn_118_BB68(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
