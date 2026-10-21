#pragma force_active on

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_120_5540(void*, short);
void* fn_27_21038(void*, short);
void* fn_120_55AC(void*, short);
void* fn_120_5608(void*, short);
void* fn_120_5664(void*, short);
void* fn_120_56C0(void*, short);
void* fn_120_571C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_548C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_13C90(storage + 0x26C, destroy);
        fn_120_5540(storage + 0x230, destroy);
        fn_27_21038(storage + 0x220, destroy);
        fn_120_55AC(storage + 0x200, destroy);
        fn_120_5608(storage + 0x1E0, destroy);
        fn_120_5664(storage + 0x1A8, destroy);
        fn_120_56C0(storage + 0xC4, destroy);
        fn_120_571C(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
