#pragma force_active on
extern "C" void fn_27_565F0(void*, short);
extern "C" void fn_114_7D48(void* object, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_7CDC(unsigned char* object, short flags) {
    if (object != 0) {
        fn_27_565F0(object + 0x14, -1);
        fn_114_7D48(object, -1);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
