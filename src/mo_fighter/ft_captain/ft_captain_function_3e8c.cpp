#pragma force_active on
extern "C" {
void fn_100_3AA8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_3E8C(void* object, short flag) {
    if (object != 0) {
        fn_100_3AA8(static_cast<char*>(object) + 0x14, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
