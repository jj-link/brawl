#pragma force_active on
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_126_4A58(void*, short);
void* fn_27_21038(void*, short);
void* fn_126_4AC4(void*, short);
void* fn_126_4B20(void*, short);
void* fn_126_4B7C(void*, short);
void* fn_126_4BD8(void*, short);
void* fn_126_4C34(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_49A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x250, -1);
        fn_126_4A58(storage + 0x214, -1);
        fn_27_21038(storage + 0x204, -1);
        fn_126_4AC4(storage + 0x1E4, -1);
        fn_126_4B20(storage + 0x1C4, -1);
        fn_126_4B7C(storage + 0x160, -1);
        fn_126_4BD8(storage + 0xC4, -1);
        fn_126_4C34(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
