#pragma force_active on
extern "C" void* fn_125_CD7C(void* object, short deleting);
extern "C" void* fn_125_CC4C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_CDDC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_CD7C(storage + 0x94, -1);
        if (object != 0) {
            fn_125_CC4C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
