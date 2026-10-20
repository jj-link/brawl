#pragma force_active on
extern "C" {
void operator delete(void*);
void fn_27_1A1B88(void* member, short deleteFlag);
void fn_102_4A40(void* object, short deleting);

void* fn_102_49C8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2d0, -1);
        if (object != 0) {
            fn_102_4A40(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
