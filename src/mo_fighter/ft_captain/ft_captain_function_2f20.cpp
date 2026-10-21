// Destroy the embedded modules in reverse construction order, then the base.
#pragma force_active on
extern "C" {
void* fn_27_CB048(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void* fn_27_197EF4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_2F20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_CB048(storage + 0x220, destroy);
        fn_27_199214(storage + 0x94, destroy);
        fn_27_A78FC(storage + 0x78, destroy);
        fn_27_14E050(storage + 0x10, destroy);
        if (object != 0) {
            fn_27_197EF4(object, destroy);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
