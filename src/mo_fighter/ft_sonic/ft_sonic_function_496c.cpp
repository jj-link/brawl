#include <types.h>
#include <so/so_instance_manager.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>
#pragma force_active on
class soEventUnit;
template <class Observer, int Capacity> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;

void operator delete(void*);

extern "C" {
void* fn_123_39AC(void*, short);
void* fn_123_216C(void*, short);
void* fn_123_2208(void*, short);
void* fn_123_2248(void*, short);
void* fn_27_C7770(void*, short);
void* fn_123_39EC(void*, short);
void* fn_123_3A58(void*, short);
void* fn_123_3AE4(void*, short);
void* fn_123_3B40(void*, short);
void* fn_27_BED74(void*, short);
void* fn_123_2E14(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_123_30CC(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_123_3B9C(void*, short);
void* fn_123_396C(void*, short);
void* fn_123_4E64(void*, short);
void* fn_123_4ED4(void*, short);
void* fn_123_3D38(void*, short);
void* fn_123_3FA0(void*, short);
void* fn_123_40D4(void*, short);
void* fn_123_4F40(void*, short);
void __dt__22soControllerModuleImplFv(void*, short);
void* fn_123_4130(void*, short);
void* fn_123_418C(void*, short);
void* fn_123_41F8(void*, short);
void* fn_123_4258(void*, short);
void* fn_123_42B8(void*, short);
void* fn_123_4FB4(void*, short);
void* fn_123_4314(void*, short);
void* fn_123_4398(void*, short);
void* fn_123_4464(void*, short);
void* fn_123_44C0(void*, short);
void* fn_123_452C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_123_5038(void*, short);
void* fn_123_45A0(void*, short);
void* fn_123_4628(void*, short);
void* fn_123_4694(void*, short);
void* fn_123_474C(void*, short);
void* fn_123_478C(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_1AA40C(void*, short);
void* fn_27_1A9648(void*, short);
void __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_123_496C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x2CD8 != 0) {
            if (storage + 0x2CD8 != 0) {
                fn_123_39AC(storage + 0x2CD8, 0);
            }
        }
        if (object != 0) {
            if (storage + 0xCC != 0) {
                if (storage + 0x25F8 != 0) {
                    if (storage + 0x2BA4 != 0) {
                        fn_123_216C(storage + 0x2C80, -1);
                        fn_123_2208(storage + 0x2C64, -1);
                        fn_123_2248(storage + 0x2BB8, -1);
                        if (storage + 0x2BA4 != 0) {
                            fn_27_C7770(storage + 0x2BA4, -1);
                        }
                    }
                    fn_123_39EC(storage + 0x2AA8, -1);
                    if (storage + 0x297C != 0) {
                        fn_123_216C(storage + 0x2A58, -1);
                        fn_123_2208(storage + 0x2A3C, -1);
                        fn_123_2248(storage + 0x2990, -1);
                        if (storage + 0x297C != 0) {
                            fn_27_C7770(storage + 0x297C, -1);
                        }
                    }
                    if (storage + 0x2850 != 0) {
                        fn_123_216C(storage + 0x292C, -1);
                        fn_123_2208(storage + 0x2910, -1);
                        fn_123_2248(storage + 0x2864, -1);
                        if (storage + 0x2850 != 0) {
                            fn_27_C7770(storage + 0x2850, -1);
                        }
                    }
                    if (storage + 0x2724 != 0) {
                        fn_123_216C(storage + 0x2800, -1);
                        fn_123_2208(storage + 0x27E4, -1);
                        fn_123_2248(storage + 0x2738, -1);
                        if (storage + 0x2724 != 0) {
                            fn_27_C7770(storage + 0x2724, -1);
                        }
                    }
                    fn_123_3A58(storage + 0x25F8, -1);
                }
                if (storage + 0xCC != 0) {
                    fn_123_3AE4(storage + 0x25B4, -1);
                    fn_123_3B40(storage + 0x259C, -1);
                    if (storage + 0x2444 != 0) {
                        fn_27_BED74(storage + 0x2444, -1);
                    }
                    fn_123_2E14(storage + 0x23F8, -1);
                    if (storage + 0x2260 != 0) {
                        fn_27_97968(storage + 0x22B8, -1);
                        fn_27_1CCCC(storage + 0x22A8, -1);
                        fn_123_30CC(storage + 0x229C, -1);
                        if (storage + 0x2260 != 0) {
                            fn_27_CBF58(storage + 0x2260, -1);
                        }
                    }
                    fn_123_3B9C(storage + 0x2200, -1);
                    if (storage + 0x20B8 != 0) {
                        if (storage + 0x2198 != 0) {
                            if (storage + 0x219C != 0) {
                                if (storage + 0x219C != 0) {
                                    if (storage + 0x21E0 != 0) {
                                        if (storage + 0x21E8 != 0) {
                                            if (storage + 0x21EC != 0) {
                                                fn_123_396C(storage + 0x21EC, 0);
                                            }
                                        }
                                    }
                                    if (storage + 0x219C != 0) {
                                        if (storage + 0x219C != 0) {
                                            if (storage + 0x21A0 != 0) {
                                                if (storage + 0x21A8 != 0) {
                                                    if (storage + 0x21AC != 0) {
                                                        fn_123_396C(storage + 0x21AC, 0);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        fn_123_4E64(storage + 0x20E8, -1);
                        fn_123_4ED4(storage + 0x20B8, -1);
                    }
                    fn_123_3D38(storage + 0x1EEC, -1);
                    fn_123_3FA0(storage + 0x1E48, -1);
                    fn_123_40D4(storage + 0x1E14, -1);
                    fn_123_4F40(storage + 0x1DA0, -1);
                    if (storage + 0x1D80 != 0) {
                        if (storage + 0x1D84 != 0) {
                            __dt__22soControllerModuleImplFv(storage + 0x1D84, 0);
                        }
                    }
                    fn_123_4130(storage + 0x1D6C, -1);
                    fn_123_418C(storage + 0x1C08, -1);
                    fn_123_41F8(storage + 0x1BA0, -1);
                    fn_123_4258(storage + 0x1B94, -1);
                    fn_123_42B8(storage + 0x1B6C, -1);
                    fn_123_4FB4(storage + 0x1208, -1);
                    fn_123_4314(storage + 0x1044, -1);
                    fn_123_4398(storage + 0xFE0, -1);
                    fn_123_4464(storage + 0xFA4, -1);
                    fn_123_44C0(storage + 0xEFC, -1);
                    fn_123_452C(storage + 0xE48, -1);
                    if (storage + 0xC00 != 0) {
                        fn_27_13C90(storage + 0xCD8, -1);
                        fn_27_21038(storage + 0xCC4, -1);
                        fn_123_5038(storage + 0xC88, -1);
                        fn_123_45A0(storage + 0xC00, -1);
                    }
                    fn_123_4628(storage + 0xA20, -1);
                    fn_123_4694(storage + 0x9F0, -1);
                    fn_123_474C(storage + 0x9E0, -1);
                    fn_123_478C(storage + 0x9C8, -1);
                    __dt__16soModuleAccesserFv(storage + 0x8E8, -1);
                    if (storage + 0xCC != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x8AC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x874)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x818)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x7BC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x760)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x704)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x6A8)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(storage + 0x664, -1);
                        fn_27_18D498(storage + 0x5FC, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x5A0)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x544)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x4E8)->~soEventUnitWithWorkArea();
                        fn_27_D597C(storage + 0x4A4, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x448)->~soEventUnitWithWorkArea();
                        fn_27_1AA40C(storage + 0x290, -1);
                        fn_27_1A9648(storage + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(storage + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(storage + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
