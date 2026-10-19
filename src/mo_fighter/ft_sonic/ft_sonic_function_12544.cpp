#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_125B4(void*, short);
extern "C" void* fn_123_127E8(void*, short);

extern "C" void* fn_123_12544(void* object, short deleting) {
    if (object != 0) {
        fn_123_125B4(static_cast<unsigned char*>(object) + 0x1A60, -1);
        fn_123_127E8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
