extern "C" {
void* fn_99_F2E8(void*, short);
void* fn_99_F344(void*, short);
void* fn_99_F3A0(void*, short);
void* fn_99_F424(void*, short);
void* fn_99_F4B0(void*, short);
void* fn_99_F510(void*, short);
void* fn_99_F69C(void*, short);
void* fn_99_F928(void*, short);
void* fn_99_3FD8(void*, short);
void* fn_99_F9F4(void*, short);
void* fn_99_FA50(void*, short);
void* fn_99_FABC(void*, short);
void* fn_99_FB68(void*, short);
void* fn_99_FBC8(void*, short);
void* fn_99_FC24(void*, short);
void* fn_99_FCA8(void*, short);
void* fn_99_4074(void*, short);
void* fn_99_40D0(void*, short);
void* fn_99_FD88(void*, short);
void* fn_99_FF34(void*, short);
void* fn_99_FFA0(void*, short);
void* fn_99_10074(void*, short);
void* fn_99_4184(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_99_10170(void*, short);
}

// Destroy the embedded modules in reverse construction order, then the base.
// Only a positive signed deletion flag releases the enclosing allocation.
extern "C" void* fn_99_F168(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_99_F2E8(storage + 0x1914, -1);
        fn_99_F344(storage + 0x18fc, -1);
        fn_99_F3A0(storage + 0x17a0, -1);
        fn_99_F424(storage + 0x160c, -1);
        fn_99_F4B0(storage + 0x15ac, -1);
        fn_99_F510(storage + 0x14f8, -1);
        fn_99_F69C(storage + 0x1334, -1);
        fn_99_F928(storage + 0x1290, -1);
        fn_99_3FD8(storage + 0x125c, -1);
        fn_99_F9F4(storage + 0x1244, -1);
        fn_99_FA50(storage + 0x10e0, -1);
        fn_99_FABC(storage + 0x1078, -1);
        fn_99_FB68(storage + 0x106c, -1);
        fn_99_FBC8(storage + 0x1044, -1);
        fn_99_FC24(storage + 0xe74, -1);
        fn_99_FCA8(storage + 0xe10, -1);
        fn_99_4074(storage + 0xdd4, -1);
        fn_99_40D0(storage + 0xd1c, -1);
        fn_99_FD88(storage + 0xb10, -1);
        fn_99_FF34(storage + 0x930, -1);
        fn_99_FFA0(storage + 0x900, -1);
        fn_99_10074(storage + 0x8f0, -1);
        fn_99_4184(storage + 0x8d8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7f8, -1);
        fn_99_10170(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
