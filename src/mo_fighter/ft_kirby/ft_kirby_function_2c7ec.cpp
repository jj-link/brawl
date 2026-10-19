#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_2C85C(void*, short);
extern "C" void* fn_96_2C978(void*, short);

extern "C" void* fn_96_2C7EC(void* object, short deleting) {
    if (object != 0) {
        fn_96_2C85C(static_cast<unsigned char*>(object) + 0x1980, -1);
        fn_96_2C978(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
