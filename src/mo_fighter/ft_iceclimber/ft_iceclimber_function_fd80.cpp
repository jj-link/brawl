#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_FD20(void* object, short deleting);
extern "C" void fn_105_FBEC(void* object, short deleting);

extern "C" void* fn_105_FD80(void* object, short deleting) {
    if (object != 0) {
        fn_105_FD20(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_105_FBEC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
