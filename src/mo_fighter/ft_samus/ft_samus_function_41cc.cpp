#pragma force_active on
void operator delete(void*);

class soModelEventObserver;
class soCollisionAttackEventObserver;
class soEventUnit;
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;
template <class T, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
template <class T, class S> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" {
void* fn_94_4750(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_94_4790(void*, short);
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_10424(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_94_30AC(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_94_47EC(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_94_4888(void*, short);
void* fn_94_1F14(void*, short);
void* fn_94_48C8(void*, short);
void* fn_94_4928(void*, short);
void* fn_94_49AC(void*, short);
void* fn_27_1A4D90(void*, short);
void* fn_94_4A0C(void*, short);
void* fn_27_1A1B88(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_94_4AAC(void*, short);
void* fn_94_4AEC(void*, short);
void* fn_94_4B58(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_B5324(void*, short);
void* fn_94_4BB4(void*, short);
void* fn_94_4BF4(void*, short);
void* fn_94_4C50(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_94_4CC4(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_94_4D20(void*, short);
void* fn_94_4D60(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1A8B10(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_D6B9C(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9D88(void*, short);
void* fn_27_D645C(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_94_41CC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (object != 0) {
            if (p + 0x1704 != 0) {
                fn_94_4750(p + 0x1704, 0);
            }
            fn_27_1DBB60(p + 0x16CC, -1);
            if (p + 0xCC != 0) {
                if (p + 0x1374 != 0) {
                    if (p + 0x1644 != 0) {
                        fn_94_4790(p + 0x1694, -1);
                        fn_94_2158(p + 0x1644, -1);
                    }
                    if (p + 0x1590 != 0) {
                        fn_94_2158(p + 0x15F4, -1);
                        fn_94_21F4(p + 0x15D8, -1);
                        fn_94_4790(p + 0x15A4, -1);
                        if (p + 0x1590 != 0) fn_27_C7770(p + 0x1590, -1);
                    }
                    if (p + 0x14DC != 0) {
                        fn_94_2158(p + 0x1540, -1);
                        fn_94_21F4(p + 0x1524, -1);
                        fn_94_4790(p + 0x14F0, -1);
                        if (p + 0x14DC != 0) fn_27_C7770(p + 0x14DC, -1);
                    }
                    if (p + 0x1428 != 0) {
                        fn_94_2158(p + 0x148C, -1);
                        fn_94_21F4(p + 0x1470, -1);
                        fn_94_4790(p + 0x143C, -1);
                        if (p + 0x1428 != 0) fn_27_C7770(p + 0x1428, -1);
                    }
                    if (p + 0x1374 != 0) {
                        fn_94_2158(p + 0x13D8, -1);
                        fn_94_21F4(p + 0x13BC, -1);
                        fn_94_4790(p + 0x1388, -1);
                        if (p + 0x1374 != 0) fn_27_C7770(p + 0x1374, -1);
                    }
                }
                if (p + 0xCC != 0) {
                    if (p + 0x1330 != 0) fn_27_63EBC(p + 0x1330, -1);
                    if (p + 0x1318 != 0) fn_27_5C674(p + 0x1318, -1);
                    if (p + 0x12C4 != 0) fn_27_10424(p + 0x12C8, -1);
                    if (p + 0x1130 != 0) {
                        fn_27_97968(p + 0x1188, -1);
                        fn_27_1CCCC(p + 0x1178, -1);
                        fn_94_30AC(p + 0x116C, -1);
                        if (p + 0x1130 != 0) fn_27_CBF58(p + 0x1130, -1);
                    }
                    if (p + 0x10D0 != 0) fn_94_47EC(p + 0x1108, -1);
                    if (p + 0x101C != 0) {
                        if (p + 0x104C != 0) {
                            fn_27_1A241C(p + 0x105C, -1);
                            fn_94_4888(p + 0x104C, 0);
                        }
                        if (p + 0x101C != 0) {
                            fn_94_1F14(p + 0x103C, 0);
                            fn_94_48C8(p + 0x101C, 0);
                        }
                    }
                    if (p + 0xE74 != 0) {
                        fn_94_4928(p + 0xF6C, -1);
                        fn_94_49AC(p + 0xF58, -1);
                        if (p + 0xF28 != 0) fn_27_1A4D90(p + 0xF28, -1);
                        if (p + 0xEC4 != 0) {
                            fn_94_4A0C(p + 0xF10, -1);
                            unsigned char* t = p + 0xEE4;
                            if (t != 0 && t != 0 && t != 0) {
                                fn_27_1A1B88(t, -1);
                            }
                            fn_27_CD934(p + 0xEC4, -1);
                        }
                        if (p + 0xE84 != 0) fn_94_47EC(p + 0xEA0, -1);
                        fn_27_C74E8(p + 0xE74, -1);
                    }
                    if (p + 0xDD0 != 0) {
                        if (p + 0xDF4 != 0) {
                            fn_27_1A262C(p + 0xE04, -1);
                            fn_94_4AAC(p + 0xDF4, 0);
                        }
                        fn_94_4AEC(p + 0xDD0, -1);
                    }
                    fn_94_4B58(p + 0xD9C, -1);
                    if (p + 0xD84 != 0) fn_27_5AE44(p + 0xD84, -1);
                    if (p + 0xC20 != 0) {
                        fn_27_6A3D8(p + 0xD30, -1);
                        fn_27_CBB00(p + 0xC20, -1);
                    }
                    if (p + 0xBB8 != 0) fn_27_565F0(p + 0xBC4, -1);
                    if (p + 0xBAC != 0) fn_27_6880C(p + 0xBB0, -1);
                    if (p + 0xB84 != 0) __dt__16soStopModuleImplFv(p + 0xB84, -1);
                    if (p + 0xB14 != 0) {
                        fn_27_B5324(p + 0xB34, -1);
                        if (p + 0xB24 != 0) fn_94_4BB4(p + 0xB24, 0);
                        if (p + 0xB14 != 0) fn_94_4BB4(p + 0xB14, 0);
                    }
                    fn_94_4BF4(p + 0xAD8, -1);
                    fn_94_4C50(p + 0xA20, -1);
                    if (p + 0x85C != 0) {
                        fn_27_13C90(p + 0x8B0, -1);
                        fn_27_21038(p + 0x89C, -1);
                        fn_94_4CC4(p + 0x860, -1);
                    }
                    if (p + 0x67C != 0) {
                        __dt__17soModelModuleImplFv(p + 0x790, -1);
                        fn_27_CBDE8(p + 0x67C, -1);
                    }
                    if (p + 0x64C != 0) {
                        __dt__20soResourceModuleImplFv(p + 0x664, -1);
                        if (p + 0x64C != 0) fn_94_4D20(p + 0x64C, 0);
                    }
                    fn_94_4D60(p + 0x624, -1);
                    __dt__16soModuleAccesserFv(p + 0x544, -1);
                    if (p + 0xCC != 0) {
                        fn_27_1A8B10(p + 0x4CC, -1);
                        fn_27_D7DBC(p + 0x48C, -1);
                        fn_27_D6B9C(p + 0x450, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x3F4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x398)->~soEventUnitWithWorkArea();
                        fn_27_D57AC(p + 0x35C, -1);
                        fn_27_1A9D88(p + 0x254, -1);
                        fn_27_D645C(p + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
