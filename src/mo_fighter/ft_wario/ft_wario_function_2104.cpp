#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_110_21DC(void*, short);
void* fn_110_23A0(void*, short);
void* fn_110_2468(void*, short);
void* fn_110_24F4(void*, short);
void* fn_110_2580(void*, short);
void* fn_110_260C(void*, short);
void* fn_110_2698(void*, short);
void* fn_110_2724(void*, short);
void* fn_110_27B0(void*, short);
void* fn_110_283C(void*, short);
void* fn_110_28C8(void*, short);
}

extern "C" void* fn_110_2104(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_21DC(storage + 0x1540, memberDeleting);
        fn_110_23A0(storage + 0x141C, memberDeleting);
        fn_110_2468(storage + 0x12F0, memberDeleting);
        fn_110_24F4(storage + 0x11C4, memberDeleting);
        fn_110_2580(storage + 0x1098, memberDeleting);
        fn_110_260C(storage + 0xF6C, memberDeleting);
        fn_110_2698(storage + 0xE40, memberDeleting);
        fn_110_2724(storage + 0xD14, memberDeleting);
        fn_110_27B0(storage + 0xBE8, memberDeleting);
        fn_110_283C(storage + 0xABC, memberDeleting);
        fn_110_28C8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}