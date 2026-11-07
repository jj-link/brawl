#include <ac/ac_cmd_interpreter.h>
#include <so/so_module_accesser.h>
#include <so/event/so_event_system.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/posture/so_posture_module_impl.h>

#pragma force_active on

void operator delete(void*);

template <>
class soArrayVector<acCmdInterpreterStackData, 1> {
public:
    ~soArrayVector();
};

class soModelEventObserver;
template <>
class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" {
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_37E8(void*, short);
void* fn_116_38F0(void*, short);
void* fn_116_394C(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_3A60(void*, short);
void* fn_116_3ACC(void*, short);
void* fn_116_3B68(void*, short);
void* fn_116_3CA4(void*, short);
void* fn_116_3D28(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_3F18(void*, short);
void* fn_116_3F84(void*, short);
void* fn_116_3FE4(void*, short);
void* fn_116_40C4(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_42CC(void*, short);
void* fn_116_430C(void*, short);
void* fn_116_4ADC(void*, short);
void* fn_116_4C04(void*, short);
void* fn_116_4C70(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_19AB9C(void*, short);
void* fn_27_19EB34(void*, short);
void* fn_27_1A0184(void*, short);
void* fn_27_1A0FA4(void*, short);
void* fn_27_1A4980(void*, short);
void* fn_27_1A4E94(void*, short);
void* fn_27_1A8EB0(void*, short);
void* fn_27_1A9364(void*, short);
void* fn_27_1A9F58(void*, short);
void* fn_27_1AB16C(void*, short);
void* fn_27_1AB33C(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_93100(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_D6B9C(void*, short);
void* fn_27_D7DBC(void*, short);
}

#pragma opt_common_subs off
#pragma always_inline on
#pragma inline_depth(8)

static inline void destroyGroup(char* p) {
    if (p) {
        short d = -1;
        fn_116_2164(p + 0x64, d);
        fn_116_2200(p + 0x48, d);
        fn_116_38F0(p + 0x14, d);
        if (p)
            fn_27_C7770(p, d);
    }
}

static inline void destroyCollision(char* p) {
    if (p) {
        if (p + 0x2e4) {
            if (p + 0x334) {
                reinterpret_cast<soArrayVector<acCmdInterpreterStackData, 1>*>(
                    p + 0x334)->~soArrayVector();
            }
            fn_116_2164(p + 0x2e4, static_cast<short>(-1));
        }
        destroyGroup(p + 0x230);
        destroyGroup(p + 0x17c);
        destroyGroup(p + 0xc8);
        if (p) {
            short d = -1;
            fn_116_2164(p + 0x78, d);
            fn_116_2200(p + 0x5c, d);
            if (p + 0x14)
                fn_27_1A0FA4(p + 0x14, d);
            if (p)
                fn_27_C7770(p, static_cast<short>(-1));
        }
    }
}

static inline void destroyEvents(char* p) {
    if (p + 0xcc) {
        short d = -1;
        fn_27_1A8EB0(p + 0x510, d);
        fn_27_D7DBC(p + 0x4d0, d);
        fn_27_D6B9C(p + 0x494, d);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(
            p + 0x438)->soEventUnitWithWorkArea<soModelEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_1AB33C(p + 0x3f4, d);
        fn_27_1AB16C(p + 0x3b0, d);
        fn_27_D597C(p + 0x368, d);
        fn_27_1A9F58(p + 0x248, d);
        fn_27_1A9364(p + 0x198, d);
        reinterpret_cast<soEventManageModuleImpl*>(
            p + 0x184)->soEventManageModuleImpl::~soEventManageModuleImpl();
        reinterpret_cast<soInstanceManagerSimpleEntity<
            soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(
            p + 0xcc)->~soInstanceManagerSimpleEntity();
    }
}

static inline void destroyModules(char* p) {
    if (p + 0xcc) {
        short d = -1;
        fn_116_394C(p + 0x14f8, d);
        fn_116_3A04(p + 0x14dc, d);
        fn_116_3A60(p + 0x1384, d);
        if (p + 0x1318) {
            fn_27_93100(p + 0x1348, d);
            fn_27_19EB34(p + 0x1328, d);
            fn_27_1A4E94(p + 0x1318, d);
        }
        if (p + 0x12ac)
            fn_116_3ACC(p + 0x12f4, static_cast<short>(-1));
        {
            short d = -1;
            fn_116_3B68(p + 0x1240, d);
            if (p + 0x10c4) {
                fn_116_3CA4(p + 0x1190, d);
                fn_116_3D28(p + 0x117c, d);
                if (p + 0x115c)
                    fn_27_1A4980(p + 0x115c, d);
                {
                    short d = -1;
                    fn_116_4ADC(p + 0x1108, d);
                    if (p + 0x10d4)
                        fn_116_3ACC(p + 0x10e4, d);
                }
                fn_27_C74E8(p + 0x10c4, static_cast<short>(-1));
            }
        }
        {
            short d = -1;
            fn_116_3D88(p + 0x1020, d);
            fn_116_3EBC(p + 0xfec, d);
            if (p + 0xfd4)
                fn_27_5AE44(p + 0xfd4, d);
        }
        {
            short d = -1;
            fn_116_3F18(p + 0xe70, d);
            if (p + 0xe08)
                fn_27_565F0(p + 0xe14, d);
        }
        {
            short d = -1;
            fn_116_3F84(p + 0xdfc, d);
            fn_116_3FE4(p + 0xdd4, d);
            if (p + 0xc28) {
                reinterpret_cast<soCollisionHitModuleImpl*>(
                    p + 0xd64)->soCollisionHitModuleImpl::~soCollisionHitModuleImpl();
                fn_27_CC984(p + 0xd20, d);
                fn_27_4CAA0(p + 0xc9c, d);
                fn_27_19AB9C(p + 0xc28, d);
            }
        }
        {
            short d = -1;
            fn_116_40C4(p + 0xbc0, d);
            fn_116_4190(p + 0xb84, d);
            fn_116_41EC(p + 0xadc, d);
            if (p + 0x9f8) {
                reinterpret_cast<soPostureModuleImpl*>(
                    p + 0xa64)->soPostureModuleImpl::~soPostureModuleImpl();
                if (p + 0x9f8)
                    fn_27_1A0184(p + 0x9f8, d);
            }
        }
        if (p + 0x81c) {
            short d = -1;
            fn_27_13C90(p + 0x888, d);
            fn_27_21038(p + 0x874, d);
            fn_116_4ADC(p + 0x81c, d);
        }
        {
            short d = -1;
            fn_116_4C04(p + 0x6d8, d);
            fn_116_4C70(p + 0x6a8, d);
            fn_116_42CC(p + 0x698, d);
            fn_116_430C(p + 0x680, d);
            reinterpret_cast<soModuleAccesser*>(
                p + 0x5a0)->soModuleAccesser::~soModuleAccesser();
            destroyEvents(p);
        }
    }
}

static inline void destroyBase(char* p) {
    if (p) {
        short d = -1;
        fn_116_37E8(p + 0x18a4, d);
        fn_27_1DBB60(p + 0x186c, d);
        if (p + 0xcc) {
            destroyCollision(p + 0x1514);
            destroyModules(p);
        }
        fn_27_1D81C8(p, static_cast<short>(0));
    }
}

extern "C" void* fn_116_4648(void* object, int deleting) {
    if (object) {
        destroyBase(static_cast<char*>(object));
        if (static_cast<short>(deleting) > 0)
            operator delete(object);
    }
    return object;
}
