#pragma force_active on

void operator delete(void*);

class soModelEventObserver;
class soCollisionAttackEventObserver;
class soSituationEventObserver;
class soEventUnit;

template <class Observer, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class Element> class soInstanceUnit;
template <class Element, int Capacity> class soArrayVector;
template <class Element, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" {
void* fn_104_3804(void*, short);
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_18360(void*, short);
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_183CC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_104_3AF0(void*, short);
void* fn_104_3B4C(void*, short);
void* fn_104_3BA8(void*, short);
void* fn_104_3C04(void*, short);
void* fn_104_3D50(void*, short);
void* fn_104_3E4C(void*, short);
void* fn_104_3F88(void*, short);
void* fn_104_400C(void*, short);
void* fn_104_18428(void*, short);
void* fn_104_18484(void*, short);
void* fn_104_1850C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_104_4194(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_4324(void*, short);
void* fn_104_4380(void*, short);
void* fn_104_43EC(void*, short);
void* fn_104_444C(void*, short);
void* fn_104_44AC(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CF10(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_104_458C(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_46B4(void*, short);
void* fn_104_4720(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_104_480C(void*, short);
void* fn_104_4894(void*, short);
void* fn_104_4900(void*, short);
void* fn_104_49B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1A8B10(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9F58(void*, short);
void* fn_27_D645C(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_104_17F58(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x1B98 != 0) {
            if (storage + 0x1B98 != 0) {
                fn_104_3804(storage + 0x1B98, 0);
            }
        }
        if (object != 0) {
            fn_104_3844(storage + 0x1B50, -1);
            fn_27_1DBB60(storage + 0x1B18, -1);
            if (storage + 0xCC != 0) {
                if (storage + 0x17C0 != 0) {
                    fn_104_18360(storage + 0x1A90, -1);
                    if (storage + 0x19DC != 0) {
                        fn_104_21D0(storage + 0x1A40, -1);
                        fn_104_226C(storage + 0x1A24, -1);
                        fn_104_183CC(storage + 0x19F0, -1);
                        if (storage + 0x19DC != 0) {
                            fn_27_C7770(storage + 0x19DC, -1);
                        }
                    }
                    if (storage + 0x1928 != 0) {
                        fn_104_21D0(storage + 0x198C, -1);
                        fn_104_226C(storage + 0x1970, -1);
                        fn_104_183CC(storage + 0x193C, -1);
                        if (storage + 0x1928 != 0) {
                            fn_27_C7770(storage + 0x1928, -1);
                        }
                    }
                    if (storage + 0x1874 != 0) {
                        fn_104_21D0(storage + 0x18D8, -1);
                        fn_104_226C(storage + 0x18BC, -1);
                        fn_104_183CC(storage + 0x1888, -1);
                        if (storage + 0x1874 != 0) {
                            fn_27_C7770(storage + 0x1874, -1);
                        }
                    }
                    if (storage + 0x17C0 != 0) {
                        fn_104_21D0(storage + 0x1824, -1);
                        fn_104_226C(storage + 0x1808, -1);
                        fn_104_183CC(storage + 0x17D4, -1);
                        if (storage + 0x17C0 != 0) {
                            fn_27_C7770(storage + 0x17C0, -1);
                        }
                    }
                }
                if (storage + 0xCC != 0) {
                    fn_104_3AF0(storage + 0x17A4, -1);
                    fn_104_3B4C(storage + 0x1764, -1);
                    fn_104_3BA8(storage + 0x174C, -1);
                    fn_104_3C04(storage + 0x15B0, -1);
                    fn_104_3D50(storage + 0x1550, -1);
                    fn_104_3E4C(storage + 0x149C, -1);
                    if (storage + 0x1310 != 0) {
                        fn_104_3F88(storage + 0x13EC, -1);
                        fn_104_400C(storage + 0x13D8, -1);
                        fn_104_18428(storage + 0x13BC, -1);
                        fn_104_18484(storage + 0x1358, -1);
                        fn_104_1850C(storage + 0x1320, -1);
                        fn_27_C74E8(storage + 0x1310, -1);
                    }
                    fn_104_4194(storage + 0x126C, -1);
                    fn_104_42C8(storage + 0x1238, -1);
                    fn_104_4324(storage + 0x1220, -1);
                    fn_104_4380(storage + 0x10BC, -1);
                    fn_104_43EC(storage + 0x1054, -1);
                    fn_104_444C(storage + 0x1048, -1);
                    fn_104_44AC(storage + 0x1020, -1);
                    if (storage + 0xCA0 != 0) {
                        __dt__27soCollisionAttackModuleImplFv(storage + 0xF74, -1);
                        fn_27_82AD4(storage + 0xF70, -1);
                        fn_27_4CAA0(storage + 0xEEC, -1);
                        fn_27_19CF10(storage + 0xCA0, -1);
                    }
                    fn_104_458C(storage + 0xC3C, -1);
                    fn_104_4658(storage + 0xC00, -1);
                    fn_104_46B4(storage + 0xB58, -1);
                    fn_104_4720(storage + 0xAA4, -1);
                    if (storage + 0x898 != 0) {
                        fn_27_13C90(storage + 0x934, -1);
                        fn_27_21038(storage + 0x920, -1);
                        fn_104_480C(storage + 0x898, -1);
                    }
                    fn_104_4894(storage + 0x6B8, -1);
                    fn_104_4900(storage + 0x688, -1);
                    fn_104_49B8(storage + 0x678, -1);
                    fn_104_49F8(storage + 0x660, -1);
                    __dt__16soModuleAccesserFv(storage + 0x580, -1);
                    if (storage + 0xCC != 0) {
                        fn_27_1A8B10(storage + 0x508, -1);
                        fn_27_D7DBC(storage + 0x4C8, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x468)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x40C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x3AC)->~soEventUnitWithWorkArea();
                        fn_27_D57AC(storage + 0x374, -1);
                        fn_27_1A9F58(storage + 0x254, -1);
                        fn_27_D645C(storage + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(storage + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(storage + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
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