#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_123_4028(void*, short);
void operator delete(void*);

extern "C" void* fn_123_5E08(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_123_4028(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
