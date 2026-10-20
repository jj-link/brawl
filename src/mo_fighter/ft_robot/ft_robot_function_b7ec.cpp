#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_B78C(void* object, short deleting);
extern "C" void fn_120_B658(void* object, short deleting);

extern "C" void* fn_120_B7EC(void* object, short deleting) {
    if (object != 0) {
        fn_120_B78C(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_120_B658(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
