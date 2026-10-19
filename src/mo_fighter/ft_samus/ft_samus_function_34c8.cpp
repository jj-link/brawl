#pragma force_active on
extern "C" {
extern void* fn_94_33FC(void*, short);
extern void* fn_94_3534(void*, short);
extern void __dl__FPv(void*);
}

extern "C" void* fn_94_34C8(void* object, short deleting) {
    if (object != 0) {
        fn_94_33FC((char*)object + 0x1838, -1);
        fn_94_3534((char*)object + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
