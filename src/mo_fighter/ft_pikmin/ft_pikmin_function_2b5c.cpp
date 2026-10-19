#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_B24(void*, short);
extern "C" void* fn_113_2BC8(void*, short);

extern "C" void* fn_113_2B5C(void* object, short deleting) {
    if (object != 0) {
        fn_113_B24(static_cast<unsigned char*>(object) + 0x20, 0);
        fn_113_2BC8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
