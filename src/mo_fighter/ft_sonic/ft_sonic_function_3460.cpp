#include <so/so_instance_manager.h>
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
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_123_3910(void*, short);
void* fn_123_39AC(void*, short);
void* fn_123_1AEC(void*, short);
void* fn_123_396C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_123_39EC(void*, short);
void* fn_123_216C(void*, short);
void* fn_123_2208(void*, short);
void* fn_123_2248(void*, short);
void* fn_27_C7770(void*, short);
void* fn_123_3A58(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_123_3AE4(void*, short);
void* fn_123_3B40(void*, short);
void* fn_27_198E00(void*, short);
void* fn_27_199318(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_A3704(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_123_30CC(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_123_3B9C(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_123_3C98(void*, short);
void* fn_123_1F28(void*, short);
void* fn_123_3CD8(void*, short);
void* fn_123_3D38(void*, short);
void* fn_123_3FA0(void*, short);
void* fn_123_40D4(void*, short);
void* fn_123_4130(void*, short);
void* fn_123_418C(void*, short);
void* fn_123_41F8(void*, short);
void* fn_123_4258(void*, short);
void* fn_123_42B8(void*, short);
void* fn_123_4314(void*, short);
void* fn_123_4398(void*, short);
void* fn_123_4464(void*, short);
void* fn_123_44C0(void*, short);
void* fn_123_452C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_123_45A0(void*, short);
void* fn_123_4628(void*, short);
void* fn_123_4694(void*, short);
void* fn_123_474C(void*, short);
void* fn_123_478C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1AAD74(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_123_3460(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_3910(storage + 0x21BC, -1);
        if (storage + 0x2168 != 0) {
            if (storage + 0x2168 != 0) {
                fn_123_39AC(storage + 0x2168, 0);
            }
        }
        fn_123_1AEC(storage + 0x2158, 0);
        if (object != 0) {
            if (storage + 0x2114 != 0) {
                fn_123_396C(storage + 0x2114, 0);
            }
            fn_27_1DBB60(storage + 0x20DC, -1);
            if (storage + 0xCC != 0) {
                if (storage + 0x1B2C != 0) {
                    fn_123_39EC(storage + 0x1FDC, -1);
                    if (storage + 0x1EB0 != 0) {
                        fn_123_216C(storage + 0x1F8C, -1);
                        fn_123_2208(storage + 0x1F70, -1);
                        fn_123_2248(storage + 0x1EC4, -1);
                        if (storage + 0x1EB0 != 0) {
                            fn_27_C7770(storage + 0x1EB0, -1);
                        }
                    }
                    if (storage + 0x1D84 != 0) {
                        fn_123_216C(storage + 0x1E60, -1);
                        fn_123_2208(storage + 0x1E44, -1);
                        fn_123_2248(storage + 0x1D98, -1);
                        if (storage + 0x1D84 != 0) {
                            fn_27_C7770(storage + 0x1D84, -1);
                        }
                    }
                    if (storage + 0x1C58 != 0) {
                        fn_123_216C(storage + 0x1D34, -1);
                        fn_123_2208(storage + 0x1D18, -1);
                        fn_123_2248(storage + 0x1C6C, -1);
                        if (storage + 0x1C58 != 0) {
                            fn_27_C7770(storage + 0x1C58, -1);
                        }
                    }
                    fn_123_3A58(storage + 0x1B2C, -1);
                }
                if (storage + 0xCC != 0) {
                    if (storage + 0x1B10 != 0) {
                        fn_27_C31CC(storage + 0x1B10, -1);
                    }
                    fn_123_3AE4(storage + 0x1AD0, -1);
                    fn_123_3B40(storage + 0x1AB8, -1);
                    if (storage + 0x19A4 != 0) {
                        fn_27_198E00(storage + 0x1A7C, -1);
                        fn_27_199318(storage + 0x1A10, -1);
                        fn_27_A78FC(storage + 0x19F4, -1);
                        fn_27_A3704(storage + 0x19A8, -1);
                    }
                    if (storage + 0x1810 != 0) {
                        fn_27_97968(storage + 0x1868, -1);
                        fn_27_1CCCC(storage + 0x1858, -1);
                        fn_123_30CC(storage + 0x184C, -1);
                        if (storage + 0x1810 != 0) {
                            fn_27_CBF58(storage + 0x1810, -1);
                        }
                    }
                    fn_123_3B9C(storage + 0x17B0, -1);
                    if (storage + 0x16FC != 0) {
                        if (storage + 0x172C != 0) {
                            fn_27_1A241C(storage + 0x173C, -1);
                            fn_123_3C98(storage + 0x172C, 0);
                        }
                        if (storage + 0x16FC != 0) {
                            fn_123_1F28(storage + 0x171C, 0);
                            fn_123_3CD8(storage + 0x16FC, 0);
                        }
                    }
                    fn_123_3D38(storage + 0x1530, -1);
                    fn_123_3FA0(storage + 0x148C, -1);
                    fn_123_40D4(storage + 0x1458, -1);
                    fn_123_4130(storage + 0x1440, -1);
                    fn_123_418C(storage + 0x12DC, -1);
                    fn_123_41F8(storage + 0x1274, -1);
                    fn_123_4258(storage + 0x1268, -1);
                    fn_123_42B8(storage + 0x1240, -1);
                    fn_123_4314(storage + 0x1070, -1);
                    fn_123_4398(storage + 0x100C, -1);
                    fn_123_4464(storage + 0xFD0, -1);
                    fn_123_44C0(storage + 0xF28, -1);
                    fn_123_452C(storage + 0xE74, -1);
                    if (storage + 0xC68 != 0) {
                        fn_27_13C90(storage + 0xD04, -1);
                        fn_27_21038(storage + 0xCF0, -1);
                        fn_123_45A0(storage + 0xC68, -1);
                    }
                    fn_123_4628(storage + 0xA88, -1);
                    fn_123_4694(storage + 0xA58, -1);
                    fn_123_474C(storage + 0xA48, -1);
                    fn_123_478C(storage + 0xA30, -1);
                    __dt__16soModuleAccesserFv(storage + 0x950, -1);
                    if (storage + 0xCC != 0) {
                        fn_27_1AAD74(storage + 0x8C0, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x888)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x850)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x7F4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x798)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x73C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x6E0)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x684)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(storage + 0x640, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x5E4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x52C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x4D0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(storage + 0x48C, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(storage + 0x284, -1);
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
