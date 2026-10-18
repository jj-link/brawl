#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_107_3DC4(void*, short);
extern "C" void fn_107_2050(void*, short);
extern "C" void* fn_107_3E04(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_3D28(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_107_3DC4(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_107_2050(storage + 0x20, 0);
            fn_107_3E04(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
