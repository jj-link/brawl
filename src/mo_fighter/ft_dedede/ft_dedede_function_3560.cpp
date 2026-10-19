#pragma force_active on
void operator delete(void*);

extern "C" void* fn_117_35DC(void* object, short deleting);
extern "C" void* fn_117_369C(void* object, short deleting);

extern "C" void* fn_117_3560(void* object, short deleting) {
    if (object != 0) {
        fn_117_35DC(static_cast<unsigned char*>(object) + 0x392A8, -1);
        if (object != 0) {
            fn_117_369C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
