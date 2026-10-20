#pragma force_active on
extern "C" {
void* fn_119_5424(void* object, short deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_119_53C8(void* object, short deleting) {
    if (object != 0) {
        fn_119_5424(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
