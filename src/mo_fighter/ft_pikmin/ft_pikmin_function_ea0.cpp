#pragma force_active on
extern "C" {
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);

void* fn_113_EA0(void* object, short deleting) {
    if (object != 0) {
        fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
