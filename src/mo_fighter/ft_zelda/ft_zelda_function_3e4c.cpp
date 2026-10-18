#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_104_3EE8(void*, short);
extern "C" void* fn_104_1F8C(void*, short);
extern "C" void* fn_104_3F28(void*, short);

extern "C" void* fn_104_3E4C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_104_3EE8(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_104_1F8C(storage + 0x20, 0);
            fn_104_3F28(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
