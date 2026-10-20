#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_119_3ED4(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_119_3E5C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x2D0, -1);
        if (object != 0) {
            fn_119_3ED4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
