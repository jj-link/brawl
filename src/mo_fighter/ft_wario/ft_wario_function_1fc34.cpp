#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_B7C8(void*, short);

extern "C" void* fn_110_1FC34(void* object, short deleting) {
    if (object != 0) {
        fn_110_B7C8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
