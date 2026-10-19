#pragma force_active on
extern "C" {
void* fn_96_336C(void* object, short deleting);
void __dl__FPv(void* p);

void* fn_96_33CC(void* object, short deleting) {
    if (object != 0) {
        fn_96_336C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
