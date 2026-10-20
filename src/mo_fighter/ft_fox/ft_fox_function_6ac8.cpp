#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_97_6B40(void* object, short flag);

extern "C" void* fn_97_6AC8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2d0, -1);
        if (object != 0) {
            fn_97_6B40(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
