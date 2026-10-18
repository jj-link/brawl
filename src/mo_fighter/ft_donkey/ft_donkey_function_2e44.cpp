#pragma force_active on
extern "C" {
void* fn_27_19816C(void*, short);
void __dl__FPv(void*);

void* fn_92_2E44(void* object, short deleting) {
    if (object != 0) {
        fn_27_19816C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
