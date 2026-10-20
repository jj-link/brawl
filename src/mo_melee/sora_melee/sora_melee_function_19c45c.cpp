#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_4AD20(void*, int);
void __dl__FPv(void*);
void* fn_27_19C45C(void*, short);
}

void* fn_27_19C45C(void* object, short memberDeleting) {
    if (object) {
        __destroy_arr((char*)object + 0xC, fn_27_4AD20, 0x5C, 4);
        if (memberDeleting > 0)
            __dl__FPv(object);
    }
    return object;
}
