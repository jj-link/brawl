#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_3AA0(void*, short);
extern "C" void* fn_110_F5B0(void*, short);
extern "C" void* fn_110_F63C(void*, short);
extern "C" void* fn_110_F6C8(void*, short);
extern "C" void* fn_110_F754(void*, short);

extern "C" void* fn_110_F520(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_3AA0(storage + 0x4B0, -1);
        fn_110_F5B0(storage + 0x384, -1);
        fn_110_F63C(storage + 0x258, -1);
        fn_110_F6C8(storage + 0x12C, -1);
        fn_110_F754(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
