#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_B2D0(void* object, short deleting);
extern "C" void* fn_120_B1B0(void* object, short deleting);

extern "C" void* fn_120_B330(void* object, short deleting) {
    if (object != 0) {
        fn_120_B2D0(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_120_B1B0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
