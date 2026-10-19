#pragma force_active on
extern "C" void fn_105_1A334(void*, short);
extern "C" void fn_105_1A5F4(void*, short);
void operator delete(void*);

extern "C" void* fn_105_1A2C4(void* object, short deleting) {
    if (object != 0) {
        fn_105_1A334(static_cast<unsigned char*>(object) + 0x2088, -1);
        fn_105_1A5F4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
