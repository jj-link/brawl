#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_114_3A60(void*, short);
void* fn_114_3AA0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_114_5680(void*, short);
void* fn_114_3B68(void*, short);
void* fn_114_3BC4(void*, short);
void* fn_114_3C20(void*, short);
void* fn_114_3C7C(void*, short);
void* fn_114_3D08(void*, short);
void* fn_114_3E04(void*, short);
void* fn_114_3FE4(void*, short);
void* fn_114_4068(void*, short);
void* fn_114_5A38(void*, short);
void* fn_114_40C8(void*, short);
void* fn_114_3D68(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_114_41F0(void*, short);
void* fn_114_4324(void*, short);
void* fn_114_43E4(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_199E3C(void*, short);
void* fn_114_44AC(void*, short);
void* fn_114_450C(void*, short);
void* fn_114_456C(void*, short);
void* fn_114_45C8(void*, short);
void* fn_114_464C(void*, short);
void* fn_114_4718(void*, short);
void* fn_114_47E0(void*, short);
void* fn_114_5A94(void*, short);
void* fn_114_48DC(void*, short);
void* fn_114_4948(void*, short);
void* fn_114_4A00(void*, short);
void* fn_114_4A40(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_114_4A9C(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_114_57E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 4 != 0) {
            if (members + 0x1F54 != 0) {
                if (members + 0x1F54 != 0) {
                    int baseDeleting = 0;
                    fn_114_3A60(members + 0x1F54, static_cast<short>(baseDeleting));
                }
            }
            if (members + 4 != 0) {
                void* firstMember = members + 0x1F0C;
                short memberDeleting = -1;
                fn_114_3AA0(firstMember, memberDeleting);
                fn_27_1DBB60(members + 0x1ED4, memberDeleting);
                if (members + 0xD0 != 0) {
                    fn_114_5680(members + 0x1924, memberDeleting);
                    if (members + 0xD0 != 0) {
                        fn_114_3B68(members + 0x1908, memberDeleting);
                        fn_114_3BC4(members + 0x18C8, memberDeleting);
                        fn_114_3C20(members + 0x18B0, memberDeleting);
                        fn_114_3C7C(members + 0x1714, memberDeleting);
                        fn_114_3D08(members + 0x16B4, memberDeleting);
                        fn_114_3E04(members + 0x1600, memberDeleting);
                        if (members + 0x1438 != 0) {
                            fn_114_3FE4(members + 0x1550, memberDeleting);
                            fn_114_4068(members + 0x153C, memberDeleting);
                            fn_114_5A38(members + 0x152C, memberDeleting);
                            fn_114_40C8(members + 0x1488, memberDeleting);
                            if (members + 0x1448 != 0) {
                                fn_114_3D68(members + 0x1464, memberDeleting);
                            }
                            void* eventBase = members + 0x1438;
                            int baseDeleting = -1;
                            fn_27_C74E8(eventBase, static_cast<short>(baseDeleting));
                        }
                        void* nextMember = members + 0x1394;
                        memberDeleting = -1;
                        fn_114_41F0(nextMember, memberDeleting);
                        fn_114_4324(members + 0x1360, memberDeleting);
                        fn_114_43E4(members + 0x1348, memberDeleting);
                        if (members + 0x11B0 != 0) {
                            fn_27_6A3D8(members + 0x12F4, memberDeleting);
                            fn_27_199E3C(members + 0x11B0, memberDeleting);
                        }
                        void* laterMember = members + 0x1148;
                        memberDeleting = -1;
                        fn_114_44AC(laterMember, memberDeleting);
                        fn_114_450C(members + 0x113C, memberDeleting);
                        fn_114_456C(members + 0x1114, memberDeleting);
                        fn_114_45C8(members + 0xF44, memberDeleting);
                        fn_114_464C(members + 0xEE0, memberDeleting);
                        fn_114_4718(members + 0xEA4, memberDeleting);
                        fn_114_47E0(members + 0xDEC, memberDeleting);
                        fn_114_5A94(members + 0xBE0, memberDeleting);
                        fn_114_48DC(members + 0xA00, memberDeleting);
                        fn_114_4948(members + 0x9D0, memberDeleting);
                        fn_114_4A00(members + 0x9C0, memberDeleting);
                        fn_114_4A40(members + 0x9A8, memberDeleting);
                        __dt__16soModuleAccesserFv(members + 0x8C8, memberDeleting);
                        fn_114_4A9C(members + 0xD0, memberDeleting);
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
