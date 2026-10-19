#pragma force_active on

void operator delete(void*);

extern "C" {
void fn_114_3A60(void*, short);
void fn_114_3AA0(void*, short);
void fn_27_1DBB60(void*, short);
void fn_114_5680(void*, short);
void fn_114_3BC4(void*, short);
void fn_114_3C20(void*, short);
void fn_114_3C7C(void*, short);
void fn_114_3D08(void*, short);
void fn_114_3E98(void*, short);
void fn_27_1A220C(void*, short);
void fn_114_3ED8(void*, short);
void fn_114_3F18(void*, short);
void fn_114_3FE4(void*, short);
void fn_114_4068(void*, short);
void fn_114_5A38(void*, short);
void fn_114_40C8(void*, short);
void fn_114_5120(void*, short);
void fn_27_C74E8(void*, short);
void fn_114_41F0(void*, short);
void fn_114_4324(void*, short);
void fn_114_43E4(void*, short);
void fn_114_4440(void*, short);
void fn_114_44AC(void*, short);
void fn_114_450C(void*, short);
void fn_114_456C(void*, short);
void fn_114_45C8(void*, short);
void fn_114_464C(void*, short);
void fn_114_4718(void*, short);
void fn_114_47E0(void*, short);
void fn_114_5A94(void*, short);
void __dt__17soModelModuleImplFv(void*, short);
void fn_27_19A5BC(void*, short);
void fn_114_4948(void*, short);
void fn_114_4A00(void*, short);
void fn_114_4A40(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_1A8B10(void*, short);
void fn_27_D7DBC(void*, short);
void fn_27_18D3DC(void*, short);
void fn_27_D597C(void*, short);
void fn_27_1AA128(void*, short);
void fn_27_18D788(void*, short);
void __dt__23soEventManageModuleImplFv(void*, short);
void fn_27_1D81C8(void*, short);
}

class soModelEventObserver;
class soCollisionAttackEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;

template<class T, int N> struct soEventUnitWithWorkArea {
    ~soEventUnitWithWorkArea();
};

class soEventUnit;
template<class T> class soInstanceUnit;
template<class T, int N> class soArrayVector;

template<class T, class A> struct soInstanceManagerSimpleEntity {
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_114_5D6C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1BDC != 0) {
            if (members + 0x1BDC != 0) {
                fn_114_3A60(members + 0x1BDC, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_114_3AA0(members + 0x1B94, memberDeleting);
            fn_27_1DBB60(members + 0x1B5C, memberDeleting);
            if (members + 0xCC != 0) {
                fn_114_5680(members + 0x15AC, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_114_3BC4(members + 0x1568, memberDeleting);
                    fn_114_3C20(members + 0x1550, memberDeleting);
                    fn_114_3C7C(members + 0x13B4, memberDeleting);
                    fn_114_3D08(members + 0x1354, memberDeleting);
                    if (members + 0x12E8 != 0) {
                        fn_114_3E98(members + 0x1350, memberDeleting);
                        if (members + 0x1318 != 0) {
                            fn_27_1A220C(members + 0x1328, memberDeleting);
                            fn_114_3ED8(members + 0x1318, static_cast<short>(0));
                        }
                        fn_114_3F18(members + 0x12E8, static_cast<short>(-1));
                    }
                    if (members + 0x1128 != 0) {
                        fn_114_3FE4(members + 0x1238, memberDeleting);
                        fn_114_4068(members + 0x1224, memberDeleting);
                        fn_114_5A38(members + 0x1214, memberDeleting);
                        fn_114_40C8(members + 0x1170, memberDeleting);
                        fn_114_5120(members + 0x1138, memberDeleting);
                        fn_27_C74E8(members + 0x1128, memberDeleting);
                    }
                    fn_114_41F0(members + 0x1084, memberDeleting);
                    fn_114_4324(members + 0x1050, memberDeleting);
                    fn_114_43E4(members + 0x1038, memberDeleting);
                    fn_114_4440(members + 0xED4, memberDeleting);
                    fn_114_44AC(members + 0xE6C, memberDeleting);
                    fn_114_450C(members + 0xE60, memberDeleting);
                    fn_114_456C(members + 0xE38, memberDeleting);
                    fn_114_45C8(members + 0xC68, memberDeleting);
                    fn_114_464C(members + 0xC04, memberDeleting);
                    fn_114_4718(members + 0xBC8, memberDeleting);
                    fn_114_47E0(members + 0xB10, memberDeleting);
                    fn_114_5A94(members + 0x904, memberDeleting);
                    if (members + 0x7C0 != 0) {
                        __dt__17soModelModuleImplFv(members + 0x838, memberDeleting);
                        fn_27_19A5BC(members + 0x7C0, memberDeleting);
                    }
                    fn_114_4948(members + 0x790, memberDeleting);
                    fn_114_4A00(members + 0x780, memberDeleting);
                    fn_114_4A40(members + 0x768, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x688, memberDeleting);
                    if (members + 0xCC != 0) {
                        fn_27_1A8B10(members + 0x610, memberDeleting);
                        fn_27_D7DBC(members + 0x5D0, memberDeleting);
                        fn_27_18D3DC(members + 0x588, memberDeleting);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(members + 0x52C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(members + 0x4D0)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(members + 0x470)->~soEventUnitWithWorkArea();
                        fn_27_D597C(members + 0x42C, memberDeleting);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(members + 0x3D0)->~soEventUnitWithWorkArea();
                        fn_27_1AA128(members + 0x284, memberDeleting);
                        fn_27_18D788(members + 0x198, memberDeleting);
                        __dt__23soEventManageModuleImplFv(members + 0x184, memberDeleting);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(members + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
