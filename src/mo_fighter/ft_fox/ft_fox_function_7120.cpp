#pragma force_active on
void operator delete(void*);
extern "C" void fn_97_718C(void*, short);
extern "C" void fn_97_4090(void*, short);

extern "C" void* fn_97_7120(void* object, short deleting) {
    if (object != 0) {
        fn_97_718C((unsigned char*)object + 0x24, -1);
        fn_97_4090(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
