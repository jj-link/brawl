#pragma force_active on
extern "C" {

void* __dl__FPv(void*);
extern "C" void* fn_116_1DCF4(void* object, short deleting);
extern "C" void* fn_116_1E158(void* object, short deleting);

extern "C" void* fn_116_1E0EC(void* object, short deleting) {
    if (object != 0) {
        fn_116_1DCF4(static_cast<unsigned char*>(object) + 0x16B8, -1);
        fn_116_1E158(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

}
