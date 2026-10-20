#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_125_6810(void* object, short flag);

extern "C" void* fn_125_6798(void* object, short deleting) {
    if (object != 0) {
        unsigned char* base = static_cast<unsigned char*>(object);
        fn_27_1A1B88(base + 0x48c, -1);
        if (object != 0) {
            fn_125_6810(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
