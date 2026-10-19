#pragma force_active on
extern "C" {
void* fn_100_AD2C(void* object, short deleting);
void* fn_100_AC0C(char* object, short flag);
void __dl__FPv(void*);
}

extern "C" void* fn_100_AD8C(char* object, short deleting) {
    if (object != 0) {
        fn_100_AD2C(object + 0x60, -1);
        fn_100_AC0C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
