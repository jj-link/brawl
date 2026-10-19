#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_102_10D40(void*, short);

extern "C" void* fn_102_140F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x13F10, -1);
        fn_102_10D40(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
