#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void* object, short deleting);
extern "C" void* fn_104_64D8(void* object, short deleting);

extern "C" void* fn_104_6460(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x11c, -1);
        if (object != 0) {
            fn_104_64D8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
