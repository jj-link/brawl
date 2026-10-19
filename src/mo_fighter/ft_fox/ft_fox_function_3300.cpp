#pragma force_active on
extern "C" void* fn_97_3370(void* object, short flag);
extern "C" void* fn_97_6208(void* object, short count);

extern "C" void* fn_97_3300(void* object, short deleting) {
    if (object != 0) {
        fn_97_3370(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_97_6208(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
