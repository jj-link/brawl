#pragma force_active on
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void* fn_113_4B50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_4AD8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<char*>(object) + 0x524, -1);
        if (object != 0) {
            fn_113_4B50(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
