#pragma force_active on
extern "C" {
extern void* fn_113_2CAA4(void*, short);
extern void* fn_113_2CAE4(void*, short);
extern void* fn_113_2CB44(void*, short);
extern void __dl__FPv(void*);
}

extern "C" void* fn_113_2CA2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short deleting2 = -1;
        fn_113_2CAA4(storage + 0xB0, deleting2);
        fn_113_2CAE4(storage + 0x30, deleting2);
        fn_113_2CB44(object, deleting2);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
