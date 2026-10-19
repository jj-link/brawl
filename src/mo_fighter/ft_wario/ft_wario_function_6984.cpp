#pragma force_active on
extern "C" {
void* fn_110_69E0(void* object, short deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_110_6984(void* object, short deleting) {
    if (object != 0) {
        fn_110_69E0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
