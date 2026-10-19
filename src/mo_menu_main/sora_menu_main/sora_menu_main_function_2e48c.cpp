#pragma force_active on
extern "C" void fn_2_37C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_2_2E48C(void* object, int deleting) {
    if (object == 0)
        goto done;

    if (object != 0)
        __destroy_arr((char*)object + 0x48, fn_2_37C, 0xA8, 9);

    if (deleting > 0)
        __dl__FPv(object);

done:
    return object;
}
