#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_33B8(void*, short);

extern "C" void* fn_117_335C(void* object, short deleting) {
    if (object != 0) {
        fn_117_33B8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
