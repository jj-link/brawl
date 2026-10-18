#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_CEB4(void*, short);

extern "C" void* fn_125_CF14(void* object, short deleting) {
    if (object != 0) {
        fn_125_CEB4(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
