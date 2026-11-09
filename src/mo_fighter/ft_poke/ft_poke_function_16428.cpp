#pragma force_active on

void operator delete(void*);

class soEventUnit;
struct acCmdInterpreterStackData;
class soModelEventObserver;
class soCollisionAttackEventObserver;

template <class T> class soInstanceUnit {
public:
    ~soInstanceUnit();
};
template <class T, int C> class soArrayVector {
public:
    ~soArrayVector();
};
template <class T, class U> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};
template <class T, int C> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" {
void* fn_116_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_38F0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_116_3ACC(void*, short);
void* fn_27_1A220C(void*, short);
void* fn_116_3C04(void*, short);
void* fn_116_1F20(void*, short);
void* fn_116_3C44(void*, short);
void* fn_116_3CA4(void*, short);
void* fn_116_3D28(void*, short);
void* fn_116_4B64(void*, short);
void* fn_27_1A1B88(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_116_3E10(void*, short);
void* fn_116_3E50(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void* fn_27_B5324(void*, short);
void* fn_116_4150(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_19A33C(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_116_4CE8(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1A8B10(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9D88(void*, short);
void* fn_27_1A9194(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_116_16428(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            unsigned char* p = static_cast<unsigned char*>(object);
            if (p + 0x1600 != 0) fn_116_3844(p + 0x1600, 0);
            fn_27_1DBB60(p + 0x15c8, -1);
            if (p + 0xcc != 0) {
                if (p + 0x12b4 != 0) {
                    if (p + 0x1570 != 0) fn_116_2164(p + 0x1570, -1);
                    if (p + 0x14bc != 0) {
                        fn_116_2164(p + 0x1520, -1);
                        fn_116_2200(p + 0x1504, -1);
                        fn_116_38F0(p + 0x14d0, -1);
                        if (p + 0x14bc != 0) fn_27_C7770(p + 0x14bc, -1);
                    }
                    if (p + 0x1408 != 0) {
                        fn_116_2164(p + 0x146c, -1);
                        fn_116_2200(p + 0x1450, -1);
                        fn_116_38F0(p + 0x141c, -1);
                        if (p + 0x1408 != 0) fn_27_C7770(p + 0x1408, -1);
                    }
                    if (p + 0x1354 != 0) {
                        fn_116_2164(p + 0x13b8, -1);
                        fn_116_2200(p + 0x139c, -1);
                        fn_116_38F0(p + 0x1368, -1);
                        if (p + 0x1354 != 0) fn_27_C7770(p + 0x1354, -1);
                    }
                    if (p + 0x12b4 != 0) {
                        fn_116_2164(p + 0x1304, -1);
                        fn_116_2200(p + 0x12e8, -1);
                        if (p + 0x12c8 != 0)
                            reinterpret_cast<soArrayVector<acCmdInterpreterStackData, 1>*>(p + 0x12c8)->~soArrayVector();
                        if (p + 0x12b4 != 0) fn_27_C7770(p + 0x12b4, -1);
                    }
                }
                if (p + 0xcc != 0) {
                    if (p + 0x1298 != 0) fn_27_C31CC(p + 0x1298, -1);
                    if (p + 0x1258 != 0) fn_27_63EBC(p + 0x1258, -1);
                    if (p + 0x1240 != 0) fn_27_5C674(p + 0x1240, -1);
                    if (p + 0x10e8 != 0) {
                        fn_27_97968(p + 0x10fc, -1);
                        fn_27_1CCCC(p + 0x10ec, -1);
                    }
                    if (p + 0x1080 != 0) fn_116_3ACC(p + 0x10c0, -1);
                    if (p + 0x1014 != 0) {
                        if (p + 0x1044 != 0) {
                            fn_27_1A220C(p + 0x1054, -1);
                            fn_116_3C04(p + 0x1044, 0);
                        }
                        if (p + 0x1014 != 0) {
                            fn_116_1F20(p + 0x1034, 0);
                            fn_116_3C44(p + 0x1014, 0);
                        }
                    }
                    if (p + 0xed4 != 0) {
                        fn_116_3CA4(p + 0xf64, -1);
                        fn_116_3D28(p + 0xf50, -1);
                        if (p + 0xee8 != 0) {
                            fn_116_4B64(p + 0xf34, -1);
                            if (p + 0xf08 != 0) {
                                if (p + 0xf08 != 0) {
                                    if (p + 0xf08 != 0) fn_27_1A1B88(p + 0xf08, -1);
                                }
                            }
                            fn_27_CD934(p + 0xee8, -1);
                        }
                        fn_27_C74E8(p + 0xed4, -1);
                    }
                    if (p + 0xe30 != 0) {
                        if (p + 0xe54 != 0) {
                            fn_27_1A262C(p + 0xe64, -1);
                            fn_116_3E10(p + 0xe54, 0);
                        }
                        fn_116_3E50(p + 0xe30, -1);
                    }
                    fn_116_3EBC(p + 0xdfc, -1);
                    if (p + 0xc94 != 0) {
                        fn_27_6A3D8(p + 0xda4, -1);
                        fn_27_CBB00(p + 0xc94, -1);
                    }
                    if (p + 0xc84 != 0) fn_27_6880C(p + 0xc88, -1);
                    if (p + 0xc5c != 0) __dt__16soStopModuleImplFv(p + 0xc5c, -1);
                    if (p + 0xa8c != 0) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0xbb0, -1);
                        fn_27_82AD4(p + 0xbac, -1);
                        fn_27_4CAA0(p + 0xb28, -1);
                        fn_27_19CA80(p + 0xa8c, -1);
                    }
                    if (p + 0xa28 != 0) {
                        fn_27_B5324(p + 0xa48, -1);
                        if (p + 0xa38 != 0) fn_116_4150(p + 0xa38, 0);
                        if (p + 0xa28 != 0) fn_116_4150(p + 0xa28, 0);
                    }
                    fn_116_41EC(p + 0x97c, -1);
                    fn_116_4258(p + 0x8c8, -1);
                    if (p + 0x73c != 0) {
                        fn_27_13C90(p + 0x758, -1);
                        fn_27_21038(p + 0x744, -1);
                    }
                    if (p + 0x62c != 0) {
                        __dt__17soModelModuleImplFv(p + 0x670, -1);
                        fn_27_19A33C(p + 0x62c, -1);
                    }
                    if (p + 0x5fc != 0) {
                        __dt__20soResourceModuleImplFv(p + 0x614, -1);
                        if (p + 0x5fc != 0) fn_116_4CE8(p + 0x5fc, 0);
                    }
                    fn_116_430C(p + 0x5d4, -1);
                    __dt__16soModuleAccesserFv(p + 0x4f4, -1);
                    if (p + 0xcc != 0) {
                        fn_27_1A8B10(p + 0x47c, -1);
                        fn_27_D7DBC(p + 0x43c, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x3dc)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x380)->~soEventUnitWithWorkArea();
                        fn_27_D57AC(p + 0x344, -1);
                        fn_27_1A9D88(p + 0x23c, -1);
                        fn_27_1A9194(p + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}