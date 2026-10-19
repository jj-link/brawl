#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C31CC(void*, short);

extern "C" void* fn_96_8A88(void* object, short deleting) {
    if (object) {
        fn_27_C31CC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
