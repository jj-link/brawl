#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_37E8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_116_3884(void*, short);
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_38F0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_116_394C(void*, short);
void* fn_116_39A8(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_3A60(void*, short);
void* fn_116_3ACC(void*, short);
void* fn_116_3B68(void*, short);
void* fn_116_3CA4(void*, short);
void* fn_116_3D28(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_3F18(void*, short);
void* fn_116_3F84(void*, short);
void* fn_116_3FE4(void*, short);
void* fn_116_4040(void*, short);
void* fn_116_40C4(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_19A33C(void*, short);
void* fn_116_42CC(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1A8CE0(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_D6B9C(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9BB8(void*, short);
void* fn_27_1A9364(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

class soEventUnit;
class soModelEventObserver;
class soCollisionAttackEventObserver;

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template<class T>
class soInstanceUnit {};

template<class T, int N>
class soArrayVector {};

template<class T, class A>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_116_3468(void* object, int deleting) {
    if (object != 0) {
        char* p = static_cast<char*>(object);
        if (object != 0) {
            short d = -1;
            fn_116_37E8(p + 0x1604, d);
            fn_27_1DBB60(p + 0x15CC, d);
            if (p + 0xCC != 0) {
                if (p + 0x12A8 != 0) {
                    fn_116_3884(p + 0x1544, d);
                    if (p + 0x1490 != 0) {
                        fn_116_2164(p + 0x14F4, d);
                        fn_116_2200(p + 0x14D8, d);
                        fn_116_38F0(p + 0x14A4, d);
                        if (p + 0x1490 != 0) fn_27_C7770(p + 0x1490, d);
                    }
                    if (p + 0x13DC != 0) {
                        fn_116_2164(p + 0x1440, d);
                        fn_116_2200(p + 0x1424, d);
                        fn_116_38F0(p + 0x13F0, d);
                        if (p + 0x13DC != 0) fn_27_C7770(p + 0x13DC, d);
                    }
                    if (p + 0x1328 != 0) {
                        fn_116_2164(p + 0x138C, d);
                        fn_116_2200(p + 0x1370, d);
                        fn_116_38F0(p + 0x133C, d);
                        if (p + 0x1328 != 0) fn_27_C7770(p + 0x1328, d);
                    }
                    if (p + 0x12A8 != 0) {
                        fn_116_2164(p + 0x12D8, d);
                        fn_116_2200(p + 0x12BC, d);
                        if (p + 0x12A8 != 0) fn_27_C7770(p + 0x12A8, d);
                    }
                }
                if (p + 0xCC != 0) {
                    fn_116_394C(p + 0x128C, d);
                    fn_116_39A8(p + 0x124C, d);
                    fn_116_3A04(p + 0x1234, d);
                    fn_116_3A60(p + 0x10DC, d);
                    if (p + 0x1068 != 0) fn_116_3ACC(p + 0x10B4, d);
                    fn_116_3B68(p + 0xFFC, d);
                    if (p + 0xF24 != 0) {
                        fn_116_3CA4(p + 0xF4C, d);
                        fn_116_3D28(p + 0xF38, d);
                        fn_27_C74E8(p + 0xF24, d);
                    }
                    fn_116_3D88(p + 0xE80, d);
                    fn_116_3EBC(p + 0xE4C, d);
                    fn_116_3F18(p + 0xCE4, d);
                    fn_116_3F84(p + 0xCD4, d);
                    fn_116_3FE4(p + 0xCAC, d);
                    fn_116_4040(p + 0xADC, d);
                    fn_116_40C4(p + 0xA78, d);
                    fn_116_4190(p + 0xA3C, d);
                    fn_116_41EC(p + 0x994, d);
                    fn_116_4258(p + 0x8E0, d);
                    if (p + 0x754 != 0) {
                        fn_27_13C90(p + 0x770, d);
                        fn_27_21038(p + 0x75C, d);
                    }
                    if (p + 0x644 != 0) {
                        __dt__17soModelModuleImplFv(p + 0x688, d);
                        fn_27_19A33C(p + 0x644, d);
                    }
                    fn_116_42CC(p + 0x630, d);
                    fn_116_430C(p + 0x618, d);
                    __dt__16soModuleAccesserFv(p + 0x538, d);
                    if (p + 0xCC != 0) {
                        fn_27_1A8CE0(p + 0x4B4, d);
                        fn_27_D7DBC(p + 0x474, d);
                        fn_27_D6B9C(p + 0x438, d);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x3DC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x380)->~soEventUnitWithWorkArea();
                        fn_27_D57AC(p + 0x344, d);
                        fn_27_1A9BB8(p + 0x248, d);
                        fn_27_1A9364(p + 0x198, d);
                        __dt__23soEventManageModuleImplFv(p + 0x184, d);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, static_cast<short>(0));
        }
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
