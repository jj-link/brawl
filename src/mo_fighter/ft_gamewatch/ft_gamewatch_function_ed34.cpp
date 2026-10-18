#pragma force_active on
extern "C" void* fn_107_ECD8(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_107_ED34(void* object, short deleting) {
    if (object != 0) {
        fn_107_ECD8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
