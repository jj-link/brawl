#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_A1E80(void*, short);

extern "C" void* fn_126_3F48(void* object, short deleting) {
    if (object != 0) {
        fn_27_A1E80(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
