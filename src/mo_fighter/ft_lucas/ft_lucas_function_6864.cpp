#pragma force_active on
template <class T, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;
template <class T, class U>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

class soEventUnit;
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
void* fn_114_3A60(void*, short);
void* fn_114_3AA0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_114_3AFC(void*, short);
void* fn_114_232C(void*, short);
void* fn_114_23C8(void*, short);
void* fn_114_2408(void*, short);
void* fn_27_C7770(void*, short);
void* fn_114_3BC4(void*, short);
void* fn_114_3C20(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_10424(void*, short);
void* fn_114_3C7C(void*, short);
void* fn_114_3D08(void*, short);
void* fn_114_3E04(void*, short);
void* fn_114_3FE4(void*, short);
void* fn_114_4068(void*, short);
void* fn_27_1A4D90(void*, short);
void* fn_114_40C8(void*, short);
void* fn_114_3D68(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_114_41F0(void*, short);
void* fn_114_4324(void*, short);
void* fn_114_43E4(void*, short);
void* fn_114_4440(void*, short);
void* fn_114_44AC(void*, short);
void* fn_114_450C(void*, short);
void* fn_114_456C(void*, short);
void* fn_114_45C8(void*, short);
void* fn_114_464C(void*, short);
void* fn_114_4718(void*, short);
void* fn_114_47E0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_114_4854(void*, short);
void* fn_114_48DC(void*, short);
void* fn_114_4948(void*, short);
void* fn_114_4A00(void*, short);
void* fn_114_4A40(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}

extern "C" void* fn_114_6864(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);

        if (p + 0x20d0) {
            if (p + 0x20d0)
                fn_114_3A60(p + 0x20d0, 0);
        }

        if (object) {
            fn_114_3AA0(p + 0x2088, -1);
            fn_27_1DBB60(p + 0x2050, -1);

            if (p + 0xcc) {
                if (p + 0x1aa0) {
                    fn_114_3AFC(p + 0x1f50, -1);

                    if (p + 0x1e24) {
                        fn_114_232C(p + 0x1f00, -1);
                        fn_114_23C8(p + 0x1ee4, -1);
                        fn_114_2408(p + 0x1e38, -1);
                        if (p + 0x1e24)
                            fn_27_C7770(p + 0x1e24, -1);
                    }
                    if (p + 0x1cf8) {
                        fn_114_232C(p + 0x1dd4, -1);
                        fn_114_23C8(p + 0x1db8, -1);
                        fn_114_2408(p + 0x1d0c, -1);
                        if (p + 0x1cf8)
                            fn_27_C7770(p + 0x1cf8, -1);
                    }
                    if (p + 0x1bcc) {
                        fn_114_232C(p + 0x1ca8, -1);
                        fn_114_23C8(p + 0x1c8c, -1);
                        fn_114_2408(p + 0x1be0, -1);
                        if (p + 0x1bcc)
                            fn_27_C7770(p + 0x1bcc, -1);
                    }
                    if (p + 0x1aa0) {
                        fn_114_232C(p + 0x1b7c, -1);
                        fn_114_23C8(p + 0x1b60, -1);
                        fn_114_2408(p + 0x1ab4, -1);
                        if (p + 0x1aa0)
                            fn_27_C7770(p + 0x1aa0, -1);
                    }
                }

                if (p + 0xcc) {
                    fn_114_3BC4(p + 0x1a5c, -1);
                    fn_114_3C20(p + 0x1a44, -1);
                    if (p + 0x18ec)
                        fn_27_BED74(p + 0x18ec, -1);
                    if (p + 0x189c)
                        fn_27_10424(p + 0x18a0, -1);
                    fn_114_3C7C(p + 0x1708, -1);
                    fn_114_3D08(p + 0x16a8, -1);
                    fn_114_3E04(p + 0x15f4, -1);

                    if (p + 0x140c) {
                        fn_114_3FE4(p + 0x1544, -1);
                        fn_114_4068(p + 0x1530, -1);
                        if (p + 0x1500)
                            fn_27_1A4D90(p + 0x1500, -1);
                        fn_114_40C8(p + 0x145c, -1);
                        if (p + 0x141c)
                            fn_114_3D68(p + 0x1438, -1);
                        fn_27_C74E8(p + 0x140c, -1);
                    }

                    fn_114_41F0(p + 0x1368, -1);
                    fn_114_4324(p + 0x1334, -1);
                    fn_114_43E4(p + 0x131c, -1);
                    fn_114_4440(p + 0x11b8, -1);
                    fn_114_44AC(p + 0x1150, -1);
                    fn_114_450C(p + 0x1144, -1);
                    fn_114_456C(p + 0x111c, -1);
                    fn_114_45C8(p + 0xf4c, -1);
                    fn_114_464C(p + 0xee8, -1);
                    fn_114_4718(p + 0xeac, -1);
                    fn_114_47E0(p + 0xdf4, -1);

                    if (p + 0xbe8) {
                        fn_27_13C90(p + 0xc84, -1);
                        fn_27_21038(p + 0xc70, -1);
                        fn_114_4854(p + 0xbe8, -1);
                    }

                    fn_114_48DC(p + 0xa08, -1);
                    fn_114_4948(p + 0x9d8, -1);
                    fn_114_4A00(p + 0x9c8, -1);
                    fn_114_4A40(p + 0x9b0, -1);
                    __dt__16soModuleAccesserFv(p + 0x8d0, -1);

                    if (p + 0xcc) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x894)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x85c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x800)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7a4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x748)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6ec)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x690)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x64c, -1);
                        fn_27_18D498(p + 0x5e4, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x52c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4d0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(p + 0x48c, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(p + 0x284, -1);
                        fn_27_18D788(p + 0x198, -1);
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
