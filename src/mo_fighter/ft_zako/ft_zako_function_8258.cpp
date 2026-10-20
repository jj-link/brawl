#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_81F8(void* object, short deleting);
extern "C" void fn_126_80C4(void* object, short deleting);

extern "C" void* fn_126_8258(void* object, short deleting) {
    if (object != 0) {
        fn_126_81F8(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_126_80C4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
