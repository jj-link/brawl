#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_3334(void*, short);
extern "C" void* fn_119_34B8(void*, short);

extern "C" void* fn_119_32C4(void* object, short deleting) {
    if (object != 0) {
        fn_119_3334(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_119_34B8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
