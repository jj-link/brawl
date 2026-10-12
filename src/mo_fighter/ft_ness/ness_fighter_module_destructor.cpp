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
void* fn_27_1A4778(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_3E14(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_442C(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_44EC(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_4674(void*, short);
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

namespace {
// These lifetime overlays retain the null checks of the inlined base destructors.
struct SupportBaseLifetime {
    inline ~SupportBaseLifetime() { fn_101_3B0C(this, static_cast<short>(0)); }
};
struct SupportLifetime {
    inline ~SupportLifetime() { reinterpret_cast<SupportBaseLifetime*>(this)->~SupportBaseLifetime(); }
};
template <int Instance>
struct ParameterBaseLifetime {
    inline ~ParameterBaseLifetime() { fn_27_C7770(this, static_cast<short>(-1)); }
};
struct CompositeSupportLifetime {
    inline ~CompositeSupportLifetime() { fn_27_1A4778(this, static_cast<short>(-1)); }
};
struct HierarchyLifetime {
    inline ~HierarchyLifetime() {
        unsigned char* members = reinterpret_cast<unsigned char*>(this);
        short memberDeleting = -1;
        fn_101_3B4C(members + 0x1FA0, memberDeleting);
        fn_27_1DBB60(members + 0x1F68, memberDeleting);
        // The nested module layers are destroyed in reverse construction order.
        if (members + 0xCC != 0) {
            if (members + 0x19B8 != 0) {
                fn_101_3BA8(members + 0x1E68, memberDeleting);
                if (members + 0x1D3C != 0) {
                    fn_101_23D8(members + 0x1E18, memberDeleting);
                    fn_101_2474(members + 0x1DFC, memberDeleting);
                    fn_101_24B4(members + 0x1D50, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<3>*>(members + 0x1D3C)->~ParameterBaseLifetime();
                }
                if (members + 0x1C10 != 0) {
                    fn_101_23D8(members + 0x1CEC, memberDeleting);
                    fn_101_2474(members + 0x1CD0, memberDeleting);
                    fn_101_24B4(members + 0x1C24, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<2>*>(members + 0x1C10)->~ParameterBaseLifetime();
                }
                if (members + 0x1AE4 != 0) {
                    fn_101_23D8(members + 0x1BC0, memberDeleting);
                    fn_101_2474(members + 0x1BA4, memberDeleting);
                    fn_101_24B4(members + 0x1AF8, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<1>*>(members + 0x1AE4)->~ParameterBaseLifetime();
                }
                if (members + 0x19B8 != 0) {
                    fn_101_23D8(members + 0x1A94, memberDeleting);
                    fn_101_2474(members + 0x1A78, memberDeleting);
                    fn_101_24B4(members + 0x19CC, memberDeleting);
                    reinterpret_cast<ParameterBaseLifetime<0>*>(members + 0x19B8)->~ParameterBaseLifetime();
                }
            }
            if (members + 0xCC != 0) {
                fn_101_3C14(members + 0x199C, memberDeleting);
                fn_101_3C70(members + 0x195C, memberDeleting);
                fn_101_3CCC(members + 0x1944, memberDeleting);
                fn_101_3D28(members + 0x17A8, memberDeleting);
                fn_101_3DB4(members + 0x1748, memberDeleting);
                fn_101_3EB0(members + 0x1694, memberDeleting);
                if (members + 0x14C4 != 0) {
                    fn_101_4090(members + 0x15E4, memberDeleting);
                    fn_101_4114(members + 0x15D0, memberDeleting);
                    reinterpret_cast<CompositeSupportLifetime*>(members + 0x15B4)->~CompositeSupportLifetime();
                    fn_101_4174(members + 0x1510, memberDeleting);
                    if (members + 0x14D4 != 0) {
                        fn_101_3E14(members + 0x14EC, memberDeleting);
                    }
                    fn_27_C74E8(members + 0x14C4, static_cast<short>(-1));
                }
                fn_101_429C(members + 0x1420, memberDeleting);
                fn_101_43D0(members + 0x13EC, memberDeleting);
                fn_101_442C(members + 0x13C8, memberDeleting);
                fn_101_4490(members + 0x13B4, memberDeleting);
                fn_101_44EC(members + 0x1250, memberDeleting);
                fn_101_4558(members + 0x11E8, memberDeleting);
                fn_101_45B8(members + 0x11DC, memberDeleting);
                fn_101_4618(members + 0x11B4, memberDeleting);
                fn_101_4674(members + 0xFE4, memberDeleting);
                fn_101_46F8(members + 0xF80, memberDeleting);
                fn_101_47C4(members + 0xF44, memberDeleting);
                fn_101_4820(members + 0xE9C, memberDeleting);
                fn_101_488C(members + 0xDE8, memberDeleting);
                if (members + 0xBDC != 0) {
                    fn_27_13C90(members + 0xC78, memberDeleting);
                    fn_27_21038(members + 0xC64, memberDeleting);
                    fn_101_4900(members + 0xBDC, memberDeleting);
                }
                fn_101_4988(members + 0x9FC, memberDeleting);
                fn_101_49F4(members + 0x9CC, memberDeleting);
                fn_101_4AAC(members + 0x9BC, memberDeleting);
                fn_101_4AEC(members + 0x9A4, memberDeleting);
                __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                fn_101_4B48(members + 0xCC, memberDeleting);
            }
        }
        fn_27_1D81C8(this, static_cast<short>(0));
    }
};
}

extern "C" void* fn_101_36DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_101_3A70(members + 0x2040, static_cast<short>(-1));
        reinterpret_cast<SupportLifetime*>(members + 0x1FE8)->~SupportLifetime();
        reinterpret_cast<HierarchyLifetime*>(object)->~HierarchyLifetime();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
