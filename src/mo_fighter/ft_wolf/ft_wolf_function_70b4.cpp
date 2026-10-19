#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_125_3F78(void*, short);
void operator delete(void*);

extern "C" void* fn_125_70B4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_125_3F78(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
