void operator delete(void*);
extern "C" {
void* fn_101_3B0C(void*, short);
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_572C(void*, short);
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_5BD4(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_3E14(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_5C30(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_4674(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_5C9C(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_4B48(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_101_5994(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        // Preserve the nested aggregate/base null guards and destruction order.
        if (members + 4 != 0) {
            if (members + 0x1F54 != 0) {
                if (members + 0x1F54 != 0) {
                    int baseDeleting = 0;
                    fn_101_3B0C(members + 0x1F54, static_cast<short>(baseDeleting));
                }
            }
            if (members + 4 != 0) {
                void* firstMember = members + 0x1F0C;
                short memberDeleting = -1;
                fn_101_3B4C(firstMember, memberDeleting);
                fn_27_1DBB60(members + 0x1ED4, memberDeleting);
                if (members + 0xD0 != 0) {
                    fn_101_572C(members + 0x1924, memberDeleting);
                    if (members + 0xD0 != 0) {
                        fn_101_3C14(members + 0x1908, memberDeleting);
                        fn_101_3C70(members + 0x18C8, memberDeleting);
                        fn_101_3CCC(members + 0x18B0, memberDeleting);
                        fn_101_3D28(members + 0x1714, memberDeleting);
                        fn_101_3DB4(members + 0x16B4, memberDeleting);
                        fn_101_3EB0(members + 0x1600, memberDeleting);
                        if (members + 0x1438 != 0) {
                            fn_101_4090(members + 0x1550, memberDeleting);
                            fn_101_4114(members + 0x153C, memberDeleting);
                            fn_101_5BD4(members + 0x152C, memberDeleting);
                            fn_101_4174(members + 0x1488, memberDeleting);
                            if (members + 0x1448 != 0) {
                                fn_101_3E14(members + 0x1464, memberDeleting);
                            }
                            void* eventBase = members + 0x1438;
                            int baseDeleting = -1;
                            fn_27_C74E8(eventBase, static_cast<short>(baseDeleting));
                        }
                        void* nextMember = members + 0x1394;
                        memberDeleting = -1;
                        fn_101_429C(nextMember, memberDeleting);
                        fn_101_43D0(members + 0x1360, memberDeleting);
                        fn_101_4490(members + 0x1348, memberDeleting);
                        fn_101_5C30(members + 0x11B0, memberDeleting);
                        fn_101_4558(members + 0x1148, memberDeleting);
                        fn_101_45B8(members + 0x113C, memberDeleting);
                        fn_101_4618(members + 0x1114, memberDeleting);
                        fn_101_4674(members + 0xF44, memberDeleting);
                        fn_101_46F8(members + 0xEE0, memberDeleting);
                        fn_101_47C4(members + 0xEA4, memberDeleting);
                        fn_101_488C(members + 0xDEC, memberDeleting);
                        fn_101_5C9C(members + 0xBE0, memberDeleting);
                        fn_101_4988(members + 0xA00, memberDeleting);
                        fn_101_49F4(members + 0x9D0, memberDeleting);
                        fn_101_4AAC(members + 0x9C0, memberDeleting);
                        fn_101_4AEC(members + 0x9A8, memberDeleting);
                        __dt__16soModuleAccesserFv(members + 0x8C8, memberDeleting);
                        fn_101_4B48(members + 0xD0, memberDeleting);
                    }
                }
                void* aggregateBase = members + 4;
                int baseDeleting = 0;
                fn_27_1D81C8(aggregateBase, static_cast<short>(baseDeleting));
            }
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
