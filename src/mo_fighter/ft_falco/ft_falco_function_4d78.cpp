#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_108_4E14(void*, short);
extern "C" void fn_108_1F70(void*, short);
extern "C" void* fn_108_4E54(void*, short);

extern "C" void* fn_108_4D78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_108_4E14(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_108_1F70(storage + 0x20, 0);
            fn_108_4E54(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
