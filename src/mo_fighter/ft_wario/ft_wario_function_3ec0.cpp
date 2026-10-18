#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_1FC8(void*, short);
extern "C" void* fn_110_3EC0(void* object, short deleting) {
    if (object != 0) {
        fn_110_1FC8(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
