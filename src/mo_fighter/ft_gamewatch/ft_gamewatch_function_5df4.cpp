#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_5E64(void*, short);
extern "C" void* fn_107_6340(void*, short);

extern "C" void* fn_107_5DF4(void* object, short deleting) {
    if (object != 0) {
        fn_107_5E64(static_cast<unsigned char*>(object) + 0x20F0, -1);
        fn_107_6340(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
