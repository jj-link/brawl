#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_1C4C8(void*, short);
extern "C" void fn_113_EE84(void*, short);

extern "C" void* fn_113_1C528(void* object, short deleting) {
    if (object != 0) {
        fn_113_1C4C8(static_cast<unsigned char*>(object) + 0x44, -1);
        fn_113_EE84(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
