#pragma force_active on
extern "C" void* fn_109_3C8C(void*, short);
extern "C" void* fn_109_3D10(void*, short);
extern "C" void* fn_109_10944(void*, short);
extern "C" void* fn_109_109A0(void*, short);
extern "C" void* fn_109_10AD4(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_108A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_3C8C(storage + 0x114, -1);
        fn_109_3D10(storage + 0x100, -1);
        fn_109_10944(storage + 0xEC, -1);
        fn_109_109A0(storage + 0x48, -1);
        fn_109_10AD4(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
