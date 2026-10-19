#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_101B8(void*, short);
extern "C" void* fn_97_102D4(void*, short);

extern "C" void* fn_97_10148(void* object, short deleting) {
    if (object != 0) {
        fn_97_101B8(static_cast<unsigned char*>(object) + 0x1730, -1);
        fn_97_102D4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
