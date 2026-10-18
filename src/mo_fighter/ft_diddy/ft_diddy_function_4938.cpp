#pragma force_active on
extern "C" void* fn_115_3AC8(void* object, short deleting);
extern "C" void* fn_115_3B4C(void* object, short deleting);
extern "C" void* fn_115_49D4(void* object, short deleting);
extern "C" void* fn_115_4A30(void* object, short deleting);
extern "C" void* fn_115_5448(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_4938(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3AC8(storage + 0xe7c, -1);
        fn_115_3B4C(storage + 0xe68, -1);
        fn_115_49D4(storage + 0x9a0, -1);
        fn_115_4A30(storage + 0x12c, -1);
        fn_115_5448(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
