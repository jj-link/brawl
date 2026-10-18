#pragma force_active on
void operator delete(void*);
extern "C" void fn_104_C298(void*, short);

extern "C" void* fn_104_C2F8(void* object, short deleting) {
    if (object != 0) {
        fn_104_C298(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
