void operator delete(void*);
extern "C" {
void* fn_100_37BC(void*, short);
void* fn_100_37FC(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_100_3898(void*, short);
void* fn_100_2158(void*, short);
void* fn_100_21F4(void*, short);
void* fn_100_2234(void*, short);
void* fn_27_C7770(void*, short);
void* fn_100_3904(void*, short);
void* fn_100_3960(void*, short);
void* fn_27_BED74(void*, short);
void* fn_100_2DF4(void*, short);
void* fn_100_39BC(void*, short);
void* fn_100_3A48(void*, short);
void* fn_100_3B44(void*, short);
void* fn_100_3C80(void*, short);
void* fn_100_3D04(void*, short);
void* fn_27_1A4778(void*, short);
void* fn_100_3D64(void*, short);
void* fn_100_3E8C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_100_3EEC(void*, short);
void* fn_100_4020(void*, short);
void* fn_100_407C(void*, short);
void* fn_100_40D8(void*, short);
void* fn_100_4144(void*, short);
void* fn_100_41A4(void*, short);
void* fn_100_4204(void*, short);
void* fn_100_4260(void*, short);
void* fn_100_42E4(void*, short);
void* fn_100_43B0(void*, short);
void* fn_100_440C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_100_4480(void*, short);
void* fn_100_44DC(void*, short);
void* fn_100_4564(void*, short);
void* fn_100_45D0(void*, short);
void* fn_100_4688(void*, short);
void* fn_100_46C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_100_4724(void*, short);
void* fn_27_1D81C8(void*, short);
}

namespace {
// Lifetime overlays preserve the guards of the inlined base destructors.
struct SupportLifetime {
    inline ~SupportLifetime() { fn_100_37BC(this, static_cast<short>(0)); }
};
template <int Instance>
struct ParameterBaseLifetime {
    inline ~ParameterBaseLifetime() { fn_27_C7770(this, static_cast<short>(-1)); }
};
struct KineticLifetime {
    inline ~KineticLifetime() { fn_27_BED74(this, static_cast<short>(-1)); }
};
struct CompositeSupportLifetime {
    inline ~CompositeSupportLifetime() { fn_27_1A4778(this, static_cast<short>(-1)); }
};
struct HierarchyLifetime {
    inline ~HierarchyLifetime() {
        unsigned char* members = reinterpret_cast<unsigned char*>(this);
        short memberDeleting = -1;
        fn_100_37FC(members + 0x209C, memberDeleting);
        fn_27_1DBB60(members + 0x2064, memberDeleting);
        // Destroy the embedded module layers in reverse construction order.
        if (members + 0xCC != 0) {
            if (members + 0x1AB4 != 0) {
                fn_100_3898(members + 0x1F64, memberDeleting);
                if (members + 0x1E38 != 0) {
                    fn_100_2158(members + 0x1F14, memberDeleting);
                    fn_100_21F4(members + 0x1EF8, memberDeleting);
                    fn_100_2234(members + 0x1E4C, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<3>*>(members + 0x1E38)->~ParameterBaseLifetime();
                }
                if (members + 0x1D0C != 0) {
                    fn_100_2158(members + 0x1DE8, memberDeleting);
                    fn_100_21F4(members + 0x1DCC, memberDeleting);
                    fn_100_2234(members + 0x1D20, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<2>*>(members + 0x1D0C)->~ParameterBaseLifetime();
                }
                if (members + 0x1BE0 != 0) {
                    fn_100_2158(members + 0x1CBC, memberDeleting);
                    fn_100_21F4(members + 0x1CA0, memberDeleting);
                    fn_100_2234(members + 0x1BF4, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<1>*>(members + 0x1BE0)->~ParameterBaseLifetime();
                }
                if (members + 0x1AB4 != 0) {
                    fn_100_2158(members + 0x1B90, memberDeleting);
                    fn_100_21F4(members + 0x1B74, memberDeleting);
                    fn_100_2234(members + 0x1AC8, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<0>*>(members + 0x1AB4)->~ParameterBaseLifetime();
                }
            }
            if (members + 0xCC != 0) {
                fn_100_3904(members + 0x1A70, memberDeleting);
                fn_100_3960(members + 0x1A58, memberDeleting);
                reinterpret_cast<KineticLifetime*>(members + 0x1900)->~KineticLifetime();
                fn_100_2DF4(members + 0x18B4, memberDeleting);
                fn_100_39BC(members + 0x171C, memberDeleting);
                fn_100_3A48(members + 0x16BC, memberDeleting);
                fn_100_3B44(members + 0x1608, memberDeleting);
                if (members + 0x143C != 0) {
                    fn_100_3C80(members + 0x1558, memberDeleting);
                    fn_100_3D04(members + 0x1544, memberDeleting);
                    reinterpret_cast<CompositeSupportLifetime*>(members + 0x1528)->~CompositeSupportLifetime();
                    fn_100_3D64(members + 0x1484, memberDeleting);
                    fn_100_3E8C(members + 0x144C, memberDeleting);
                    fn_27_C74E8(members + 0x143C, static_cast<short>(-1));
                }
                fn_100_3EEC(members + 0x1398, memberDeleting);
                fn_100_4020(members + 0x1364, memberDeleting);
                fn_100_407C(members + 0x134C, memberDeleting);
                fn_100_40D8(members + 0x11E8, memberDeleting);
                fn_100_4144(members + 0x1180, memberDeleting);
                fn_100_41A4(members + 0x1174, memberDeleting);
                fn_100_4204(members + 0x114C, memberDeleting);
                fn_100_4260(members + 0xF7C, memberDeleting);
                fn_100_42E4(members + 0xF18, memberDeleting);
                fn_100_43B0(members + 0xEDC, memberDeleting);
                fn_100_440C(members + 0xE24, memberDeleting);
                if (members + 0xBDC != 0) {
                    fn_27_13C90(members + 0xCB4, memberDeleting);
                    fn_27_21038(members + 0xCA0, memberDeleting);
                    fn_100_4480(members + 0xC64, memberDeleting);
                    fn_100_44DC(members + 0xBDC, memberDeleting);
                }
                fn_100_4564(members + 0x9FC, memberDeleting);
                fn_100_45D0(members + 0x9CC, memberDeleting);
                fn_100_4688(members + 0x9BC, memberDeleting);
                fn_100_46C8(members + 0x9A4, memberDeleting);
                __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                fn_100_4724(members + 0xCC, memberDeleting);
            }
        }
        fn_27_1D81C8(this, static_cast<short>(0));
    }
};
}

extern "C" void* fn_100_3440(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        reinterpret_cast<SupportLifetime*>(members + 0x20E4)->~SupportLifetime();
        reinterpret_cast<HierarchyLifetime*>(object)->~HierarchyLifetime();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
