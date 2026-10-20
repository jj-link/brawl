#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_112_6170(void* object, short deleteFlag);

extern "C" void* fn_112_60F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x218, -1);
        if (object != 0) {
            fn_112_6170(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
