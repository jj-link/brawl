#pragma force_active on
void operator delete(void*);

extern "C" void* fn_104_3DB0(void*, short);

extern "C" void* fn_104_11F18(void* object, short deleting) {
    if (object != 0) {
        fn_104_3DB0(static_cast<unsigned char*>(object) + 0x34, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
