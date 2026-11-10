#pragma force_active on

extern "C" {
extern void fn_106_31AC(void*, short);
extern void __dl__FPv(void*);

void* fn_106_4028(void* object, short count) {
    if (object != 0) {
        fn_106_31AC((char*)object + 0xBC, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
