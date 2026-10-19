#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_1A098(void*, short);
extern "C" void* fn_102_1A3C4(void*, short);

extern "C" void* fn_102_1A028(void* object, short deleting) {
    if (object != 0) {
        fn_102_1A098(static_cast<unsigned char*>(object) + 0x1884, -1);
        fn_102_1A3C4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
