void operator delete(void*);
extern "C" {
void* fn_100_2B4C(void*, short);
void* fn_100_2BA8(void*, short);
void* fn_100_2C04(void*, short);
void* fn_100_2C60(void*, short);
void* fn_100_2CBC(void*, short);
void* fn_100_2D18(void*, short);
void* fn_100_2DF4(void*, short);
void* fn_100_2E50(void*, short);
void* fn_100_2EAC(void*, short);
void* fn_100_2F20(void*, short);
void* fn_100_2FB8(void*, short);
void* fn_100_3014(void*, short);
void* fn_100_3164(void*, short);
void* fn_100_4DE4(void*, short);
void* fn_100_4E44(void*, short);
void* fn_100_4F98(void*, short);
void* fn_100_5B08(void*, short);
void* fn_100_4020(void*, short);
void* fn_100_5BE4(void*, short);
void* fn_100_5C58(void*, short);
void* fn_100_5D34(void*, short);
void* fn_100_5D90(void*, short);
void* fn_100_5DFC(void*, short);
void* fn_100_5EA8(void*, short);
void* fn_100_5F1C(void*, short);
void* fn_100_5F78(void*, short);
void* fn_100_5FD4(void*, short);
void* fn_100_6030(void*, short);
void* fn_100_608C(void*, short);
void* fn_100_6100(void*, short);
void* fn_100_616C(void*, short);
void* fn_100_61FC(void*, short);
void* fn_100_628C(void*, short);
void* fn_100_6310(void*, short);
void* fn_100_6394(void*, short);
void* fn_100_43B0(void*, short);
void* fn_100_64C8(void*, short);
void* fn_100_440C(void*, short);
void* fn_100_6534(void*, short);
void* fn_100_689C(void*, short);
void* fn_100_6970(void*, short);
void* fn_100_69E8(void*, short);
void* fn_100_46C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_100_6A44(void*, short);
}

// Destroy the embedded modules in reverse construction order, then the base.
extern "C" void* fn_100_28AC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_2B4C(storage + 0xA700, destroy);
        fn_100_2BA8(storage + 0xA6C4, destroy);
        fn_100_2C04(storage + 0xA65C, destroy);
        fn_100_2C60(storage + 0xA610, destroy);
        fn_100_2CBC(storage + 0xA4BC, destroy);
        fn_100_2D18(storage + 0xA3AC, destroy);
        fn_100_2DF4(storage + 0xA364, destroy);
        fn_100_2E50(storage + 0xA2E4, destroy);
        fn_100_2EAC(storage + 0xA220, destroy);
        fn_100_2F20(storage + 0x9EAC, destroy);
        fn_100_2FB8(storage + 0x9E7C, destroy);
        fn_100_3014(storage + 0x9CD8, destroy);
        fn_100_3164(storage + 0x5BC0, destroy);
        fn_100_4DE4(storage + 0x59DC, destroy);
        fn_100_4E44(storage + 0x56D4, destroy);
        fn_100_4F98(storage + 0x484C, destroy);
        fn_100_5B08(storage + 0x4758, destroy);
        fn_100_4020(storage + 0x4724, destroy);
        fn_100_5BE4(storage + 0x46B0, destroy);
        fn_100_5C58(storage + 0x3F8C, destroy);
        fn_100_5D34(storage + 0x3F5C, destroy);
        fn_100_5D90(storage + 0x3C8C, destroy);
        fn_100_5DFC(storage + 0x3C1C, destroy);
        fn_100_5EA8(storage + 0x3B84, destroy);
        fn_100_5F1C(storage + 0x3B4C, destroy);
        fn_100_5F78(storage + 0x3B28, destroy);
        fn_100_5FD4(storage + 0x3AF4, destroy);
        fn_100_6030(storage + 0x3A90, destroy);
        fn_100_608C(storage + 0x38E0, destroy);
        fn_100_6100(storage + 0x367C, destroy);
        fn_100_616C(storage + 0x2C10, destroy);
        fn_100_61FC(storage + 0x29F8, destroy);
        fn_100_628C(storage + 0x209C, destroy);
        fn_100_6310(storage + 0x19E0, destroy);
        fn_100_6394(storage + 0x196C, destroy);
        fn_100_43B0(storage + 0x1930, destroy);
        fn_100_64C8(storage + 0x1888, destroy);
        fn_100_440C(storage + 0x17D4, destroy);
        fn_100_6534(storage + 0x1440, destroy);
        fn_100_689C(storage + 0x1180, destroy);
        fn_100_6970(storage + 0x115C, destroy);
        fn_100_69E8(storage + 0x0AC8, destroy);
        fn_100_46C8(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_100_6A44(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
