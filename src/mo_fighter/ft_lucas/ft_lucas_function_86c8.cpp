#pragma force_active on
extern "C" void* fn_114_4150(void* object, short deleting);
extern "C" void* fn_114_8740(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_86C8(void* object, short parameter) {
    if (object) {
        fn_114_4150((char*)object + 0xac, -1);
        fn_114_8740((char*)object + 0x20, -1);
        fn_27_CD934(object, -1);
        if (parameter > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
