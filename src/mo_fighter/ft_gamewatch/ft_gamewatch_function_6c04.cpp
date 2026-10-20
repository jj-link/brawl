#pragma force_active on
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void* fn_107_6C7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_6C04(void* object, int deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<char*>(object) + 0x524, -1);
        if (object != 0) {
            fn_107_6C7C(object, 0);
        }
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
