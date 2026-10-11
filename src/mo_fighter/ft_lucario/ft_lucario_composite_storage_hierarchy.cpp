void operator delete(void*);
extern "C" void* fn_118_4A6C(void*, short);
extern "C" void* fn_118_3888(void*, short);
extern "C" void* fn_118_38C8(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_118_3964(void*, short);
extern "C" void* fn_118_21BC(void*, short);
extern "C" void* fn_118_2258(void*, short);
extern "C" void* fn_118_2298(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void* fn_118_39D0(void*, short);
extern "C" void* fn_118_3A2C(void*, short);
extern "C" void* fn_118_3A88(void*, short);
extern "C" void* fn_118_3AE4(void*, short);
extern "C" void* fn_118_3B70(void*, short);
extern "C" void* fn_118_3C0C(void*, short);
extern "C" void* fn_118_3D48(void*, short);
extern "C" void* fn_118_3DCC(void*, short);
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void* fn_118_3E2C(void*, short);
extern "C" void* fn_118_3F54(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_118_3FB4(void*, short);
extern "C" void* fn_118_40E8(void*, short);
extern "C" void* fn_118_4144(void*, short);
extern "C" void* fn_118_41A0(void*, short);
extern "C" void* fn_118_420C(void*, short);
extern "C" void* fn_118_426C(void*, short);
extern "C" void* fn_118_42CC(void*, short);
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CCF74(void*, short);
extern "C" void* fn_118_4328(void*, short);
extern "C" void* fn_118_43F4(void*, short);
extern "C" void* fn_118_44BC(void*, short);
extern "C" void* fn_118_4530(void*, short);
extern "C" void* fn_118_459C(void*, short);
extern "C" void* fn_118_4654(void*, short);
extern "C" void* fn_118_4694(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_118_46F0(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_118_4A0C(void* object, short deleting) {
    if (object != 0) {
        fn_118_4A6C(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

// Keep the nested guards from embedded destructor expansion and teardown order.
extern "C" void* fn_118_4A6C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x1E10 != 0) {
            if (storage + 0x1E10 != 0) {
                fn_118_3888(storage + 0x1E10, 0);
            }
        }
        if (object != 0) {
            fn_118_38C8(storage + 0x1DC8, -1);
            fn_27_1DBB60(storage + 0x1D90, -1);
            if (storage + 0xCC != 0) {
                if (storage + 0x17E0 != 0) {
                    fn_118_3964(storage + 0x1C90, -1);
                    if (storage + 0x1B64 != 0) {
                        fn_118_21BC(storage + 0x1C40, -1);
                        fn_118_2258(storage + 0x1C24, -1);
                        fn_118_2298(storage + 0x1B78, -1);
                        if (storage + 0x1B64 != 0) {
                            fn_27_C7770(storage + 0x1B64, -1);
                        }
                    }
                    if (storage + 0x1A38 != 0) {
                        fn_118_21BC(storage + 0x1B14, -1);
                        fn_118_2258(storage + 0x1AF8, -1);
                        fn_118_2298(storage + 0x1A4C, -1);
                        if (storage + 0x1A38 != 0) {
                            fn_27_C7770(storage + 0x1A38, -1);
                        }
                    }
                    if (storage + 0x190C != 0) {
                        fn_118_21BC(storage + 0x19E8, -1);
                        fn_118_2258(storage + 0x19CC, -1);
                        fn_118_2298(storage + 0x1920, -1);
                        if (storage + 0x190C != 0) {
                            fn_27_C7770(storage + 0x190C, -1);
                        }
                    }
                    if (storage + 0x17E0 != 0) {
                        fn_118_21BC(storage + 0x18BC, -1);
                        fn_118_2258(storage + 0x18A0, -1);
                        fn_118_2298(storage + 0x17F4, -1);
                        if (storage + 0x17E0 != 0) {
                            fn_27_C7770(storage + 0x17E0, -1);
                        }
                    }
                }
                if (storage + 0xCC != 0) {
                    fn_118_39D0(storage + 0x17C4, -1);
                    fn_118_3A2C(storage + 0x1784, -1);
                    fn_118_3A88(storage + 0x176C, -1);
                    fn_118_3AE4(storage + 0x15D0, -1);
                    if (storage + 0x158C != 0) {
                        fn_118_3B70(storage + 0x15A8, -1);
                    }
                    fn_118_3C0C(storage + 0x14D8, -1);
                    if (storage + 0x1318 != 0) {
                        fn_118_3D48(storage + 0x1428, -1);
                        fn_118_3DCC(storage + 0x1414, -1);
                        if (storage + 0x1404 != 0) {
                            fn_27_1A2D10(storage + 0x1404, -1);
                        }
                        fn_118_3E2C(storage + 0x1360, -1);
                        fn_118_3F54(storage + 0x1328, -1);
                        fn_27_C74E8(storage + 0x1318, -1);
                    }
                    fn_118_3FB4(storage + 0x1274, -1);
                    fn_118_40E8(storage + 0x1240, -1);
                    fn_118_4144(storage + 0x1228, -1);
                    fn_118_41A0(storage + 0x10C4, -1);
                    fn_118_420C(storage + 0x105C, -1);
                    fn_118_426C(storage + 0x1050, -1);
                    fn_118_42CC(storage + 0x1028, -1);
                    if (storage + 0xD38 != 0) {
                        __dt__27soCollisionAttackModuleImplFv(storage + 0xF7C, -1);
                        fn_27_82AD4(storage + 0xF78, -1);
                        fn_27_4CAA0(storage + 0xEF4, -1);
                        fn_27_CCF74(storage + 0xD38, -1);
                    }
                    fn_118_4328(storage + 0xCD4, -1);
                    fn_118_43F4(storage + 0xC98, -1);
                    fn_118_44BC(storage + 0xBE0, -1);
                    fn_118_4530(storage + 0x9FC, -1);
                    fn_118_459C(storage + 0x9CC, -1);
                    fn_118_4654(storage + 0x9BC, -1);
                    fn_118_4694(storage + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(storage + 0x8C4, -1);
                    fn_118_46F0(storage + 0xCC, -1);
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
