#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_B64B8(void*, short);

extern "C" void* fn_117_2E98(void* object, short deleting) {
    if (object != 0) {
        fn_27_B64B8(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
