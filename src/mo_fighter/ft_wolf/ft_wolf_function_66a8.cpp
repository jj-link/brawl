#pragma force_active on
extern "C" void fn_27_1A1CFC(void*, short);
extern "C" void fn_125_6720(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_66A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1CFC(storage + 0x524, -1);
        if (object != 0) {
            fn_125_6720(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
