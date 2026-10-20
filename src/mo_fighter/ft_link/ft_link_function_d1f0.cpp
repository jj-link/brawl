#pragma force_active on
extern "C" void fn_93_D190(void* object, short deleting);
extern "C" void* fn_93_D060(void* object, short deleting);
extern void operator delete(void*);

extern "C" void* fn_93_D1F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_D190(storage + 0x94, -1);
        if (object != 0) {
            fn_93_D060(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
