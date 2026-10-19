#pragma force_active on
extern "C" void* fn_27_1A4778(void* object, short deleting);
extern void operator delete(void*);

extern "C" void* fn_93_12F64(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A4778(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
