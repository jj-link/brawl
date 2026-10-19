#pragma force_active on
extern "C" {
void* fn_97_43C8(void*, short);
void __dl__FPv(void*);

void* fn_97_10534(void* obj, short count) {
    if (obj != 0) {
        short zero = 0;
        fn_97_43C8(obj, zero);
        if (count > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
