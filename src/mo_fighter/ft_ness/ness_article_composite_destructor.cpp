void operator delete(void*);
extern "C" {
void* fn_101_3A70(void*, short);
void* fn_101_3B0C(void*, short);
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_3BA8(void*, short);
void* fn_101_23D8(void*, short);
void* fn_101_2474(void*, short);
void* fn_101_24B4(void*, short);
void* fn_27_C7770(void*, short);
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_27_1A301C(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_51CC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_44EC(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_27_5CC1C(void*, short);
void* fn_27_D3080(void*, short);
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CC654(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_19CCC8(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_4820(void*, short);
void* fn_101_488C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_101_4900(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_4B48(void*, short);
void* fn_27_1D81C8(void*, short);
}

// These embedded aggregates retain their own null guards when inlined.
static inline void destroyCommandModules(unsigned char* object) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_3BA8(object + 0x4B0, memberDeleting);
        if (object + 0x384 != 0) {
            fn_101_23D8(object + 0x460, memberDeleting);
            fn_101_2474(object + 0x444, memberDeleting);
            fn_101_24B4(object + 0x398, memberDeleting);
            if (object + 0x384 != 0) {
                fn_27_C7770(object + 0x384, memberDeleting);
            }
        }
        if (object + 0x258 != 0) {
            fn_101_23D8(object + 0x334, memberDeleting);
            fn_101_2474(object + 0x318, memberDeleting);
            fn_101_24B4(object + 0x26C, memberDeleting);
            if (object + 0x258 != 0) {
                fn_27_C7770(object + 0x258, memberDeleting);
            }
        }
        if (object + 0x12C != 0) {
            fn_101_23D8(object + 0x208, memberDeleting);
            fn_101_2474(object + 0x1EC, memberDeleting);
            fn_101_24B4(object + 0x140, memberDeleting);
            if (object + 0x12C != 0) {
                fn_27_C7770(object + 0x12C, memberDeleting);
            }
        }
        if (object != 0) {
            fn_101_23D8(object + 0xDC, memberDeleting);
            fn_101_2474(object + 0xC0, memberDeleting);
            fn_101_24B4(object + 0x14, memberDeleting);
            if (object != 0) {
                fn_27_C7770(object, memberDeleting);
            }
        }
    }
}

static inline void destroyModuleMembers(unsigned char* object) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_3C14(object + 0x1C98, memberDeleting);
        fn_101_3C70(object + 0x1C58, memberDeleting);
        fn_101_3CCC(object + 0x1C40, memberDeleting);
        fn_101_3D28(object + 0x1AA4, memberDeleting);
        fn_101_3DB4(object + 0x1A44, memberDeleting);
        fn_101_3EB0(object + 0x1990, memberDeleting);
        if (object + 0x17CC != 0) {
            fn_101_4090(object + 0x18E0, memberDeleting);
            fn_101_4114(object + 0x18CC, memberDeleting);
            if (object + 0x18B8 != 0) {
                fn_27_1A301C(object + 0x18B8, memberDeleting);
            }
            fn_101_4174(object + 0x1814, memberDeleting);
            fn_101_51CC(object + 0x17DC, memberDeleting);
            fn_27_C74E8(object + 0x17CC, memberDeleting);
        }
        fn_101_429C(object + 0x1728, memberDeleting);
        fn_101_43D0(object + 0x16F4, memberDeleting);
        fn_101_4490(object + 0x16DC, memberDeleting);
        fn_101_44EC(object + 0x1578, memberDeleting);
        fn_101_4558(object + 0x1510, memberDeleting);
        fn_101_45B8(object + 0x1504, memberDeleting);
        fn_101_4618(object + 0x14DC, memberDeleting);
        if (object + 0x1380 != 0) {
            fn_27_5CC1C(object + 0x142C, memberDeleting);
            if (object + 0x1380 != 0) {
                fn_27_D3080(object + 0x1380, memberDeleting);
            }
        }
        if (object + 0x116C != 0) {
            __dt__24soCollisionHitModuleImplFv(object + 0x1310, memberDeleting);
            fn_27_CC984(object + 0x12CC, memberDeleting);
            fn_27_4CAA0(object + 0x1248, memberDeleting);
            fn_27_CC654(object + 0x116C, memberDeleting);
        }
        if (object + 0xF18 != 0) {
            __dt__27soCollisionAttackModuleImplFv(object + 0x10CC, memberDeleting);
            fn_27_82AD4(object + 0x10C8, memberDeleting);
            fn_27_4CAA0(object + 0x1044, memberDeleting);
            fn_27_19CCC8(object + 0xF18, memberDeleting);
        }
        fn_101_46F8(object + 0xEB4, memberDeleting);
        fn_101_47C4(object + 0xE78, memberDeleting);
        fn_101_4820(object + 0xDD0, memberDeleting);
        fn_101_488C(object + 0xD1C, memberDeleting);
        if (object + 0xB10 != 0) {
            fn_27_13C90(object + 0xBAC, memberDeleting);
            fn_27_21038(object + 0xB98, memberDeleting);
            fn_101_4900(object + 0xB10, memberDeleting);
        }
        fn_101_4988(object + 0x930, memberDeleting);
        fn_101_49F4(object + 0x900, memberDeleting);
        fn_101_4AAC(object + 0x8F0, memberDeleting);
        fn_101_4AEC(object + 0x8D8, memberDeleting);
        __dt__16soModuleAccesserFv(object + 0x7F8, memberDeleting);
        fn_101_4B48(object, memberDeleting);
    }
}

static inline void destroyModuleAggregate(unsigned char* object) {
    if (object != 0) {
        destroyCommandModules(object + 0x1CB4);
        destroyModuleMembers(object);
    }
}

static inline void destroyArticleBase(unsigned char* object) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_3B4C(object + 0x2368, memberDeleting);
        fn_27_1DBB60(object + 0x2330, memberDeleting);
        destroyModuleAggregate(object + 0xCC);
        fn_27_1D81C8(object, static_cast<short>(0));
    }
}

static inline void destroySupport(unsigned char* object) {
    if (object != 0) {
        if (object != 0) {
            fn_101_3B0C(object, static_cast<short>(0));
        }
    }
}

extern "C" void* fn_101_4DBC(unsigned char* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_3A70(object + 0x23F4, memberDeleting);
        destroySupport(object + 0x23B0);
        destroyArticleBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
