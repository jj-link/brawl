#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_2138(void*, short);
void* fn_101_2194(void*, short);
}

extern "C" void* fn_101_4364(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_101_2138(members + 0x14, static_cast<short>(0));
        fn_101_2194(members + 0x8, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
