#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_2BF8(void*, short);
void* fn_92_2C54(void*, short);
void* fn_92_2CB0(void*, short);
void* fn_92_2D0C(void*, short);
void* fn_92_2D68(void*, short);
void* fn_92_2DC4(void*, short);
void* fn_92_2EA0(void*, short);
void* fn_92_2EFC(void*, short);
void* fn_92_2F58(void*, short);
void* fn_92_2FCC(void*, short);
void* fn_92_3064(void*, short);
void* fn_92_30C0(void*, short);
void* fn_92_3210(void*, short);
void* fn_92_4FC4(void*, short);
void* fn_92_5024(void*, short);
void* fn_92_5178(void*, short);
void* fn_92_5CE8(void*, short);
void* fn_92_41C0(void*, short);
void* fn_92_5DC4(void*, short);
void* fn_92_5E38(void*, short);
void* fn_92_5F14(void*, short);
void* fn_92_5F70(void*, short);
void* fn_92_5FDC(void*, short);
void* fn_92_6088(void*, short);
void* fn_92_60FC(void*, short);
void* fn_92_6158(void*, short);
void* fn_92_61B4(void*, short);
void* fn_92_6210(void*, short);
void* fn_92_626C(void*, short);
void* fn_92_62E0(void*, short);
void* fn_92_634C(void*, short);
void* fn_92_63DC(void*, short);
void* fn_92_646C(void*, short);
void* fn_92_64F0(void*, short);
void* fn_92_6574(void*, short);
void* fn_92_44CC(void*, short);
void* fn_92_66A8(void*, short);
void* fn_92_4528(void*, short);
void* fn_92_6714(void*, short);
void* fn_92_6AD8(void*, short);
void* fn_92_6BAC(void*, short);
void* fn_92_6C24(void*, short);
void* fn_92_4788(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_92_6C80(void*, short);
}

// Destroy the embedded modules in reverse construction order, then the base.
extern "C" void* fn_92_2958(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_92_2BF8(storage + 0x1063C, destroy);
        fn_92_2C54(storage + 0x10600, destroy);
        fn_92_2CB0(storage + 0x10598, destroy);
        fn_92_2D0C(storage + 0x1054C, destroy);
        fn_92_2D68(storage + 0x103F8, destroy);
        fn_92_2DC4(storage + 0x102E8, destroy);
        fn_92_2EA0(storage + 0x102A0, destroy);
        fn_92_2EFC(storage + 0x10220, destroy);
        fn_92_2F58(storage + 0x1015C, destroy);
        fn_92_2FCC(storage + 0xFDE8, destroy);
        fn_92_3064(storage + 0xFDB8, destroy);
        fn_92_30C0(storage + 0xFC14, destroy);
        fn_92_3210(storage + 0x5B64, destroy);
        fn_92_4FC4(storage + 0x5980, destroy);
        fn_92_5024(storage + 0x5678, destroy);
        fn_92_5178(storage + 0x47A4, destroy);
        fn_92_5CE8(storage + 0x46B0, destroy);
        fn_92_41C0(storage + 0x467C, destroy);
        fn_92_5DC4(storage + 0x4608, destroy);
        fn_92_5E38(storage + 0x3EE4, destroy);
        fn_92_5F14(storage + 0x3EB4, destroy);
        fn_92_5F70(storage + 0x3D1C, destroy);
        fn_92_5FDC(storage + 0x3CAC, destroy);
        fn_92_6088(storage + 0x3C14, destroy);
        fn_92_60FC(storage + 0x3BDC, destroy);
        fn_92_6158(storage + 0x3BB8, destroy);
        fn_92_61B4(storage + 0x3B84, destroy);
        fn_92_6210(storage + 0x3B20, destroy);
        fn_92_626C(storage + 0x3970, destroy);
        fn_92_62E0(storage + 0x370C, destroy);
        fn_92_634C(storage + 0x2CA0, destroy);
        fn_92_63DC(storage + 0x2A88, destroy);
        fn_92_646C(storage + 0x212C, destroy);
        fn_92_64F0(storage + 0x1A70, destroy);
        fn_92_6574(storage + 0x19FC, destroy);
        fn_92_44CC(storage + 0x19C0, destroy);
        fn_92_66A8(storage + 0x1918, destroy);
        fn_92_4528(storage + 0x1864, destroy);
        fn_92_6714(storage + 0x1440, destroy);
        fn_92_6AD8(storage + 0x1180, destroy);
        fn_92_6BAC(storage + 0x115C, destroy);
        fn_92_6C24(storage + 0x0AC8, destroy);
        fn_92_4788(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_92_6C80(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
