#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_121_4D78(void* object, short deleting);

extern "C" void* fn_121_4DF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x1FC, -1);
        if (object != 0) {
            fn_121_4D78(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
