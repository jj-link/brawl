#pragma force_active on
void operator delete(void*);

extern "C" void fn_97_3C1C(void*, short);

extern "C" void* fn_97_64D8(void* object, short deleting) {
    if (object != 0) {
        fn_97_3C1C(static_cast<unsigned char*>(object) + 0x1C0, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
