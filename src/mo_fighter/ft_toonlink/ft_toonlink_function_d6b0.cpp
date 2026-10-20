#pragma force_active on
extern "C" void fn_121_D650(void* object, short deleting);
extern "C" void* fn_121_D518(void* object, short deleting);
extern "C" void operator delete(void*);

extern "C" void* fn_121_D6B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_D650(storage + 0x17c, -1);
        if (object != 0) {
            fn_121_D518(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
