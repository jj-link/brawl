#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_D190(void* object, short deleting);
extern "C" void fn_97_D05C(void* object, short deleting);

extern "C" void* fn_97_D1F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_D190(storage + 0x134, -1);
        if (object != 0) {
            fn_97_D05C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
