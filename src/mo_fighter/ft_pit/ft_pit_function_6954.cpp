#pragma force_active on

extern "C" {
void* fn_27_565F0(void*, short);
void* fn_112_69C0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_112_6954(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_112_69C0(object, -1);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
