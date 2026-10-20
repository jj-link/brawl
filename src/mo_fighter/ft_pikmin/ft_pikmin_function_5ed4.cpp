#pragma force_active on
extern "C" void* fn_113_2D0C(void* object, short deleting);
extern "C" void* fn_113_5F4C(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_5ED4(void* object, short deleting) {
    if (object != 0) {
        short d = -1;
        fn_113_2D0C(static_cast<unsigned char*>(object) + 0xAC, d);
        fn_113_5F4C(static_cast<unsigned char*>(object) + 0x20, d);
        fn_27_CD934(object, d);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
