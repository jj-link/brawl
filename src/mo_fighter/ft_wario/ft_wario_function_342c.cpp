#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_349C(void*, short);
extern "C" void* fn_110_4A0C(void*, short);

extern "C" void* fn_110_342C(void* object, short deleting) {
    if (object != 0) {
        fn_110_349C(static_cast<unsigned char*>(object) + 0x20b0, -1);
        fn_110_4A0C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
