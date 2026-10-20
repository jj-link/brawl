#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_C94C(void* object, short deleting);
extern "C" void fn_104_C814(void* object, short deleting);

extern "C" void* fn_104_C9AC(void* object, short deleting) {
    if (object != 0) {
        fn_104_C94C(static_cast<unsigned char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_104_C814(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
