void operator delete(void*);
extern "C" {
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_15260(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_51CC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A301C(void*, short);
void* fn_27_5CC1C(void*, short);
void* fn_27_D3080(void*, short);
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CC654(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_19CCC8(void*, short);
}

struct NessCompositeBase {
    inline ~NessCompositeBase() {
        fn_27_D3080(this, static_cast<short>(-1));
    }
};

extern "C" void* fn_101_151C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_4090(members + 0x114, memberDeleting);
        fn_101_4114(members + 0x100, memberDeleting);
        fn_101_15260(members + 0xEC, memberDeleting);
        fn_101_4174(members + 0x48, memberDeleting);
        fn_101_51CC(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma dont_inline on
extern "C" void* fn_101_15260(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A301C(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset

extern "C" void* fn_101_152BC(void* object, short deleting) {
    if (object != 0) {
        fn_27_5CC1C(static_cast<unsigned char*>(object) + 0xAC, static_cast<short>(-1));
        static_cast<NessCompositeBase*>(object)->~NessCompositeBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_101_15330(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__24soCollisionHitModuleImplFv(members + 0x1A4, memberDeleting);
        fn_27_CC984(members + 0x160, memberDeleting);
        fn_27_4CAA0(members + 0xDC, memberDeleting);
        fn_27_CC654(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_101_153B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__27soCollisionAttackModuleImplFv(members + 0x1B4, memberDeleting);
        fn_27_82AD4(members + 0x1B0, memberDeleting);
        fn_27_4CAA0(members + 0x12C, memberDeleting);
        fn_27_19CCC8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
