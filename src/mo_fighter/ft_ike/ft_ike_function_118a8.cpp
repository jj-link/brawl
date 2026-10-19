#pragma force_active on
void operator delete(void*);

extern "C" void* fn_119_11848(void* object, short deleting);

extern "C" void* fn_119_118A8(void* object, short deleting) {
    if (object != 0) {
        fn_119_11848(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
