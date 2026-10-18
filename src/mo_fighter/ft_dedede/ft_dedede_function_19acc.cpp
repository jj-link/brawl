#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A2E14(void*, short);

extern "C" void* fn_117_19ACC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2E14(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
