#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_33A0(void*, short);
extern "C" void* fn_123_47E8(void*, short);

extern "C" void* fn_123_3330(void* object, short deleting) {
    if (object != 0) {
        fn_123_33A0(static_cast<unsigned char*>(object) + 0x2D40, -1);
        fn_123_47E8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
