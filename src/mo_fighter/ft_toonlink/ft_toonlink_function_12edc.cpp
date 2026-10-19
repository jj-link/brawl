#pragma force_active on
extern "C" void* fn_121_12E7C(void* object, short deleting);

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_121_12EDC(void* obj, short deleting) {
    if (obj != 0) {
        fn_121_12E7C(obj, 0);
        if (deleting > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
