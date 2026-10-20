#pragma force_active on
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void* fn_99_469C(void*, short);

extern "C" void* fn_99_4624(void* object, short deleting) {
    if (object) {
        fn_27_1A1CFC(static_cast<unsigned char*>(object) + 0x524, -1);
        if (object) {
            fn_99_469C(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
