#pragma force_active on
extern "C" void fn_122_948C(void*, short);
extern "C" void* fn_27_1A1B88(void*, short);
void operator delete(void*);

extern "C" void* fn_122_9414(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2D0, -1);
        if (object != 0) {
            fn_122_948C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
