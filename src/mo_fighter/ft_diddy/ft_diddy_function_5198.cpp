#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_115_5210(void*, short);

extern "C" void* fn_115_5198(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x11c, -1);
        if (object != 0) {
            fn_115_5210(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
