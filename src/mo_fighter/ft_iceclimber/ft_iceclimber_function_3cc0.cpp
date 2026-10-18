#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_105_3D5C(void* ptr, short flag);
extern "C" void fn_105_1F48(void*, short);
extern "C" void* fn_105_3D9C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_3CC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_105_3D5C(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_105_1F48(storage + 0x20, 0);
            fn_105_3D9C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
