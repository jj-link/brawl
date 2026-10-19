#pragma force_active on
extern "C" {
void* fn_113_5FA8(void* object, short deleting);
void __dl__FPv(void*);

void* fn_113_5F4C(void* object, int deleting) {
    if (object != 0) {
        fn_113_5FA8(object, 0);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
