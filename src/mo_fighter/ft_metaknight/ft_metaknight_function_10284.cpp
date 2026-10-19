#pragma force_active on
typedef unsigned char u8;
typedef short s16;

extern "C" void* fn_27_6A3D8(void*, s16);
extern "C" void* fn_27_CBB00(void*, s16);
void operator delete(void*);

extern "C" void* fn_111_10284(void* object, s16 flag) {
    if (object != 0) {
        s16 destroy = -1;
        fn_27_6A3D8(static_cast<u8*>(object) + 0x110, destroy);
        fn_27_CBB00(object, destroy);
        if (flag > 0) {
            operator delete(object);
        }
    }
    return object;
}
