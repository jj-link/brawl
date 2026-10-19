#pragma force_active on
extern "C" void* fn_27_1A4778(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_17940(void* object, short deleting) {
    if (object != 0) {
        short del = -1;
        fn_27_1A4778(object, del);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
