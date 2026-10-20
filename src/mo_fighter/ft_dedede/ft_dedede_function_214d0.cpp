#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_21470(void*, short);
extern "C" void* fn_117_21398(void*, short);

extern "C" void* fn_117_214D0(void* object, short deleting) {
    if (object != 0) {
        fn_117_21470(static_cast<unsigned char*>(object) + 0xA4, static_cast<short>(-1));
        if (object != 0) {
            fn_117_21398(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
