void operator delete(void*);
extern "C" void* fn_118_3B70(void*, short);
extern "C" void* fn_118_3D48(void*, short);
extern "C" void* fn_118_3DCC(void*, short);
extern "C" void* fn_118_134C0(void*, short);
extern "C" void* fn_118_3E2C(void*, short);
extern "C" void* fn_118_3F54(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CCF74(void*, short);
extern "C" void* fn_118_43B4(void*, short);
extern "C" void* fn_118_4614(void*, short);

extern "C" void* fn_118_133C4(void* object, short deleting) {
    if (object != 0) {
        fn_118_3B70(static_cast<unsigned char*>(object) + 0x1C, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_13424(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3D48(storage + 0x110, -1);
        fn_118_3DCC(storage + 0xFC, -1);
        fn_118_134C0(storage + 0xEC, -1);
        fn_118_3E2C(storage + 0x48, -1);
        fn_118_3F54(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_134C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2D10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_1351C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x244, -1);
        fn_27_82AD4(storage + 0x240, -1);
        fn_27_4CAA0(storage + 0x1BC, -1);
        fn_27_CCF74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_135A0(void* object, short deleting) {
    if (object != 0) {
        fn_118_43B4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_135FC(void* object, short deleting) {
    if (object != 0) {
        fn_118_4614(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
