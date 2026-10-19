#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_5210(void*, short);
extern "C" void* fn_125_5654(void*, short);

extern "C" void* fn_125_51A0(void* object, short deleting) {
    if (object != 0) {
        fn_125_5210(static_cast<unsigned char*>(object) + 0x4B24, -1);
        fn_125_5654(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
