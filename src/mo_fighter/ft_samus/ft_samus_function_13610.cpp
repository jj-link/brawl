#pragma force_active on
extern "C" void* fn_94_20CC(void*, short);
extern "C" void* fn_94_2290(void*, short);
extern "C" void* fn_94_136E8(void*, short);
extern "C" void* fn_94_13774(void*, short);
extern "C" void* fn_94_13800(void*, short);
extern "C" void* fn_94_1388C(void*, short);
extern "C" void* fn_94_13918(void*, short);
extern "C" void* fn_94_139A4(void*, short);
extern "C" void* fn_94_13A30(void*, short);
extern "C" void* fn_94_13ABC(void*, short);
extern "C" void* fn_94_13B48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_13610(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_20CC(storage + 0x14C0, -1);
        fn_94_2290(storage + 0x139C, -1);
        fn_94_136E8(storage + 0x1270, -1);
        fn_94_13774(storage + 0x1144, -1);
        fn_94_13800(storage + 0x1018, -1);
        fn_94_1388C(storage + 0xEEC, -1);
        fn_94_13918(storage + 0xDC0, -1);
        fn_94_139A4(storage + 0xC94, -1);
        fn_94_13A30(storage + 0xB68, -1);
        fn_94_13ABC(storage + 0xA3C, -1);
        fn_94_13B48(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
