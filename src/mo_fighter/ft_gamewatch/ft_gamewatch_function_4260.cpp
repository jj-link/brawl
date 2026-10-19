#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_4260(void* object, short deleting) {
    if (object != 0) {
        fn_27_5AE44(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
