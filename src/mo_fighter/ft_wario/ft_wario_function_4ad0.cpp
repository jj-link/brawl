#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_4B30(void*, short);

extern "C" void* fn_110_4AD0(void* object, short deleting) {
    if (object != 0) {
        fn_110_4B30(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
