#pragma force_active on
extern "C" {
void* fn_27_19874C(void*, short);
void __dl__FPv(void*);
void* fn_126_2E78(void* object, int del);
}

void* fn_126_2E78(void* object, int del) {
    if (object) {
        fn_27_19874C(object, -1);
        if ((short)del > 0)
            __dl__FPv(object);
    }
    return object;
}
