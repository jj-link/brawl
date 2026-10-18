#pragma force_active on
extern "C" void* fn_96_8EB4(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_96_8F14(void* object, short deleting) {
    if (object != 0) {
        fn_96_8EB4(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
