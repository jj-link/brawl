#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_C2F8(void*, short);
extern "C" void* fn_104_C1D8(void*, short);

extern "C" void* fn_104_C358(void* object, short deleting) {
    if (object != 0) {
        fn_104_C2F8(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_104_C1D8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
