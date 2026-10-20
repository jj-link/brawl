#pragma force_active on
extern "C" {
void* fn_100_AEBC(void* p, short flag);
void fn_100_AD8C(char* object, short deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_100_AF1C(char* object, short flag) {
    if (object != 0) {
        short neg = -1;
        fn_100_AEBC(object + 0x94, neg);
        if (object != 0) {
            short zero = 0;
            fn_100_AD8C(object, zero);
        }
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
