#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_99_4714(void*, short);

extern "C" void* fn_99_469C(void* object, short deleting) {
    if (object) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x4B8, -1);
        if (object) {
            fn_99_4714(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
