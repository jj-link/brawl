#pragma force_active on
void operator delete(void*);
extern "C" void fn_121_D4B8(void* object, short deleting);
extern "C" void* fn_121_D384(void* object, short deleting);

extern "C" void* fn_121_D518(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_D4B8(storage + 0x134, -1);
        if (object != 0) {
            fn_121_D384(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
