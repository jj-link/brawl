#pragma force_active on
void operator delete(void*);
extern "C" void fn_97_52E8(void*, short);
extern "C" void* fn_97_572C(void*, short);

extern "C" void* fn_97_5278(void* object, short deleting) {
    if (object != 0) {
        fn_97_52E8(static_cast<unsigned char*>(object) + 0x4B24, -1);
        fn_97_572C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
