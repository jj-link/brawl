#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1FE4(void* object, short deleting);
extern "C" void fn_119_3F4C(void* object, short deleting);

extern "C" void* fn_119_3ED4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1FE4(storage + 0x244, -1);
        if (object != 0) {
            fn_119_3F4C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
