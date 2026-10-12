void operator delete(void*);

extern "C" {
void* fn_117_2BF0(void*, short);
void* fn_117_2C4C(void*, short);
void* fn_117_2CA8(void*, short);
void* fn_117_2D04(void*, short);
void* fn_117_2D60(void*, short);
void* fn_117_2DBC(void*, short);
void* fn_117_2E98(void*, short);
void* fn_117_2EF4(void*, short);
void* fn_117_2F50(void*, short);
void* fn_117_2FC4(void*, short);
void* fn_117_305C(void*, short);
void* fn_117_30B8(void*, short);
void* fn_117_3208(void*, short);
void* fn_117_4468(void*, short);
void* fn_117_4564(void*, short);
void* fn_117_46B0(void*, short);
void* fn_117_53A4(void*, short);
void* fn_117_54DC(void*, short);
void* fn_117_5538(void*, short);
void* fn_117_55AC(void*, short);
void* fn_117_5688(void*, short);
void* fn_117_56E4(void*, short);
void* fn_117_5750(void*, short);
void* fn_117_57FC(void*, short);
void* fn_117_5870(void*, short);
void* fn_117_58CC(void*, short);
void* fn_117_5928(void*, short);
void* fn_117_5984(void*, short);
void* fn_117_59E0(void*, short);
void* fn_117_5A54(void*, short);
void* fn_117_5ACC(void*, short);
void* fn_117_5B38(void*, short);
void* fn_117_5BC8(void*, short);
void* fn_117_5C58(void*, short);
void* fn_117_5CDC(void*, short);
void* fn_117_5D60(void*, short);
void* fn_117_5E74(void*, short);
void* fn_117_5ED0(void*, short);
void* fn_117_5F3C(void*, short);
void* fn_117_5FB0(void*, short);
void* fn_117_6374(void*, short);
void* fn_117_6448(void*, short);
void* fn_117_6500(void*, short);
void* fn_117_655C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_117_65B8(void*, short);
}

extern "C" void* fn_117_2944(void* object, short deleting) {
    if (object != 0) {
        // Destroy embedded modules in reverse construction order. Their storage
        // belongs to this aggregate and is released only by its deleting form.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_2BF0(members + 0x457F4, memberDeleting);
        fn_117_2C4C(members + 0x457B8, memberDeleting);
        fn_117_2CA8(members + 0x45750, memberDeleting);
        fn_117_2D04(members + 0x45704, memberDeleting);
        fn_117_2D60(members + 0x455B0, memberDeleting);
        fn_117_2DBC(members + 0x45450, memberDeleting);
        fn_117_2E98(members + 0x45408, memberDeleting);
        fn_117_2EF4(members + 0x45388, memberDeleting);
        fn_117_2F50(members + 0x452C4, memberDeleting);
        fn_117_2FC4(members + 0x44F08, memberDeleting);
        fn_117_305C(members + 0x44ED8, memberDeleting);
        fn_117_30B8(members + 0x44D34, memberDeleting);
        fn_117_3208(members + 0x5D34, memberDeleting);
        fn_117_4468(members + 0x5B50, memberDeleting);
        fn_117_4564(members + 0x5848, memberDeleting);
        fn_117_46B0(members + 0x493C, memberDeleting);
        fn_117_53A4(members + 0x4848, memberDeleting);
        fn_117_54DC(members + 0x4814, memberDeleting);
        fn_117_5538(members + 0x47A0, memberDeleting);
        fn_117_55AC(members + 0x407C, memberDeleting);
        fn_117_5688(members + 0x404C, memberDeleting);
        fn_117_56E4(members + 0x3E80, memberDeleting);
        fn_117_5750(members + 0x3E10, memberDeleting);
        fn_117_57FC(members + 0x3D78, memberDeleting);
        fn_117_5870(members + 0x3D40, memberDeleting);
        fn_117_58CC(members + 0x3D1C, memberDeleting);
        fn_117_5928(members + 0x3CE8, memberDeleting);
        fn_117_5984(members + 0x3C84, memberDeleting);
        fn_117_59E0(members + 0x3AD4, memberDeleting);
        fn_117_5A54(members + 0x38DC, memberDeleting);
        fn_117_5ACC(members + 0x367C, memberDeleting);
        fn_117_5B38(members + 0x2C10, memberDeleting);
        fn_117_5BC8(members + 0x29F8, memberDeleting);
        fn_117_5C58(members + 0x209C, memberDeleting);
        fn_117_5CDC(members + 0x19E0, memberDeleting);
        fn_117_5D60(members + 0x196C, memberDeleting);
        fn_117_5E74(members + 0x1930, memberDeleting);
        fn_117_5ED0(members + 0x1888, memberDeleting);
        fn_117_5F3C(members + 0x17D4, memberDeleting);
        fn_117_5FB0(members + 0x1440, memberDeleting);
        fn_117_6374(members + 0x1180, memberDeleting);
        fn_117_6448(members + 0x115C, memberDeleting);
        fn_117_6500(members + 0xAC8, memberDeleting);
        fn_117_655C(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_117_65B8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
