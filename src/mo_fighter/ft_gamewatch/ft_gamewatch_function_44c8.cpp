#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_107_4554(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_44C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x20, -1);
        if (storage + 0x10 != 0) {
            fn_107_4554(storage + 0x10, 0);
        }
        if (object != 0) {
            fn_107_4554(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
