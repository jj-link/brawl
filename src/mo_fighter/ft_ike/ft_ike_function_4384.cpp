#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_43F4(void* object, short deleting);
extern "C" void* fn_27_1A1E70(void* object, short deleting);

extern "C" void* fn_119_4384(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, -1);
        fn_119_43F4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
