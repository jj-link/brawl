#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_126_3CE0(void*, short);

void operator delete(void*);

extern "C" void* fn_126_3C68(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x88, -1);
        if (object != 0) {
            fn_126_3CE0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
