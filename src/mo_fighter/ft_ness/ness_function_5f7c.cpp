void operator delete(void*);
extern "C" {
void* fn_101_3B0C(void*, short);
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_572C(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3F44(void*, short);
void* fn_27_1A220C(void*, short);
void* fn_101_3F84(void*, short);
void* fn_101_3FC4(void*, short);
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_5BD4(void*, short);
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
void* fn_101_4674(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_5C9C(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_19A5BC(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1A8B10(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_1AA128(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

class soModelEventObserver;
class soCollisionAttackEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
class soEventUnit;
template <class Observer, int Capacity>
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

// Retain the nested embedded-destructor guards and reverse member order.
extern "C" void* fn_101_5F7C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x1BDC != 0) {
            if (storage + 0x1BDC != 0) {
                fn_101_3B0C(storage + 0x1BDC, 0);
            }
        }
        if (object != 0) {
            fn_101_3B4C(storage + 0x1B94, -1);
            fn_27_1DBB60(storage + 0x1B5C, -1);
            if (storage + 0xCC != 0) {
                fn_101_572C(storage + 0x15AC, -1);
                if (storage + 0xCC != 0) {
                    fn_101_3C70(storage + 0x1568, -1);
                    fn_101_3CCC(storage + 0x1550, -1);
                    fn_101_3D28(storage + 0x13B4, -1);
                    fn_101_3DB4(storage + 0x1354, -1);
                    if (storage + 0x12E8 != 0) {
                        fn_101_3F44(storage + 0x1350, -1);
                        if (storage + 0x1318 != 0) {
                            fn_27_1A220C(storage + 0x1328, -1);
                            fn_101_3F84(storage + 0x1318, 0);
                        }
                        fn_101_3FC4(storage + 0x12E8, -1);
                    }
                    if (storage + 0x1128 != 0) {
                        fn_101_4090(storage + 0x1238, -1);
                        fn_101_4114(storage + 0x1224, -1);
                        fn_101_5BD4(storage + 0x1214, -1);
                        fn_101_4174(storage + 0x1170, -1);
                        fn_101_51CC(storage + 0x1138, -1);
                        fn_27_C74E8(storage + 0x1128, -1);
                    }
                    fn_101_429C(storage + 0x1084, -1);
                    fn_101_43D0(storage + 0x1050, -1);
                    fn_101_4490(storage + 0x1038, -1);
                    fn_101_44EC(storage + 0xED4, -1);
                    fn_101_4558(storage + 0xE6C, -1);
                    fn_101_45B8(storage + 0xE60, -1);
                    fn_101_4618(storage + 0xE38, -1);
                    fn_101_4674(storage + 0xC68, -1);
                    fn_101_46F8(storage + 0xC04, -1);
                    fn_101_47C4(storage + 0xBC8, -1);
                    fn_101_488C(storage + 0xB10, -1);
                    fn_101_5C9C(storage + 0x904, -1);
                    if (storage + 0x7C0 != 0) {
                        __dt__17soModelModuleImplFv(storage + 0x838, -1);
                        fn_27_19A5BC(storage + 0x7C0, -1);
                    }
                    fn_101_49F4(storage + 0x790, -1);
                    fn_101_4AAC(storage + 0x780, -1);
                    fn_101_4AEC(storage + 0x768, -1);
                    __dt__16soModuleAccesserFv(storage + 0x688, -1);
                    if (storage + 0xCC != 0) {
                        fn_27_1A8B10(storage + 0x610, -1);
                        fn_27_D7DBC(storage + 0x5D0, -1);
                        fn_27_18D3DC(storage + 0x588, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x52C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x4D0)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x470)->~soEventUnitWithWorkArea();
                        fn_27_D597C(storage + 0x42C, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x3D0)->~soEventUnitWithWorkArea();
                        fn_27_1AA128(storage + 0x284, -1);
                        fn_27_18D788(storage + 0x198, -1);
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
