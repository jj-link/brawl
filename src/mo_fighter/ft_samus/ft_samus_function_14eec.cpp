#include <so/event/so_event_system.h>

#pragma force_active on

class soModelEventObserver;
class soCollisionAttackEventObserver;

template <>
class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};

template <>
class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};

void operator delete(void*);

extern "C" {
void* fn_94_14690(void*, short);
void* fn_94_15310(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_94_1536C(void*, short);
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_153D8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_94_4790(void*, short);
void* fn_94_1475C(void*, short);
void* fn_94_147B8(void*, short);
void* fn_94_14814(void*, short);
void* fn_94_14870(void*, short);
void* fn_94_15434(void*, short);
void* fn_94_15494(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_94_4888(void*, short);
void* fn_94_154D4(void*, short);
void* fn_94_4928(void*, short);
void* fn_94_49AC(void*, short);
void* fn_94_148FC(void*, short);
void* fn_94_14984(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_94_149E4(void*, short);
void* fn_94_4B58(void*, short);
void* fn_94_15540(void*, short);
void* fn_94_14A6C(void*, short);
void* fn_94_14B38(void*, short);
void* fn_94_14B98(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void* fn_94_14BF4(void*, short);
void* fn_94_4BF4(void*, short);
void* fn_94_6560(void*, short);
void* fn_94_4C50(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_94_1559C(void*, short);
void* fn_94_14CEC(void*, short);
void* fn_94_14D64(void*, short);
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

extern "C" void* fn_94_14EEC(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x17a4)
            if (p + 0x17a4)
                fn_94_14690(p + 0x17a4, 0);

        if (object) {
            fn_94_15310(p + 0x175c, -1);
            fn_27_1DBB60(p + 0x1724, -1);

            if (p + 0xcc) {
                if (p + 0x1408) {
                    fn_94_1536C(p + 0x169c, -1);

                    if (p + 0x15fc) {
                        fn_94_2158(p + 0x164c, -1);
                        fn_94_21F4(p + 0x1630, -1);
                        fn_94_153D8(p + 0x1610, -1);
                        if (p + 0x15fc)
                            fn_27_C7770(p + 0x15fc, -1);
                    }

                    if (p + 0x155c) {
                        fn_94_2158(p + 0x15ac, -1);
                        fn_94_21F4(p + 0x1590, -1);
                        fn_94_153D8(p + 0x1570, -1);
                        if (p + 0x155c)
                            fn_27_C7770(p + 0x155c, -1);
                    }

                    if (p + 0x14bc) {
                        fn_94_2158(p + 0x150c, -1);
                        fn_94_21F4(p + 0x14f0, -1);
                        fn_94_153D8(p + 0x14d0, -1);
                        if (p + 0x14bc)
                            fn_27_C7770(p + 0x14bc, -1);
                    }

                    if (p + 0x1408) {
                        fn_94_2158(p + 0x146c, -1);
                        fn_94_21F4(p + 0x1450, -1);
                        fn_94_4790(p + 0x141c, -1);
                        if (p + 0x1408)
                            fn_27_C7770(p + 0x1408, -1);
                    }
                }

                if (p + 0xcc) {
                    fn_94_1475C(p + 0x13ec, -1);
                    fn_94_147B8(p + 0x13ac, -1);
                    fn_94_14814(p + 0x1394, -1);
                    fn_94_14870(p + 0x11f8, -1);
                    fn_94_15434(p + 0x1198, -1);

                    if (p + 0x10e4) {
                        fn_94_15494(p + 0x1194, -1);
                        if (p + 0x1114) {
                            fn_27_1A241C(p + 0x1124, -1);
                            fn_94_4888(p + 0x1114, 0);
                        }
                        fn_94_154D4(p + 0x10e4, -1);
                    }

                    if (p + 0xf70) {
                        fn_94_4928(p + 0x1034, -1);
                        fn_94_49AC(p + 0x1020, -1);
                        fn_94_148FC(p + 0xfb8, -1);
                        fn_94_14984(p + 0xf80, -1);
                        fn_27_C74E8(p + 0xf70, -1);
                    }

                    fn_94_149E4(p + 0xecc, -1);
                    fn_94_4B58(p + 0xe98, -1);
                    fn_94_15540(p + 0xe80, -1);
                    fn_94_14A6C(p + 0xd1c, -1);
                    fn_94_14B38(p + 0xd0c, -1);
                    fn_94_14B98(p + 0xce4, -1);

                    if (p + 0xb14) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0xc38, -1);
                        fn_27_82AD4(p + 0xc34, -1);
                        fn_27_4CAA0(p + 0xbb0, -1);
                        fn_27_19CA80(p + 0xb14, -1);
                    }

                    fn_94_14BF4(p + 0xab0, -1);
                    fn_94_4BF4(p + 0xa74, -1);
                    fn_94_6560(p + 0x9cc, -1);
                    fn_94_4C50(p + 0x918, -1);

                    if (p + 0x78c) {
                        fn_27_13C90(p + 0x7a8, -1);
                        fn_27_21038(p + 0x794, -1);
                    }

                    fn_94_1559C(p + 0x67c, -1);
                    fn_94_14CEC(p + 0x64c, -1);
                    fn_94_14D64(p + 0x63c, -1);
                    fn_94_4D60(p + 0x624, -1);
                    __dt__16soModuleAccesserFv(p + 0x544, -1);

                    if (p + 0xcc) {
                        fn_27_1A8B10(p + 0x4cc, -1);
                        fn_27_D7DBC(p + 0x48c, -1);
                        fn_27_D6B9C(p + 0x450, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x3f4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x398)->~soEventUnitWithWorkArea();
                        fn_27_D57AC(p + 0x35c, -1);
                        fn_27_1A9D88(p + 0x254, -1);
                        fn_27_D645C(p + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }

        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
