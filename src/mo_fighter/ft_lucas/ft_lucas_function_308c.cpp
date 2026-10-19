#pragma force_active on
extern "C" void* fn_27_10424(void*, short);
extern "C" void* fn_27_19A97C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_308C(void* object, short shouldDelete) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 0x7C, -1);
        if (object != 0) {
            fn_27_19A97C(object, -1);
        }
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
