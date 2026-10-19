#pragma force_active on
extern "C" {
void* fn_109_6444(void* object, short deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_109_63E8(void* object, short deleting) {
    if (object != 0) {
        fn_109_6444(object, (short)0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
