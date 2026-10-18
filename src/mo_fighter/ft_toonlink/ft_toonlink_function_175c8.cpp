#pragma force_active on
extern "C" {
void* fn_121_4728(void* object, short deleting);
void* fn_121_46C8(void* object, short deleting);
void* fn_121_17664(void* object, short deleting);
void* fn_121_12F38(void* object, short deleting);
void* fn_121_176C0(void* object, short deleting);
void* fn_27_C74E8(void* object, short deleting);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_121_175C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_4728(storage + 0x138, -1);
        fn_121_46C8(storage + 0x124, -1);
        fn_121_17664(storage + 0xf4, -1);
        fn_121_12F38(storage + 0x50, -1);
        fn_121_176C0(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
