#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_121_51B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_5228(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x4B8, -1);
        if (object != 0) {
            fn_121_51B0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
