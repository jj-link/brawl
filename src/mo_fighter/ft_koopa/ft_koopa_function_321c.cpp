#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_328C(void*, short);
extern "C" void* fn_102_423C(void*, short);

extern "C" void* fn_102_321C(void* object, short deleting) {
    if (object != 0) {
        fn_102_328C(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_102_423C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
