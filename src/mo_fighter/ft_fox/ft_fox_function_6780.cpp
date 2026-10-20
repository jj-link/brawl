#pragma force_active on
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void* fn_97_67F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_6780(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<char*>(object) + 0x524, -1);
        if (object != 0) {
            fn_97_67F8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
