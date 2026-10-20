#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_104_6550(void* object, short flag);

extern "C" void* fn_104_64D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* self = static_cast<unsigned char*>(object);
        fn_27_1A1B88(self + 0xF0, -1);
        if (object != 0) {
            fn_104_6550(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
