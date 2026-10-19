#pragma force_active on
extern "C" {
void* fn_104_17EF8(void* object, short deleting);
void* fn_104_1864C(void* object, short deleting);

void* fn_104_185DC(void* object, short deleting) {
    if (object != 0) {
        fn_104_17EF8(static_cast<unsigned char*>(object) + 0x8B40, static_cast<short>(-1));
        fn_104_1864C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
