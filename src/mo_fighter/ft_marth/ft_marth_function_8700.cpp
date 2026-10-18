#pragma force_active on
extern "C" {
extern void fn_106_94B4(void*, short);
extern void __dl__FPv(void*);

void* fn_106_8700(void* object, short count) {
    if (object != 0) {
        fn_106_94B4((char*)object + 4, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
