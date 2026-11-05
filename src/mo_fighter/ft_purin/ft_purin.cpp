#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/situation/so_situation_event_presenter.h>
#include <so/so_heap_module_impl.h>
#include <so/status/so_status_event_presenter.h>
#include <so/so_null.h>
#include <StaticAssert.h>
#include <so/status/so_status_module_impl.h>
#include <ft/fighter.h>
#include <ft/ft_entry.h>
#include <ft/ft_extend_param_accesser.h>
#include <ft/ft_fighter_build_data.h>
#include <ft/purin/ft_purin_extend_param_accesser.h>
#include <so/so_array.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/event/so_event_system.h>
#include <so/so_inside_event_manage_module_builder.h>
#include <so/so_instance_unit.h>
#include <so/so_module_accesser.h>
#include <so/template_utils.h>
#include <sr/sr_common.h>
#include <types.h>

#include <ft/ft_cancel_module.h>
#include <ft/ft_param_customize_module_impl.h>
#include <ft/ft_resource_id_accesser_impl.h>
#include <ft/ft_status_uniq_process_gimmick.h>
#include <ft/ft_virtual_node_matrix_pool.h>
#include <so/so_module_accesser_builder.h>
#include <ut/ut_uncopyable.h>

////////////////////////////////////////
// ftAnimCmdModuleSubBuilder
////////////////////////////////////////

template <u32 P1, u32 P2>
class ftAnimCmdModuleSubBuildConfig {
    // TODO
};


template <typename BC>
class ftAnimCmdModuleSubBuilder {
    // TODO
};


// TODO: When the Builder base classes are done, move them to separate headers

template <class BC>
class soModuleAccesserBuilder : public utUnCopyable {
public:
    soInsideEventManageModuleBuilder<typename BC::InsideEventManageModuleBuildConfig, ftInsideEventManageModuleTypes> unk194;
    soModuleAccesser m_moduleAccsr; // +0x9D0 for ft_purin
    soHeapModuleBuilder<typename BC::HeapModuleBuildConfig> m_heapModuleBuilder;
    soParamCustomizeModuleBuilder<typename BC::ParamCustomizeModuleBuildConfig> m_paramCustomizeModuleBuilder;
    soResourceModuleBuilder<typename BC::ResourceModuleBuildConfig> m_resourceModuleBuilder;
    soModelModuleBuilder<typename BC::ModelModuleBuildConfig> m_modelModuleBuilder;

    // TODO: add remaining ModuleBuilders
    // Add getModule() member functions for each Builder

    u8 unkC44[0x8DF4];
    soModuleAccesserBuilder(const ftFighterBuildData& fbd) :
        m_heapModuleBuilder(fbd),
        m_paramCustomizeModuleBuilder(&m_moduleAccsr),
        m_resourceModuleBuilder(
            fbd.getMdlResId(),
            fbd.getAnmResId(),
            fbd.getResGroupNo(),
            &m_moduleAccsr
        ),
        m_modelModuleBuilder(
            &m_moduleAccsr,
            fbd.getModelExtendNodeTable(),
            &g_soEventObserverRegistrationDescNull,
            fbd.getModelScale()
        ) {
    }

    ~soModuleAccesserBuilder() { }
    soModuleAccesser* getModuleAccesser() { return &m_moduleAccsr; }
};

template <typename BC>
class ftModuleAccesserBuilder : public soModuleAccesserBuilder<BC> {
public:
    soArrayContractibleTable<const soStatusData> unkTable;
    ftAnimCmdModuleSubBuilder<typename BC::AnimCmdModuleSubBuildConfig> unkAnimCmdModuleSubBuilder;

    ftModuleAccesserBuilder(const ftFighterBuildData& fbd) : soModuleAccesserBuilder<BC>(fbd) {

    }
};

template<typename BC>
class ftFighterBuilder : public Fighter {
    ftModuleAccesserBuilder<BC> m_moduleBuilder; // +0x194
    ftCancelModuleImpl m_cancelModule;
    ftVirtualNodeMatrixPoolImpl m_virtualNodeMtxPool;
    ftStatusGimmickUniqProcessPoolImpl m_gimmickProcPool;
    u32 unk9A38[2]; // cameraRangeSet TODO type
    u32 unk9A40[2]; // cameraClipSphereSet TODO type
public:
    ftFighterBuilder(s32 entryId,
                     ftKind kind,
                     Heaps::HeapType instHeap,
                     Heaps::HeapType nwModelInstHeap,
                     Heaps::HeapType nwMotionInstHeap) :
        Fighter(entryId, kind, instHeap, &m_moduleBuilder.m_moduleAccsr),
        m_moduleBuilder(ftFighterBuildData(entryId,
                               Fighter_Jigglypuff,
                               instHeap,
                               nwModelInstHeap,
                               nwMotionInstHeap,
                               0,
                               m_moduleAccesser,
                               -1,
                               &unk9A38,
                               &unk9A40)),
        m_cancelModule(m_moduleAccesser),
        m_virtualNodeMtxPool(),
        m_gimmickProcPool(m_moduleAccesser) {
    }
};


////////////////////////////////////////
// Jigglypuff Build Configuration
////////////////////////////////////////

typedef soInsideEventManageModuleBuildConfig<
    32, 40, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 1, 1, 0, 2, 1, ftInsideEventManageModuleTypes
> ftPurinInsideEventManageModuleBuildConfig;
typedef soHeapModuleBuildConfig<soHeapModuleImpl> ftPurinHeapModuleBuildConfig;
typedef soParamCustomizeModuleBuildConfig<ftParamCustomizeModuleImpl> ftPurinParamCustomizeModuleBuildConfig;
typedef soResourceModuleBuildConfigDynamic<0, ftResourceIdAccesserImpl, soResourceModuleImpl> ftPurinResourceModuleBuildConfig;
typedef soModelModuleBuildConfig<8, 3, soModelModuleImpl> ftPurinModelModuleBuildConfig;

typedef ftAnimCmdModuleSubBuildConfig<288, 501> ftPurinAnimCmdModuleSubBuildConfig;

class ftPurinBuildConfig {
public:
    typedef ftPurinInsideEventManageModuleBuildConfig InsideEventManageModuleBuildConfig;
    typedef ftPurinHeapModuleBuildConfig HeapModuleBuildConfig;
    typedef ftPurinParamCustomizeModuleBuildConfig ParamCustomizeModuleBuildConfig;
    typedef ftPurinResourceModuleBuildConfig ResourceModuleBuildConfig;
    typedef ftPurinAnimCmdModuleSubBuildConfig AnimCmdModuleSubBuildConfig;
    typedef ftPurinModelModuleBuildConfig ModelModuleBuildConfig;
};

class ftPurin : public ftFighterBuilder<ftPurinBuildConfig> {

    // begin ftPurin fields
    soArrayContractibleTable<const soStatusData> unk9A48;
    void* unk9A58; // TODO type
public:
    ftPurin(s32 entryId,
            Heaps::HeapType instHeap,
            Heaps::HeapType nwModelInstHeap,
            Heaps::HeapType nwMotionInstHeap);
};
// static_assert(sizeof(ftPurin) == 0x9A5C, "Class is the wrong size!");

ftPurin::ftPurin(s32 entryId,
                 Heaps::HeapType instHeap,
                 Heaps::HeapType nwModelInstHeap,
                 Heaps::HeapType nwMotionInstHeap) :
    ftFighterBuilder<ftPurinBuildConfig>(entryId,
                                         Fighter_Jigglypuff,
                                         instHeap,
                                         nwModelInstHeap,
                                         nwMotionInstHeap) {
    // TODO
}

// FIXME: Test code present only to emit the constructor; delete once ftPurin is done
void testBuilder() {
    soInsideEventManageModuleBuilder<ftPurinInsideEventManageModuleBuildConfig, ftInsideEventManageModuleTypes> insideBuilder;
    soResourceIdAccesserImpl idAccImpl(0, 1, 2);
    ftPopoResourceIdAccesserImpl popoIdAccImpl(nullptr);
    soAnimCmdAddressPackArraySeparate arr(nullptr, nullptr, nullptr);
    (void)arr.at(0);
    (void)arr.size();
    (void)arr.isNull();
}
soInsideEventManageModuleBuilder<ftPurinInsideEventManageModuleBuildConfig, ftInsideEventManageModuleTypes> g_insideBuilder;

ftPurinExtendParamAccesser g_ftPurinExtendParamAccesser;

// decomp-orchestrator: begin fn_124_65A0
#pragma force_active on
namespace decomp_orch_fn_124_65A0 {
extern "C" {
void fn_27_4AC40(void* p, int flag);
void fn_27_4AD20(void* p, short v);
void fn_27_19C31C(void* self, int a, void* buf, int b);
void fn_27_4B184(void* obj, int a, int b, unsigned char c, void* self, void* d, unsigned char e, unsigned char f);
}

extern "C" void* fn_124_65A0(void* self, int a, int b, unsigned char c, void* d)
{
    char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, (short)-1);
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, 1, 1);
    return self;
}
}  // namespace decomp_orch_fn_124_65A0
// decomp-orchestrator: end fn_124_65A0

// decomp-orchestrator: begin fn_124_80C4
#pragma force_active on
namespace decomp_orch_fn_124_80C4 {
extern "C" void fn_27_D3E88(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_124_80C4(void* receiver, short id, int argument) {
    fn_27_D3E88(receiver, id, receiver, static_cast<signed char>(argument));
}
}  // namespace decomp_orch_fn_124_80C4
// decomp-orchestrator: end fn_124_80C4

// decomp-orchestrator: begin fn_124_393C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_393C {
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_393C(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_393C
// decomp-orchestrator: end fn_124_393C

// decomp-orchestrator: begin fn_124_8578
#pragma force_active on
namespace decomp_orch_fn_124_8578 {
extern "C" void fn_124_8578(void* self, int index, float value) {
    float* arr = *reinterpret_cast<float**>(static_cast<char*>(self) + 0x14);
    arr[index] -= value;
}
}  // namespace decomp_orch_fn_124_8578
// decomp-orchestrator: end fn_124_8578

// decomp-orchestrator: begin fn_124_3874
#pragma force_active on
namespace decomp_orch_fn_124_3874 {
extern "C" void fn_124_1E48(void*, short);
extern "C" void fn_124_1EA4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3874(void* self, short flag) {
    if (self != 0) {
        short m = 0;
        fn_124_1E48((char*)self + 0x14, m);
        fn_124_1EA4((char*)self + 8, m);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_3874
// decomp-orchestrator: end fn_124_3874

// decomp-orchestrator: begin fn_124_2BB8
#pragma force_active on
namespace decomp_orch_fn_124_2BB8 {
extern "C" void fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_2BB8(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_C21DC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_2BB8
// decomp-orchestrator: end fn_124_2BB8

// decomp-orchestrator: begin fn_124_304C
#pragma force_active on
namespace decomp_orch_fn_124_304C {
extern "C" void* fn_27_19874C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_304C(void* ptr, short flag)
{
    if (ptr) {
        fn_27_19874C(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_304C
// decomp-orchestrator: end fn_124_304C

// decomp-orchestrator: begin fn_124_5048
#pragma force_active on
namespace decomp_orch_fn_124_5048 {
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_4742C(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CDDE8(void*, short);
void* fn_27_CD78C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_5048(void* self, short del) {
    if (self != 0) {
        fn_27_48BE8((char*)self + 0x1C4, -1);
        fn_27_4742C((char*)self + 0x1B4, -1);
        fn_27_4CAA0((char*)self + 0x130, -1);
        fn_27_CDDE8((char*)self + 0x6C, -1);
        fn_27_CD78C(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_5048
// decomp-orchestrator: end fn_124_5048

// decomp-orchestrator: begin fn_124_331C
#pragma force_active on
namespace decomp_orch_fn_124_331C {
extern "C" void fn_124_337C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_331C(void* p, short flag) {
    if (p != 0) {
        fn_124_337C((char*)p + 4, -1);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_331C
// decomp-orchestrator: end fn_124_331C

// decomp-orchestrator: begin fn_124_3D9C
#pragma force_active on
namespace decomp_orch_fn_124_3D9C {
extern "C" void fn_27_75E0C(void*, short);
extern "C" void fn_27_64930(void*, short);
extern "C" void fn_124_1E48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3D9C(void* object, short flag) {
    if (object != 0) {
        fn_27_75E0C(static_cast<char*>(object) + 0x4C, -1);
        if (static_cast<char*>(object) + 0x20 != 0) {
            fn_27_64930(static_cast<char*>(object) + 0x20, 0);
        }
        fn_124_1E48(static_cast<char*>(object) + 0x14, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}  // namespace decomp_orch_fn_124_3D9C
// decomp-orchestrator: end fn_124_3D9C

// decomp-orchestrator: begin fn_124_4F4C
#pragma force_active on
namespace decomp_orch_fn_124_4F4C {
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4F4C(void* obj, short del) {
    if (obj) {
        fn_27_4B53C(static_cast<unsigned char*>(obj) + 0x17C, static_cast<short>(-1));
        fn_27_19C45C(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}  // namespace decomp_orch_fn_124_4F4C
// decomp-orchestrator: end fn_124_4F4C

// decomp-orchestrator: begin fn_124_411C
#pragma force_active on
namespace decomp_orch_fn_124_411C {
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_124_4194(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_411C(void* p, short flag) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x470, (short)-1);
        if (p != 0) {
            fn_124_4194(p, (short)0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_411C
// decomp-orchestrator: end fn_124_411C

// decomp-orchestrator: begin fn_124_4644
#pragma force_active on
namespace decomp_orch_fn_124_4644 {
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_124_46BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4644(void* p, short flag) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x11c, -1);
        if (p != 0) {
            fn_124_46BC(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4644
// decomp-orchestrator: end fn_124_4644

// decomp-orchestrator: begin fn_124_49C0
#pragma force_active on
namespace decomp_orch_fn_124_49C0 {
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_124_3834(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_49C0(void* p, short flag) {
    if (p != 0) {
        short dtor = -1;
        fn_27_1A2524((char*)p + 0x10, dtor);
        fn_124_3834(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_49C0
// decomp-orchestrator: end fn_124_49C0

// decomp-orchestrator: begin fn_124_5B7C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_5B7C {
// Generated by decomp-orchestrator template solver (getter).



extern "C" u8 fn_124_5B7C(void* self) {
    return *reinterpret_cast<u8*>(reinterpret_cast<u8*>(self) + 0x4);
}
}  // namespace decomp_orch_fn_124_5B7C
// decomp-orchestrator: end fn_124_5B7C

// decomp-orchestrator: begin fn_124_6790
#pragma force_active on
namespace decomp_orch_fn_124_6790 {
extern "C" void fn_27_199DDC(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_124_6790(void* link, void* modules) {
    fn_27_199DDC(link, 6, 0);
    fn_27_6A244((char*)link + 0x144, modules, link);
    return link;
}
}  // namespace decomp_orch_fn_124_6790
// decomp-orchestrator: end fn_124_6790

// decomp-orchestrator: begin fn_124_718C
#pragma force_active on
namespace decomp_orch_fn_124_718C {
typedef unsigned char Byte;

struct WorkPrefix {
    unsigned int header[2];
};

class PurinWork : public WorkPrefix {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6C() = 0;
};

extern "C" void fn_124_6C8C(void*, void*, int, void*, int, void*, int);

extern "C" void* fn_124_718C(Byte* self) {
    fn_124_6C8C(self + 0x1C0, self, 0x4D, self + 0x134, 0x20, self + 0x1B4, 3);
    reinterpret_cast<PurinWork*>(self + 0x1C0)->slot6C();
    return self;
}
}  // namespace decomp_orch_fn_124_718C
// decomp-orchestrator: end fn_124_718C

// decomp-orchestrator: begin fn_124_7790
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_7790 {
// Class_5B5C: vtable slot at offset 0x30 is fn_124_B978 (11th method, index 10).
class Class_5B5C {
public:
    virtual void fn_124_B998();
    virtual void fn_124_B464();
    virtual void fn_124_B85C();
    virtual void fn_124_B468();
    virtual void fn_124_B994();
    virtual void fn_124_B990();
    virtual void fn_124_B98C();
    virtual void fn_124_B988();
    virtual void fn_124_B984();
    virtual void fn_124_B97C();
    virtual void fn_124_B978(int* item);
};

extern "C" void fn_124_7790(Class_5B5C* self, int* items, s32 count) {
    if (items == 0 || count <= 0) {
        return;
    }
    for (s32 i = 0; i < count; i++) {
        self->fn_124_B978(&items[i]);
    }
}
}  // namespace decomp_orch_fn_124_7790
// decomp-orchestrator: end fn_124_7790

// decomp-orchestrator: begin fn_124_80B4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_80B4 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_80B4(void) {}
}  // namespace decomp_orch_fn_124_80B4
// decomp-orchestrator: end fn_124_80B4

// decomp-orchestrator: begin fn_124_80B8
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_80B8 {
// Generated by decomp-orchestrator template solver (getter).



extern "C" u8 fn_124_80B8(void* self) {
    return *reinterpret_cast<u8*>(reinterpret_cast<u8*>(self) + 0x44);
}
}  // namespace decomp_orch_fn_124_80B8
// decomp-orchestrator: end fn_124_80B8

// decomp-orchestrator: begin fn_124_80C0
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_80C0 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_80C0(void) {}
}  // namespace decomp_orch_fn_124_80C0
// decomp-orchestrator: end fn_124_80C0

// decomp-orchestrator: begin fn_124_8100
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8100 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8100(void) {}
}  // namespace decomp_orch_fn_124_8100
// decomp-orchestrator: end fn_124_8100

// decomp-orchestrator: begin fn_124_8104
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8104 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8104(void) {}
}  // namespace decomp_orch_fn_124_8104
// decomp-orchestrator: end fn_124_8104

// decomp-orchestrator: begin fn_124_8194
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8194 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8194(void) {}
}  // namespace decomp_orch_fn_124_8194
// decomp-orchestrator: end fn_124_8194

// decomp-orchestrator: begin fn_124_81C0
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81C0 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81C0(void) {}
}  // namespace decomp_orch_fn_124_81C0
// decomp-orchestrator: end fn_124_81C0

// decomp-orchestrator: begin fn_124_81C4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81C4 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81C4(void) {}
}  // namespace decomp_orch_fn_124_81C4
// decomp-orchestrator: end fn_124_81C4

// decomp-orchestrator: begin fn_124_81C8
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81C8 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81C8(void) {}
}  // namespace decomp_orch_fn_124_81C8
// decomp-orchestrator: end fn_124_81C8

// decomp-orchestrator: begin fn_124_81CC
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81CC {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81CC(void) {}
}  // namespace decomp_orch_fn_124_81CC
// decomp-orchestrator: end fn_124_81CC

// decomp-orchestrator: begin fn_124_81D0
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81D0 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81D0(void) {}
}  // namespace decomp_orch_fn_124_81D0
// decomp-orchestrator: end fn_124_81D0

// decomp-orchestrator: begin fn_124_81D4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81D4 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81D4(void) {}
}  // namespace decomp_orch_fn_124_81D4
// decomp-orchestrator: end fn_124_81D4

// decomp-orchestrator: begin fn_124_81D8
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81D8 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81D8(void) {}
}  // namespace decomp_orch_fn_124_81D8
// decomp-orchestrator: end fn_124_81D8

// decomp-orchestrator: begin fn_124_81DC
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81DC {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81DC(void) {}
}  // namespace decomp_orch_fn_124_81DC
// decomp-orchestrator: end fn_124_81DC

// decomp-orchestrator: begin fn_124_81E0
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81E0 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81E0(void) {}
}  // namespace decomp_orch_fn_124_81E0
// decomp-orchestrator: end fn_124_81E0

// decomp-orchestrator: begin fn_124_81E4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81E4 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81E4(void) {}
}  // namespace decomp_orch_fn_124_81E4
// decomp-orchestrator: end fn_124_81E4

// decomp-orchestrator: begin fn_124_81E8
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81E8 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81E8(void) {}
}  // namespace decomp_orch_fn_124_81E8
// decomp-orchestrator: end fn_124_81E8

// decomp-orchestrator: begin fn_124_81EC
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81EC {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81EC(void) {}
}  // namespace decomp_orch_fn_124_81EC
// decomp-orchestrator: end fn_124_81EC

// decomp-orchestrator: begin fn_124_81F0
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81F0 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81F0(void) {}
}  // namespace decomp_orch_fn_124_81F0
// decomp-orchestrator: end fn_124_81F0

// decomp-orchestrator: begin fn_124_81F4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81F4 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81F4(void) {}
}  // namespace decomp_orch_fn_124_81F4
// decomp-orchestrator: end fn_124_81F4

// decomp-orchestrator: begin fn_124_81F8
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81F8 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_81F8(void) {}
}  // namespace decomp_orch_fn_124_81F8
// decomp-orchestrator: end fn_124_81F8

// decomp-orchestrator: begin fn_124_81FC
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_81FC {
// Generated by decomp-orchestrator template solver (const_return).



extern "C" s32 fn_124_81FC(void) {
    return 0x0;
}
}  // namespace decomp_orch_fn_124_81FC
// decomp-orchestrator: end fn_124_81FC

// decomp-orchestrator: begin fn_124_8204
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8204 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8204(void) {}
}  // namespace decomp_orch_fn_124_8204
// decomp-orchestrator: end fn_124_8204

// decomp-orchestrator: begin fn_124_8208
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8208 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8208(void) {}
}  // namespace decomp_orch_fn_124_8208
// decomp-orchestrator: end fn_124_8208

// decomp-orchestrator: begin fn_124_820C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_820C {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_820C(void) {}
}  // namespace decomp_orch_fn_124_820C
// decomp-orchestrator: end fn_124_820C

// decomp-orchestrator: begin fn_124_8210
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8210 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8210(void) {}
}  // namespace decomp_orch_fn_124_8210
// decomp-orchestrator: end fn_124_8210

// decomp-orchestrator: begin fn_124_823C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_823C {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_823C(void) {}
}  // namespace decomp_orch_fn_124_823C
// decomp-orchestrator: end fn_124_823C

// decomp-orchestrator: begin fn_124_8240
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8240 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8240(void) {}
}  // namespace decomp_orch_fn_124_8240
// decomp-orchestrator: end fn_124_8240

// decomp-orchestrator: begin fn_124_8244
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8244 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8244(void) {}
}  // namespace decomp_orch_fn_124_8244
// decomp-orchestrator: end fn_124_8244

// decomp-orchestrator: begin fn_124_8248
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8248 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8248(void) {}
}  // namespace decomp_orch_fn_124_8248
// decomp-orchestrator: end fn_124_8248

// decomp-orchestrator: begin fn_124_824C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_824C {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_824C(void) {}
}  // namespace decomp_orch_fn_124_824C
// decomp-orchestrator: end fn_124_824C

// decomp-orchestrator: begin fn_124_8250
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8250 {
// Generated by decomp-orchestrator template solver (getter).



extern "C" u32 fn_124_8250(void* self) {
    return *reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 0x110);
}
}  // namespace decomp_orch_fn_124_8250
// decomp-orchestrator: end fn_124_8250

// decomp-orchestrator: begin fn_124_8268
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8268 {
// Generated by decomp-orchestrator template solver (const_return).



extern "C" s32 fn_124_8268(void) {
    return 0x0;
}
}  // namespace decomp_orch_fn_124_8268
// decomp-orchestrator: end fn_124_8268

// decomp-orchestrator: begin fn_124_8270
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8270 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8270(void) {}
}  // namespace decomp_orch_fn_124_8270
// decomp-orchestrator: end fn_124_8270

// decomp-orchestrator: begin fn_124_8274
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8274 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8274(void) {}
}  // namespace decomp_orch_fn_124_8274
// decomp-orchestrator: end fn_124_8274

// decomp-orchestrator: begin fn_124_8278
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8278 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8278(void) {}
}  // namespace decomp_orch_fn_124_8278
// decomp-orchestrator: end fn_124_8278

// decomp-orchestrator: begin fn_124_827C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_827C {
// Generated by decomp-orchestrator template solver (const_return).



extern "C" s32 fn_124_827C(void) {
    return 0x0;
}
}  // namespace decomp_orch_fn_124_827C
// decomp-orchestrator: end fn_124_827C

// decomp-orchestrator: begin fn_124_8284
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8284 {
// Generated by decomp-orchestrator template solver (const_return).



extern "C" s32 fn_124_8284(void) {
    return 0x0;
}
}  // namespace decomp_orch_fn_124_8284
// decomp-orchestrator: end fn_124_8284

// decomp-orchestrator: begin fn_124_828C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_828C {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_828C(void) {}
}  // namespace decomp_orch_fn_124_828C
// decomp-orchestrator: end fn_124_828C

// decomp-orchestrator: begin fn_124_8290
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8290 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8290(void) {}
}  // namespace decomp_orch_fn_124_8290
// decomp-orchestrator: end fn_124_8290

// decomp-orchestrator: begin fn_124_8294
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8294 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8294(void) {}
}  // namespace decomp_orch_fn_124_8294
// decomp-orchestrator: end fn_124_8294

// decomp-orchestrator: begin fn_124_8298
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8298 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_8298(void) {}
}  // namespace decomp_orch_fn_124_8298
// decomp-orchestrator: end fn_124_8298

// decomp-orchestrator: begin fn_124_829C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_829C {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_829C(void) {}
}  // namespace decomp_orch_fn_124_829C
// decomp-orchestrator: end fn_124_829C

// decomp-orchestrator: begin fn_124_82A0
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_82A0 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_124_82A0(void) {}
}  // namespace decomp_orch_fn_124_82A0
// decomp-orchestrator: end fn_124_82A0

// decomp-orchestrator: begin fn_124_8364
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8364 {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_8364(void* self) {
    return reinterpret_cast<u8*>(self) + 0x458;
}
}  // namespace decomp_orch_fn_124_8364
// decomp-orchestrator: end fn_124_8364

// decomp-orchestrator: begin fn_124_836C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_836C {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_836C(void* self) {
    return reinterpret_cast<u8*>(self) + 0x3c8;
}
}  // namespace decomp_orch_fn_124_836C
// decomp-orchestrator: end fn_124_836C

// decomp-orchestrator: begin fn_124_8374
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8374 {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_8374(void* self) {
    return reinterpret_cast<u8*>(self) + 0x8;
}
}  // namespace decomp_orch_fn_124_8374
// decomp-orchestrator: end fn_124_8374

// decomp-orchestrator: begin fn_124_837C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_837C {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_837C(void* self) {
    return reinterpret_cast<u8*>(self) + 0x84;
}
}  // namespace decomp_orch_fn_124_837C
// decomp-orchestrator: end fn_124_837C

// decomp-orchestrator: begin fn_124_8384
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8384 {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_8384(void* self) {
    return reinterpret_cast<u8*>(self) + 0x70;
}
}  // namespace decomp_orch_fn_124_8384
// decomp-orchestrator: end fn_124_8384

// decomp-orchestrator: begin fn_124_838C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_838C {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_838C(void* self) {
    return reinterpret_cast<u8*>(self) + 0x5c;
}
}  // namespace decomp_orch_fn_124_838C
// decomp-orchestrator: end fn_124_838C

// decomp-orchestrator: begin fn_124_8394
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8394 {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_8394(void* self) {
    return reinterpret_cast<u8*>(self) + 0x48;
}
}  // namespace decomp_orch_fn_124_8394
// decomp-orchestrator: end fn_124_8394

// decomp-orchestrator: begin fn_124_839C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_839C {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_839C(void* self) {
    return reinterpret_cast<u8*>(self) + 0x34;
}
}  // namespace decomp_orch_fn_124_839C
// decomp-orchestrator: end fn_124_839C

// decomp-orchestrator: begin fn_124_83A4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_83A4 {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_83A4(void* self) {
    return reinterpret_cast<u8*>(self) + 0x20;
}
}  // namespace decomp_orch_fn_124_83A4
// decomp-orchestrator: end fn_124_83A4

// decomp-orchestrator: begin fn_124_83AC
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_83AC {
// Generated by decomp-orchestrator template solver (adjust_return).



extern "C" void* fn_124_83AC(void* self) {
    return reinterpret_cast<u8*>(self) + 0x8;
}
}  // namespace decomp_orch_fn_124_83AC
// decomp-orchestrator: end fn_124_83AC

// decomp-orchestrator: begin fn_124_8454
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8454 {
// Generated by decomp-orchestrator template solver (getter).



extern "C" u32 fn_124_8454(void* self) {
    return *reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 0x20);
}
}  // namespace decomp_orch_fn_124_8454
// decomp-orchestrator: end fn_124_8454

// decomp-orchestrator: begin fn_124_8530
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_8530 {
// Generated by decomp-orchestrator template solver (getter).



extern "C" u32 fn_124_8530(void* self) {
    return *reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 0x18);
}
}  // namespace decomp_orch_fn_124_8530
// decomp-orchestrator: end fn_124_8530

// decomp-orchestrator: begin fn_124_85C8
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_85C8 {
// Generated by decomp-orchestrator template solver (getter).



extern "C" u32 fn_124_85C8(void* self) {
    return *reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 0x10);
}
}  // namespace decomp_orch_fn_124_85C8
// decomp-orchestrator: end fn_124_85C8

// decomp-orchestrator: begin fn_124_23F8
#pragma force_active on
namespace decomp_orch_fn_124_23F8 {
extern "C" {
void* fn_124_20E0(void*, short);
void __dt__33soAnimCmdAddressPackArraySeparateFv(void*, short);
void* fn_124_21BC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_23F8(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_124_20E0(members + 0xDC, memberDeleting);
        __dt__33soAnimCmdAddressPackArraySeparateFv(members + 0xC0, memberDeleting);
        fn_124_21BC(members + 0x14, memberDeleting);
        if (object != 0)
            fn_27_C7770(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}  // namespace decomp_orch_fn_124_23F8
// decomp-orchestrator: end fn_124_23F8

// decomp-orchestrator: begin fn_124_30A8
#pragma force_active on
namespace decomp_orch_fn_124_30A8 {
extern "C" {
void* fn_27_93100(void*, short);
void* fn_124_312C(void*, short);
void* fn_27_19EFFC(void*, short);
void* fn_27_1A51A0(void*, short);
void __dl__FPv(void*);

void* fn_124_30A8(void* self, short arg1) {
    if (self) {
        short destroy = -1;
        fn_27_93100((char*)self + 0x1724, destroy);
        fn_124_312C((char*)self + 0x40, destroy);
        fn_27_19EFFC((char*)self + 0x14, destroy);
        fn_27_1A51A0(self, destroy);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
}  // namespace decomp_orch_fn_124_30A8
// decomp-orchestrator: end fn_124_30A8

// decomp-orchestrator: begin fn_124_4954
#pragma force_active on
namespace decomp_orch_fn_124_4954 {
extern "C" void* fn_124_49C0(void*, short);
extern "C" void* fn_124_3874(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4954(void* p, short flag) {
    if (p) {
        fn_124_49C0(static_cast<char*>(p) + 0x24, -1);
        fn_124_3874(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4954
// decomp-orchestrator: end fn_124_4954

// decomp-orchestrator: begin fn_124_4B24
#pragma force_active on
namespace decomp_orch_fn_124_4B24 {
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4B24(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_19BFCC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_4B24
// decomp-orchestrator: end fn_124_4B24

// decomp-orchestrator: begin fn_124_2E64
#pragma force_active on
namespace decomp_orch_fn_124_2E64 {
extern "C" {
void* fn_27_CB048(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void* fn_27_197EF4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_2E64(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_27_CB048(members + 0x220, memberDeleting);
        fn_27_199214(members + 0x94, memberDeleting);
        fn_27_A78FC(members + 0x78, memberDeleting);
        fn_27_14E050(members + 0x10, memberDeleting);
        if (object != 0)
            fn_27_197EF4(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}  // namespace decomp_orch_fn_124_2E64
// decomp-orchestrator: end fn_124_2E64

// decomp-orchestrator: begin fn_124_7FFC
#pragma force_active on
namespace decomp_orch_fn_124_7FFC {
extern "C" bool fn_124_7FFC(void*, signed char value)
{
    return value == static_cast<signed char>(0xC);
}
}  // namespace decomp_orch_fn_124_7FFC
// decomp-orchestrator: end fn_124_7FFC

// decomp-orchestrator: begin fn_124_4284
#pragma force_active on
namespace decomp_orch_fn_124_4284 {
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_124_42FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4284(void* p, short flag) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x2fc, -1);
        if (p != 0) {
            fn_124_42FC(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4284
// decomp-orchestrator: end fn_124_4284

// decomp-orchestrator: begin fn_124_2F58
#pragma force_active on
namespace decomp_orch_fn_124_2F58 {
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_124_2FF0(void*, short);
void* fn_124_304C(void*, short);
void* fn_27_CBF58(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_2F58(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_97968(members + 0x6C, memberDeleting);
        fn_27_1CCCC(members + 0x5C, memberDeleting);
        fn_124_2FF0(members + 0x50, memberDeleting);
        fn_124_304C(members + 0x38, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}  // namespace decomp_orch_fn_124_2F58
// decomp-orchestrator: end fn_124_2F58

// decomp-orchestrator: begin fn_124_420C
#pragma force_active on
namespace decomp_orch_fn_124_420C {
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_124_4284(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_420C(void* p, short flag) {
    if (p != 0) {
        fn_27_D2904((char*)p + 0x318, -1);
        if (p != 0) {
            fn_124_4284(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_420C
// decomp-orchestrator: end fn_124_420C

// decomp-orchestrator: begin fn_124_3834
#pragma force_active on
namespace decomp_orch_fn_124_3834 {
extern "C" {
void __dl__FPv(void*);
}

extern "C" void* fn_124_3834(void* p, short size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3834
// decomp-orchestrator: end fn_124_3834

// decomp-orchestrator: begin fn_124_32BC
#pragma force_active on
namespace decomp_orch_fn_124_32BC {
extern "C" void fn_124_331C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_32BC(void* p, int flag) {
    if (p != 0) {
        fn_124_331C((char*)p + 8, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_32BC
// decomp-orchestrator: end fn_124_32BC

// decomp-orchestrator: begin fn_124_74F8
#pragma force_active on
namespace decomp_orch_fn_124_74F8 {
struct FtCommandResources {
    unsigned char calcArea[0x48];
    unsigned char workCalc[0x5C];
    unsigned char mediator[0x6C];
};

extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" FtCommandResources* fn_124_74F8(FtCommandResources* resources,
                                           void* context, int index) {
    fn_27_197FD4(resources, 3, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
}  // namespace decomp_orch_fn_124_74F8
// decomp-orchestrator: end fn_124_74F8

// decomp-orchestrator: begin fn_124_4E20
#pragma force_active on
namespace decomp_orch_fn_124_4E20 {
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_124_4E20(void* ptr, short flag) {
    if (ptr) {
        fn_27_66114(ptr, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_4E20
// decomp-orchestrator: end fn_124_4E20

// decomp-orchestrator: begin fn_124_4554
#pragma force_active on
namespace decomp_orch_fn_124_4554 {
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_124_45CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4554(void* p, short flag) {
    if (p != 0) {
        fn_27_D2904((char*)p + 0x154, -1);
        if (p != 0) {
            fn_124_45CC(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4554
// decomp-orchestrator: end fn_124_4554

// decomp-orchestrator: begin fn_124_2DA8
#pragma force_active on
namespace decomp_orch_fn_124_2DA8 {
extern "C" void fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_2DA8(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_27_ACC5C(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_2DA8
// decomp-orchestrator: end fn_124_2DA8

// decomp-orchestrator: begin fn_124_3F54
#pragma force_active on
namespace decomp_orch_fn_124_3F54 {
extern "C" void fn_124_3FB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3F54(void* ptr, short flag)
{
    if (ptr != 0) {
        if (ptr != 0) {
            fn_124_3FB4(ptr, 0);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_3F54
// decomp-orchestrator: end fn_124_3F54

// decomp-orchestrator: begin fn_124_8108
#pragma force_active on
namespace decomp_orch_fn_124_8108 {
extern "C" void fn_27_D48FC(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_124_8108(void* receiver, short id, int argument) {
    fn_27_D48FC(receiver, id, receiver, static_cast<signed char>(argument));
}
}  // namespace decomp_orch_fn_124_8108
// decomp-orchestrator: end fn_124_8108

// decomp-orchestrator: begin fn_124_4CF4
#pragma force_active on
namespace decomp_orch_fn_124_4CF4 {
extern "C" void fn_27_689B0(void*, short);
extern "C" void fn_27_1985B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4CF4(void* self, short flag) {
    if (self != 0) {
        fn_27_689B0(static_cast<unsigned char*>(self) + 0x7C, -1);
        if (self != 0) {
            fn_27_1985B4(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_4CF4
// decomp-orchestrator: end fn_124_4CF4

// decomp-orchestrator: begin fn_124_8678
#pragma force_active on
namespace decomp_orch_fn_124_8678 {
extern "C" void *fn_124_8678(void *self, unsigned int idx)
{
    void **table = *(void ***)((char *)self + 0xC);
    return table[idx];
}
}  // namespace decomp_orch_fn_124_8678
// decomp-orchestrator: end fn_124_8678

// decomp-orchestrator: begin fn_124_55CC
#pragma force_active on
namespace decomp_orch_fn_124_55CC {
extern "C" void fn_27_19C818(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_55CC(void* ptr, short flag)
{
    if (ptr) {
        fn_27_19C818(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_55CC
// decomp-orchestrator: end fn_124_55CC

// decomp-orchestrator: begin fn_124_5684
#pragma force_active on
namespace decomp_orch_fn_124_5684 {
extern "C" void* fn_124_39D8(void*, short);
extern "C" void* fn_124_56FC(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_5684(void* p, short flag) {
    if (p) {
        fn_124_39D8((char*)p + 0xAC, -1);
        fn_124_56FC((char*)p + 0x20, -1);
        fn_27_CD934(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_5684
// decomp-orchestrator: end fn_124_5684

// decomp-orchestrator: begin fn_124_8600
#pragma force_active on
namespace decomp_orch_fn_124_8600 {
struct FnWork {
    char pad[0xc];
    int *intWorks;
};

extern "C" void fn_124_8600(FnWork *self, int value, unsigned int index) {
    if (value != 0) {
        self->intWorks[index] /= value;
    }
}
}  // namespace decomp_orch_fn_124_8600
// decomp-orchestrator: end fn_124_8600

// decomp-orchestrator: begin fn_124_42FC
#pragma force_active on
namespace decomp_orch_fn_124_42FC {
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void fn_124_4374(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_42FC(void* p, short flag) {
    if (p != 0) {
        fn_27_1A1B88((char*)p + 0x2d0, (short)-1);
        if (p != 0) {
            fn_124_4374(p, (short)0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_42FC
// decomp-orchestrator: end fn_124_42FC

// decomp-orchestrator: begin fn_124_18AC
#pragma force_active on
namespace decomp_orch_fn_124_18AC {
extern "C" {
void* fn_124_194C(char*, short);
void* fn_124_1D2C(char*, short);
void* fn_124_1DC8(char*, short);
void* fn_124_1F00(char*, short);
void* fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_124_18AC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_124_194C(storage + 0x99A0, destroy);
        fn_124_1D2C(storage + 0x94E8, destroy);
        fn_124_1DC8(storage + 0x94AC, destroy);
        fn_124_1F00(storage + 0x194, destroy);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
}  // namespace decomp_orch_fn_124_18AC
// decomp-orchestrator: end fn_124_18AC

// decomp-orchestrator: begin fn_124_3E20
#pragma force_active on
namespace decomp_orch_fn_124_3E20 {
extern "C" void fn_27_1A2B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3E20(void* p, int flag) {
    if (p != 0) {
        fn_27_1A2B08((char*)p + 4, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3E20
// decomp-orchestrator: end fn_124_3E20

// decomp-orchestrator: begin fn_124_7720
#pragma force_active on
namespace decomp_orch_fn_124_7720 {
extern "C" {
extern signed char lbl_124_bss_214;
extern unsigned char lbl_124_bss_218[];
extern unsigned char lbl_124_bss_200[];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_124_7720() {
    if (lbl_124_bss_214 == 0) {
        fn_27_197E44(lbl_124_bss_218);
        __register_global_object(lbl_124_bss_218,
            reinterpret_cast<void*>(fn_27_197E54), lbl_124_bss_200);
        lbl_124_bss_214 = 1;
    }
    return lbl_124_bss_218;
}
}  // namespace decomp_orch_fn_124_7720
// decomp-orchestrator: end fn_124_7720

// decomp-orchestrator: begin fn_124_8144
#pragma force_active on
namespace decomp_orch_fn_124_8144 {
extern "C" void fn_27_D512C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_124_8144(void* receiver, short id, signed char argument) {
    fn_27_D512C(receiver, id, receiver, argument);
}
}  // namespace decomp_orch_fn_124_8144
// decomp-orchestrator: end fn_124_8144

// decomp-orchestrator: begin fn_124_3B54
#pragma force_active on
namespace decomp_orch_fn_124_3B54 {
extern "C" void fn_124_3798(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3B54(void* p, int flag) {
    if (p != 0) {
        fn_124_3798((char*)p + 0x1C0, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3B54
// decomp-orchestrator: end fn_124_3B54

// decomp-orchestrator: begin fn_124_5314
#pragma force_active on
namespace decomp_orch_fn_124_5314 {
extern "C" void* fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_5314(void* ptr, short flag)
{
    if (ptr) {
        fn_27_3544C(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_5314
// decomp-orchestrator: end fn_124_5314

// decomp-orchestrator: begin fn_124_4D68
#pragma force_active on
namespace decomp_orch_fn_124_4D68 {
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_124_4D68(void* p, short flag) {
    if (p) {
        fn_27_69684(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4D68
// decomp-orchestrator: end fn_124_4D68

// decomp-orchestrator: begin fn_124_73CC
#pragma force_active on
namespace decomp_orch_fn_124_73CC {
extern "C" {
void* fn_27_197E94(void* self, unsigned a2, unsigned a3);
void* fn_27_14DFE4(void* p, unsigned a2, unsigned a3, void* a4, void* a5, void* a6, void* a7, unsigned a8, unsigned a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, unsigned a2);
void* fn_27_CAF4C(char* self, unsigned a2);
}

extern "C" void* fn_124_73CC(void* self, unsigned arg2, unsigned arg3, unsigned arg4) {
    fn_27_197E94(self, 1, 0);
    char* p = (char*)self;
    fn_27_14DFE4(p + 0x10, arg2, (unsigned char)arg3, p + 0x220, p + 0x94, p + 0x78, self, arg4, 8);
    fn_27_A78C0(p + 0x78);
    fn_27_1991F0(p + 0x94, 0);
    fn_27_CAF4C(p + 0x220, 0);
    return self;
}
}  // namespace decomp_orch_fn_124_73CC
// decomp-orchestrator: end fn_124_73CC

// decomp-orchestrator: begin fn_124_1F7C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_1F7C {
extern "C" {
void* fn_124_2054(void*, short);
void* fn_124_2218(void*, short);
void* fn_124_22E0(void*, short);
void* fn_124_236C(void*, short);
void* fn_124_23F8(void*, short);
void* fn_124_2484(void*, short);
void* fn_124_2510(void*, short);
void* fn_124_259C(void*, short);
void* fn_124_2628(void*, short);
void* fn_124_26B4(void*, short);
void* fn_124_2740(void*, short);
void __dl__FPv(void*);

void* fn_124_1F7C(void* self, short del) {
    if (self) {
        fn_124_2054((char*)self + 0x14B8, -1);
        fn_124_2218((char*)self + 0x1394, -1);
        fn_124_22E0((char*)self + 0x1268, -1);
        fn_124_236C((char*)self + 0x113C, -1);
        fn_124_23F8((char*)self + 0x1010, -1);
        fn_124_2484((char*)self + 0xEE4, -1);
        fn_124_2510((char*)self + 0xDB8, -1);
        fn_124_259C((char*)self + 0xC8C, -1);
        fn_124_2628((char*)self + 0xB60, -1);
        fn_124_26B4((char*)self + 0xA34, -1);
        fn_124_2740(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
}  // namespace decomp_orch_fn_124_1F7C
// decomp-orchestrator: end fn_124_1F7C

// decomp-orchestrator: begin fn_124_5830
#pragma force_active on
namespace decomp_orch_fn_124_5830 {
extern "C" void* fn_27_CC7EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_5830(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_27_CC7EC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_5830
// decomp-orchestrator: end fn_124_5830

// decomp-orchestrator: begin fn_124_85E8
#pragma force_active on
namespace decomp_orch_fn_124_85E8 {
struct Fn12485E8Owner {
    unsigned char pad[0xc];
    int* counts;
};

extern "C" void fn_124_85E8(Fn12485E8Owner* owner, int index) {
    int* counts = owner->counts;
    counts[index] = counts[index] + 1;
}
}  // namespace decomp_orch_fn_124_85E8
// decomp-orchestrator: end fn_124_85E8

// decomp-orchestrator: begin fn_124_4894
#pragma force_active on
namespace decomp_orch_fn_124_4894 {
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4894(void* ptr, short flag)
{
    if (ptr != 0) {
        if (ptr != 0) {
            fn_27_1A15B8(ptr, -1);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_4894
// decomp-orchestrator: end fn_124_4894

// decomp-orchestrator: begin fn_124_8518
#pragma force_active on
namespace decomp_orch_fn_124_8518 {
struct FlagHolder {
    char pad[0x1c];
    unsigned int *table;
};

extern "C" {
void fn_124_8518(FlagHolder *self, unsigned int flags, unsigned int index) {
    self->table[index] |= flags;
}
}
}  // namespace decomp_orch_fn_124_8518
// decomp-orchestrator: end fn_124_8518

// decomp-orchestrator: begin fn_124_1B7C
#pragma force_active on
namespace decomp_orch_fn_124_1B7C {
extern "C" void fn_124_1A60(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_1B7C(void* ptr, short flag)
{
    if (ptr) {
        fn_124_1A60(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_1B7C
// decomp-orchestrator: end fn_124_1B7C

// decomp-orchestrator: begin fn_124_45CC
#pragma force_active on
namespace decomp_orch_fn_124_45CC {
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_124_4644(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_45CC(void* p, short flag) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x138, -1);
        if (p != 0) {
            fn_124_4644(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_45CC
// decomp-orchestrator: end fn_124_45CC

// decomp-orchestrator: begin fn_124_5570
#pragma force_active on
namespace decomp_orch_fn_124_5570 {
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_124_5570(void* ptr, short flag) {
    if (ptr) {
        fn_27_1A75E4(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_5570
// decomp-orchestrator: end fn_124_5570

// decomp-orchestrator: begin fn_124_3188
#pragma force_active on
namespace decomp_orch_fn_124_3188 {
extern "C" void fn_124_31F8(void*, short);
extern "C" void fn_124_3B14(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3188(void* p, short flag) {
    if (p != 0) {
        fn_124_31F8((char*)p + 8, -1);
        fn_124_3B14(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3188
// decomp-orchestrator: end fn_124_3188

// decomp-orchestrator: begin fn_124_3A38
#pragma force_active on
namespace decomp_orch_fn_124_3A38 {
extern "C" {
void __dl__FPv(void*);
void* fn_124_3A38(void* p, short size);
}

extern "C" void* fn_124_3A38(void* p, short size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3A38
// decomp-orchestrator: end fn_124_3A38

// decomp-orchestrator: begin fn_124_5ED8
#pragma force_active on
namespace decomp_orch_fn_124_5ED8 {
extern "C" {
void fn_124_5AA4(void*, int);
extern unsigned char lbl_27_data_2C030[];
void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);
}

extern "C" void* fn_124_5ED8(void* object, void* arg1, void* arg2, int kind, void* resource) {
    fn_124_5AA4(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 8) = resource;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        static_cast<unsigned char*>(object) + 0xC, 0, object, static_cast<unsigned char>(kind));
    return object;
}
}  // namespace decomp_orch_fn_124_5ED8
// decomp-orchestrator: end fn_124_5ED8

// decomp-orchestrator: begin fn_124_1D88
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_1D88 {
extern "C" void __dl__FPv(void*);
extern "C" void* fn_124_1D88(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_1D88
// decomp-orchestrator: end fn_124_1D88

// decomp-orchestrator: begin fn_124_3C8C
#pragma force_active on
void operator delete(void*);
namespace decomp_orch_fn_124_3C8C {
extern "C" {
void fn_124_1EA4(void*, short);
void fn_124_1E48(void*, short);
}

extern "C" void* fn_124_3C8C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_124_1EA4(storage + 0x20, 0);
        if (object != 0) {
            fn_124_1E48(storage + 0x8, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}  // namespace decomp_orch_fn_124_3C8C
// decomp-orchestrator: end fn_124_3C8C

// decomp-orchestrator: begin fn_124_3EDC
#pragma force_active on
namespace decomp_orch_fn_124_3EDC {
extern "C" void* fn_124_39D8(void*, short);
extern "C" void* fn_124_3F54(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3EDC(void* p, short flag) {
    if (p) {
        fn_124_39D8((char*)p + 0x85C, -1);
        fn_124_3F54((char*)p + 0x19C, -1);
        fn_27_19E99C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3EDC
// decomp-orchestrator: end fn_124_3EDC

// decomp-orchestrator: begin fn_124_5258
#pragma force_active on
namespace decomp_orch_fn_124_5258 {
extern "C" void* fn_124_393C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_5258(void* ptr, short flag)
{
    if (ptr != 0) {
        if (ptr != 0) {
            fn_124_393C(ptr, 0);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_5258
// decomp-orchestrator: end fn_124_5258

// decomp-orchestrator: begin fn_124_3AB8
#pragma force_active on
namespace decomp_orch_fn_124_3AB8 {
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3AB8(void* object, short shouldDelete) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}  // namespace decomp_orch_fn_124_3AB8
// decomp-orchestrator: end fn_124_3AB8

// decomp-orchestrator: begin fn_124_43EC
#pragma force_active on
namespace decomp_orch_fn_124_43EC {
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_124_4464(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_43EC(void* p, short flag) {
    if (p != 0) {
        fn_27_1A1B88((char*)p + 0x218, -1);
        if (p != 0) {
            fn_124_4464(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_43EC
// decomp-orchestrator: end fn_124_43EC

// decomp-orchestrator: begin fn_124_397C
#pragma force_active on
namespace decomp_orch_fn_124_397C {
extern "C" void fn_27_C96C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_397C(void* arg0, short arg1) {
    if (arg0 != 0) {
        fn_27_C96C0(arg0, -1);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}  // namespace decomp_orch_fn_124_397C
// decomp-orchestrator: end fn_124_397C

// decomp-orchestrator: begin fn_124_6334
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_part.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/so_array.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on
namespace decomp_orch_fn_124_6334 {
extern "C" {
void fn_27_19B5C4(void* hitPartVector, int size, const soCollisionHitPart* element, int param3);
void fn_27_CB6E0(void* collisionGroupVector, int size, int param2);
void fn_27_CC8F4(void* collisionHitGroupVector, int size, int param2);
}

extern "C" void* fn_124_6334(void* config, soModuleAccesser* moduleAccesser, int taskId,
                             unsigned char taskCategory,
                             soEventObserverRegistrationDesc* registrationDesc) {
    unsigned char* storage = static_cast<unsigned char*>(config);
    {
        soCollisionHitPart hitPart(soCollision::Category_Fighter, 0x3FF);
        fn_27_19B5C4(storage, 20, &hitPart, 0);
    }
    fn_27_CB6E0(storage + 0x82C, 1, 0);
    fn_27_CC8F4(storage + 0x8B0, 1, 0);
    new (storage + 0x8F4) soCollisionHitModuleImpl(
        moduleAccesser, taskId, static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionHitPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x82C),
        reinterpret_cast<soArray<soCollisionHitGroup>*>(storage + 0x8B0),
        registrationDesc, true);
    return config;
}
}  // namespace decomp_orch_fn_124_6334
// decomp-orchestrator: end fn_124_6334

// decomp-orchestrator: begin fn_124_40A4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_40A4 {
namespace decomp_orch_fn_124_40A4 {
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_124_411C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_40A4(void* p, short flag) {
    if (p != 0) {
        short neg = -1;
        fn_27_1A1B88((char*)p + 0x48c, neg);
        if (p != 0) {
            short zero = 0;
            fn_124_411C(p, zero);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_40A4
}  // namespace decomp_orch_fn_124_40A4
// decomp-orchestrator: end fn_124_40A4

// decomp-orchestrator: begin fn_124_67E4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_67E4 {
namespace decomp_orch_fn_124_67E4 {
extern "C" {
void fn_27_1999C4(void*, int, int);
void fn_27_19BF3C(void*, int, int);
void fn_27_150320(void*, void*, short, void*, void*);
}

extern "C" void* fn_124_67E4(char* self, void* arg, short arg2) {
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(self + 0x584, 2, 0);
    fn_27_150320(self + 0x5b8, arg, arg2, self, self + 0x584);
    return self;
}
}  // namespace decomp_orch_fn_124_67E4
}  // namespace decomp_orch_fn_124_67E4
// decomp-orchestrator: end fn_124_67E4

// decomp-orchestrator: begin fn_124_31F8
#pragma force_active on
namespace decomp_orch_fn_124_31F8 {
namespace decomp_orch_fn_124_31F8 {
extern "C" void* fn_124_32BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_31F8(void* p, short flag) {
    if (p != 0) {
        if (p != 0) {
            short memberDeleting = -1;
            fn_124_32BC((char*)p + 4, memberDeleting);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
}  // namespace decomp_orch_fn_124_31F8
// decomp-orchestrator: end fn_124_31F8

// decomp-orchestrator: begin fn_124_236C
#pragma force_active on
namespace decomp_orch_fn_124_236C {
extern "C" {
void* fn_124_20E0(void*, short);
void __dt__33soAnimCmdAddressPackArraySeparateFv(void*, short);
void* fn_124_21BC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_236C(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_124_20E0(members + 0xDC, memberDeleting);
        __dt__33soAnimCmdAddressPackArraySeparateFv(members + 0xC0, memberDeleting);
        fn_124_21BC(members + 0x14, memberDeleting);
        if (object != 0)
            fn_27_C7770(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}  // namespace decomp_orch_fn_124_236C
// decomp-orchestrator: end fn_124_236C

// decomp-orchestrator: begin fn_124_194C
#pragma force_active on
namespace decomp_orch_fn_124_194C {
extern "C" {
void* fn_124_1A04(void*, short);
void* fn_124_1AC4(void*, short);
void* fn_124_1B20(void*, short);
void* fn_124_1B7C(void*, short);
void* fn_124_1BD8(void*, short);
void* fn_124_1C34(void*, short);
void* fn_124_1C90(void*, short);
void* fn_124_1CEC(void*, short);
void __dl__FPv(void*);
}
extern "C" void* fn_124_194C(char* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_124_1A04(object + 0x84, memberDeleting);
        fn_124_1AC4(object + 0x70, memberDeleting);
        fn_124_1B20(object + 0x5C, memberDeleting);
        fn_124_1B7C(object + 0x48, memberDeleting);
        fn_124_1BD8(object + 0x34, memberDeleting);
        fn_124_1C34(object + 0x20, memberDeleting);
        fn_124_1C90(object + 8, memberDeleting);
        fn_124_1CEC(object, static_cast<short>(0));
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}  // namespace decomp_orch_fn_124_194C
// decomp-orchestrator: end fn_124_194C

// decomp-orchestrator: begin fn_124_8590
#pragma force_active on
namespace decomp_orch_fn_124_8590 {
extern "C" void fn_124_8590(void* obj, int index, float value) {
    float* arr = *(float**)((char*)obj + 0x14);
    arr[index] += value;
}
}  // namespace decomp_orch_fn_124_8590
// decomp-orchestrator: end fn_124_8590

// decomp-orchestrator: begin fn_124_4A30
#pragma force_active on
namespace decomp_orch_fn_124_4A30 {
extern "C" void fn_27_B21D0(void*, short);
extern "C" void fn_27_CB4A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4A30(void* self, short flag) {
    if (self != 0) {
        fn_27_B21D0(static_cast<char*>(self) + 0x50, -1);
        if (self != 0) {
            fn_27_CB4A0(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_4A30
// decomp-orchestrator: end fn_124_4A30

// decomp-orchestrator: begin fn_124_8180
#pragma force_active on
namespace decomp_orch_fn_124_8180 {
extern "C" void fn_27_1A8014(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_124_8180(void* receiver, short id, int argument) {
    fn_27_1A8014(receiver, id, receiver, static_cast<signed char>(argument));
}
}  // namespace decomp_orch_fn_124_8180
// decomp-orchestrator: end fn_124_8180

// decomp-orchestrator: begin fn_124_808C
#include <types.h>
#pragma dont_inline on
#pragma force_active on
namespace decomp_orch_fn_124_808C {
#ifndef STATIC_CHECK
class soAnimCmdEventObserver;
template <class T>
class soEventObserver {
public:
    void addObserverSub(s32 manageId, T* obsvr, s8 p3);
};
#endif



extern "C" void fn_124_808C(soAnimCmdEventObserver* self, short id, int argument) {
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(self)->addObserverSub(id, self, static_cast<s8>(argument));
}
}  // namespace decomp_orch_fn_124_808C
// decomp-orchestrator: end fn_124_808C

// decomp-orchestrator: begin fn_124_1AC4
#pragma force_active on
namespace decomp_orch_fn_124_1AC4 {
namespace decomp_orch_fn_124_1AC4 {
extern "C" void fn_124_1A60(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_1AC4(void* ptr, short flag)
{
    if (ptr) {
        fn_124_1A60(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_1AC4
}  // namespace decomp_orch_fn_124_1AC4
// decomp-orchestrator: end fn_124_1AC4

// decomp-orchestrator: begin fn_124_1F00
#pragma force_active on
namespace decomp_orch_fn_124_1F00 {
namespace decomp_orch_fn_124_1F00 {
extern "C" {
void* fn_124_1F7C(void*, short);
void* fn_124_2834(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_1F00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_124_1F7C(members + 0x7D34, memberDeleting);
        fn_27_C74E8(members + 0x7D24, memberDeleting);
        fn_124_2834(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}  // namespace decomp_orch_fn_124_1F00
}  // namespace decomp_orch_fn_124_1F00
// decomp-orchestrator: end fn_124_1F00

// decomp-orchestrator: begin fn_124_6700
#pragma force_active on
namespace decomp_orch_fn_124_6700 {
extern "C" {
extern char lbl_124_data_ED0[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
}

extern "C" void* fn_124_6700(void* self, void* a, void* b, void* c)
{
    *(void**)self = lbl_124_data_ED0;
    for (int i = 0; i < 2; ++i) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    int one = 1;
    fn_27_561E0((char*)self + 0x14, a, self, b, one, true, c);
    return self;
}
}  // namespace decomp_orch_fn_124_6700
// decomp-orchestrator: end fn_124_6700

// decomp-orchestrator: begin fn_124_37F4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_37F4 {
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_37F4(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_37F4
// decomp-orchestrator: end fn_124_37F4

// decomp-orchestrator: begin fn_124_3C2C
#pragma force_active on
namespace decomp_orch_fn_124_3C2C {
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3C2C(void* p, short flag) {
    if (p != 0) {
        fn_27_1A20EC((char*)p + 0x10, -1);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3C2C
// decomp-orchestrator: end fn_124_3C2C

// decomp-orchestrator: begin fn_124_1E48
#pragma force_active on
namespace decomp_orch_fn_124_1E48 {
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_1E48(void* ptr, short flag) {
    if (ptr) {
        fn_27_7700(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_1E48
// decomp-orchestrator: end fn_124_1E48

// decomp-orchestrator: begin fn_124_2628
#include <so/anim/so_anim_cmd_module_impl.h>
#pragma force_active on
namespace decomp_orch_fn_124_2628 {
extern "C" {
void* fn_124_20E0(void*, short);
void __dt__33soAnimCmdAddressPackArraySeparateFv(void*, short);
void* fn_124_21BC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_2628(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_124_20E0(members + 0xDC, memberDeleting);
        __dt__33soAnimCmdAddressPackArraySeparateFv(members + 0xC0, memberDeleting);
        fn_124_21BC(members + 0x14, memberDeleting);
        if (object != 0)
            fn_27_C7770(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}  // namespace decomp_orch_fn_124_2628
// decomp-orchestrator: end fn_124_2628

// decomp-orchestrator: begin fn_124_3D00
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_3D00 {
extern "C" {
void* fn_124_3D9C(void*, short);
void* fn_124_3E20(void*, short);
void* fn_124_3E80(void*, short);
void* fn_124_3EDC(void*, short);
void* fn_124_48F4(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_3D00(void* self, short del) {
    if (self != 0) {
        fn_124_3D9C(static_cast<char*>(self) + 0xDE4, -1);
        fn_124_3E20(static_cast<char*>(self) + 0xDD0, -1);
        fn_124_3E80(static_cast<char*>(self) + 0x944, -1);
        fn_124_3EDC(static_cast<char*>(self) + 0xD0, -1);
        fn_124_48F4(static_cast<char*>(self) + 0x10, -1);
        fn_27_C74E8(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_3D00
// decomp-orchestrator: end fn_124_3D00

// decomp-orchestrator: begin fn_124_3E80
#pragma force_active on
namespace decomp_orch_fn_124_3E80 {
extern "C" void fn_27_1A3940(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3E80(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_27_1A3940(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_3E80
// decomp-orchestrator: end fn_124_3E80

// decomp-orchestrator: begin fn_124_5628
#pragma force_active on
namespace decomp_orch_fn_124_5628 {
namespace decomp_orch_fn_124_5628 {
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_5628(void* p, short flag) {
    if (p != 0) {
        fn_27_C9EDC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_5628
}  // namespace decomp_orch_fn_124_5628
// decomp-orchestrator: end fn_124_5628

// decomp-orchestrator: begin fn_124_27D8
#pragma force_active on
namespace decomp_orch_fn_124_27D8 {
extern "C" void fn_27_1A60DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_27D8(void* self, short flag)
{
    if (self != 0) {
        short memberDeleting = -1;
        fn_27_1A60DC(self, memberDeleting);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_27D8
// decomp-orchestrator: end fn_124_27D8

// decomp-orchestrator: begin fn_124_4464
#pragma force_active on
namespace decomp_orch_fn_124_4464 {
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_124_44DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4464(void* p, short flag) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x1fc, -1);
        if (p != 0) {
            fn_124_44DC(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4464
// decomp-orchestrator: end fn_124_4464

// decomp-orchestrator: begin fn_124_2C70
#pragma force_active on
namespace decomp_orch_fn_124_2C70 {
extern "C" {
void* fn_27_B81C4(void*, short);
void fn_124_2CF0(void*, short);
void* fn_27_198034(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_2C70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_B81C4(storage + 0xA4, destroy);
        fn_124_2CF0(storage + 0x48, destroy);
        if (object != 0) {
            fn_27_198034(object, destroy);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}  // namespace decomp_orch_fn_124_2C70
// decomp-orchestrator: end fn_124_2C70

// decomp-orchestrator: begin fn_124_1EA4
#pragma force_active on
namespace decomp_orch_fn_124_1EA4 {
extern "C" void fn_27_1362C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_1EA4(void* ptr, short flag)
{
    if (ptr) {
        short zero = 0;
        fn_27_1362C(ptr, zero);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_1EA4
// decomp-orchestrator: end fn_124_1EA4

// decomp-orchestrator: begin fn_124_4CB4
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_4CB4 {
extern "C" void __dl__FPv(void*);
extern "C" void* fn_124_4CB4(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_4CB4
// decomp-orchestrator: end fn_124_4CB4

// decomp-orchestrator: begin fn_124_7A74
#include <so/so_module_accesser.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on
namespace decomp_orch_fn_124_7A74 {
extern "C" void fn_124_7A74(void*, void* event, soModuleAccesser* accesser) {
    if (*((unsigned char*)event + 0x21) == 1) {
        switch (accesser->m_enumerationStart->m_statusModule->getStatusKind()) {
        case 0x119:
        case 0x11a:
            accesser->m_enumerationStart->m_workManageModule->onFlag(0x22000012);
            break;
        }
    }
}
}  // namespace decomp_orch_fn_124_7A74
// decomp-orchestrator: end fn_124_7A74

// decomp-orchestrator: begin fn_124_53DC
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_53DC {
extern "C" void __dt__19soPostureModuleImplFv(void*, short);
extern "C" void fn_27_19FFEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_53DC(void* self, short flag) {
    if (self != 0) {
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(self) + 0x3C, -1);
        if (self != 0) {
            fn_27_19FFEC(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_53DC
// decomp-orchestrator: end fn_124_53DC

// decomp-orchestrator: begin getParamIndefinite__21ftExtendParamAccesserFP16soModuleAccesserll
#pragma force_active on
namespace decomp_orch_getParamIndefinite__21ftExtendParamAccesserFP16soModuleAccesserll {
extern "C" void* getParamIndefinite__21ftExtendParamAccesserFP16soModuleAccesserll(void) { return 0; }
}  // namespace decomp_orch_getParamIndefinite__21ftExtendParamAccesserFP16soModuleAccesserll
// decomp-orchestrator: end getParamIndefinite__21ftExtendParamAccesserFP16soModuleAccesserll

// decomp-orchestrator: begin fn_124_51E0
#pragma force_active on
namespace decomp_orch_fn_124_51E0 {
namespace decomp_orch_fn_124_51E0 {
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_124_5258(void*, short);
extern "C" void* fn_124_52B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_51E0(void* p, short flag) {
    if (p != 0) {
        short neg = -1;
        fn_27_B5324((char*)p + 0x30, neg);
        fn_124_5258((char*)p + 0x18, neg);
        fn_124_52B8((char*)p + 0x4, neg);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}  // namespace decomp_orch_fn_124_51E0
}  // namespace decomp_orch_fn_124_51E0
// decomp-orchestrator: end fn_124_51E0

// decomp-orchestrator: begin fn_124_2D4C
#pragma force_active on
namespace decomp_orch_fn_124_2D4C {
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_2D4C(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_27_B64B8(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_2D4C
// decomp-orchestrator: end fn_124_2D4C

// decomp-orchestrator: begin fn_124_515C
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/situation/so_situation_event_presenter.h>
#include <so/so_heap_module_impl.h>
#include <so/status/so_status_event_presenter.h>
#include <so/so_null.h>
#include <StaticAssert.h>
#include <so/status/so_status_module_impl.h>
#include <ft/fighter.h>
#include <ft/ft_entry.h>
#include <ft/ft_extend_param_accesser.h>
#include <ft/ft_fighter_build_data.h>
#include <ft/purin/ft_purin_extend_param_accesser.h>
#include <so/so_array.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/event/so_event_system.h>
#include <so/so_inside_event_manage_module_builder.h>
#include <so/so_instance_unit.h>
#include <so/so_module_accesser.h>
#include <so/template_utils.h>
#include <sr/sr_common.h>
#include <types.h>
#include <ft/ft_cancel_module.h>
#include <ft/ft_param_customize_module_impl.h>
#include <ft/ft_resource_id_accesser_impl.h>
#include <ft/ft_status_uniq_process_gimmick.h>
#include <ft/ft_virtual_node_matrix_pool.h>
#include <so/so_module_accesser_builder.h>
#include <ut/ut_uncopyable.h>
#pragma force_active on
namespace decomp_orch_fn_124_515C {
template <u32 P1, u32 P2>
class ftAnimCmdModuleSubBuildConfig {
    // TODO
};

template <typename BC>
class ftAnimCmdModuleSubBuilder {
    // TODO
};

template <class BC>
class soModuleAccesserBuilder : public utUnCopyable {
public:
    soInsideEventManageModuleBuilder<typename BC::InsideEventManageModuleBuildConfig, ftInsideEventManageModuleTypes> unk194;
    soModuleAccesser m_moduleAccsr; // +0x9D0 for ft_purin
    soHeapModuleBuilder<typename BC::HeapModuleBuildConfig> m_heapModuleBuilder;
    soParamCustomizeModuleBuilder<typename BC::ParamCustomizeModuleBuildConfig> m_paramCustomizeModuleBuilder;
    soResourceModuleBuilder<typename BC::ResourceModuleBuildConfig> m_resourceModuleBuilder;
    soModelModuleBuilder<typename BC::ModelModuleBuildConfig> m_modelModuleBuilder;

    u8 unkC44[0x8DF4];
    soModuleAccesserBuilder(const ftFighterBuildData& fbd) :
        m_heapModuleBuilder(fbd),
        m_paramCustomizeModuleBuilder(&m_moduleAccsr),
        m_resourceModuleBuilder(
            fbd.getMdlResId(),
            fbd.getAnmResId(),
            fbd.getResGroupNo(),
            &m_moduleAccsr
        ),
        m_modelModuleBuilder(
            &m_moduleAccsr,
            fbd.getModelExtendNodeTable(),
            &g_soEventObserverRegistrationDescNull,
            fbd.getModelScale()
        ) {
    }

    ~soModuleAccesserBuilder() { }
    soModuleAccesser* getModuleAccesser() { return &m_moduleAccsr; }
};

template <typename BC>
class ftModuleAccesserBuilder : public soModuleAccesserBuilder<BC> {
public:
    soArrayContractibleTable<const soStatusData> unkTable;
    ftAnimCmdModuleSubBuilder<typename BC::AnimCmdModuleSubBuildConfig> unkAnimCmdModuleSubBuilder;

    ftModuleAccesserBuilder(const ftFighterBuildData& fbd) : soModuleAccesserBuilder<BC>(fbd) {
    }
};

template<typename BC>
class ftFighterBuilder : public Fighter {
    ftModuleAccesserBuilder<BC> m_moduleBuilder; // +0x194
    ftCancelModuleImpl m_cancelModule;
    ftVirtualNodeMatrixPoolImpl m_virtualNodeMtxPool;
    ftStatusGimmickUniqProcessPoolImpl m_gimmickProcPool;
    u32 unk9A38[2]; // cameraRangeSet TODO type
    u32 unk9A40[2]; // cameraClipSphereSet TODO type
public:
    ftFighterBuilder(s32 entryId,
                     ftKind kind,
                     Heaps::HeapType instHeap,
                     Heaps::HeapType nwModelInstHeap,
                     Heaps::HeapType nwMotionInstHeap) :
        Fighter(entryId, kind, instHeap, &m_moduleBuilder.m_moduleAccsr),
        m_moduleBuilder(ftFighterBuildData(entryId,
                               Fighter_Jigglypuff,
                               instHeap,
                               nwModelInstHeap,
                               nwMotionInstHeap,
                               0,
                               m_moduleAccesser,
                               -1,
                               &unk9A38,
                               &unk9A40)),
        m_cancelModule(m_moduleAccesser),
        m_virtualNodeMtxPool(),
        m_gimmickProcPool(m_moduleAccesser) {
    }
};

typedef soInsideEventManageModuleBuildConfig<
    32, 40, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 1, 1, 0, 2, 1, ftInsideEventManageModuleTypes
> ftPurinInsideEventManageModuleBuildConfig;
typedef soHeapModuleBuildConfig<soHeapModuleImpl> ftPurinHeapModuleBuildConfig;
typedef soParamCustomizeModuleBuildConfig<ftParamCustomizeModuleImpl> ftPurinParamCustomizeModuleBuildConfig;
typedef soResourceModuleBuildConfigDynamic<0, ftResourceIdAccesserImpl, soResourceModuleImpl> ftPurinResourceModuleBuildConfig;
typedef soModelModuleBuildConfig<8, 3, soModelModuleImpl> ftPurinModelModuleBuildConfig;

typedef ftAnimCmdModuleSubBuildConfig<288, 501> ftPurinAnimCmdModuleSubBuildConfig;

class ftPurinBuildConfig {
public:
    typedef ftPurinInsideEventManageModuleBuildConfig InsideEventManageModuleBuildConfig;
    typedef ftPurinHeapModuleBuildConfig HeapModuleBuildConfig;
    typedef ftPurinParamCustomizeModuleBuildConfig ParamCustomizeModuleBuildConfig;
    typedef ftPurinResourceModuleBuildConfig ResourceModuleBuildConfig;
    typedef ftPurinAnimCmdModuleSubBuildConfig AnimCmdModuleSubBuildConfig;
    typedef ftPurinModelModuleBuildConfig ModelModuleBuildConfig;
};

class ftPurin : public ftFighterBuilder<ftPurinBuildConfig> {
    soArrayContractibleTable<const soStatusData> unk9A48;
    void* unk9A58; // TODO type
public:
    ftPurin(s32 entryId,
            Heaps::HeapType instHeap,
            Heaps::HeapType nwModelInstHeap,
            Heaps::HeapType nwMotionInstHeap);
};

// decomp-orchestrator: begin fn_124_515C

namespace decomp_orch_fn_124_515C {
extern "C" {
void __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_1A12AC(void*, short);
void* fn_27_CB998(void*, short);
void* fn_27_CD1F0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_515C(void* self, short del) {
    if (self != 0) {
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv((char*)self + 0x61C, destroy);
        fn_27_1A12AC((char*)self + 0x540, destroy);
        fn_27_CB998((char*)self + 0x2DC, destroy);
        fn_27_CD1F0(self, destroy);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_515C
// decomp-orchestrator: end fn_124_515C
}  // namespace decomp_orch_fn_124_515C
// decomp-orchestrator: end fn_124_515C

// decomp-orchestrator: begin fn_124_3B14
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_124_3B14 {
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_3B14(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_124_3B14
// decomp-orchestrator: end fn_124_3B14

// decomp-orchestrator: begin fn_124_4DC4
#pragma force_active on
namespace decomp_orch_fn_124_4DC4 {
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4DC4(void* ptr, short flag)
{
    if (ptr) {
        fn_27_1540CC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_4DC4
// decomp-orchestrator: end fn_124_4DC4

// decomp-orchestrator: begin fn_124_5F40
#include <so/model/so_model_module_impl.h>
#pragma force_active on
namespace decomp_orch_fn_124_5F40 {
extern "C" void* fn_27_19A7DC(void*, int, int);
extern "C" void* fn_27_CC75C(void*, int, int);

extern "C" void* fn_124_5F40(
    void* object,
    soModuleAccesser* accesser,
    float scale,
    void* context,
    soEventObserverRegistrationDesc* registration)
{
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_27_19A7DC(object, 8, 0);
    fn_27_CC75C(storage + 0x1AC, 3, 0);
    reinterpret_cast<soModelModuleImpl*>(storage + 0x1F4)->__ct(
        accesser,
        reinterpret_cast<soArray<soModelNodeSetUp>*>(object),
        scale,
        context,
        reinterpret_cast<soArray<soModelVirtualNode>*>(storage + 0x1AC),
        registration);
    return object;
}
}  // namespace decomp_orch_fn_124_5F40
// decomp-orchestrator: end fn_124_5F40

// decomp-orchestrator: begin fn_124_2510
#pragma force_active on
namespace decomp_orch_fn_124_2510 {
extern "C" {
void* fn_124_20E0(void*, short);
void __dt__33soAnimCmdAddressPackArraySeparateFv(void*, short);
void* fn_124_21BC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_2510(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_124_20E0(members + 0xDC, memberDeleting);
        __dt__33soAnimCmdAddressPackArraySeparateFv(members + 0xC0, memberDeleting);
        fn_124_21BC(members + 0x14, memberDeleting);
        if (object != 0)
            fn_27_C7770(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}  // namespace decomp_orch_fn_124_2510
// decomp-orchestrator: end fn_124_2510

// decomp-orchestrator: begin fn_124_2FF0
#pragma force_active on
namespace decomp_orch_fn_124_2FF0 {
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_2FF0(void* ptr, short flag) {
    if (ptr) {
        fn_27_A0C34(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_2FF0
// decomp-orchestrator: end fn_124_2FF0

// decomp-orchestrator: begin fn_124_4ED8
#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on
namespace decomp_orch_fn_124_4ED8 {
extern "C" void fn_27_614C4(void*, short);
extern "C" void* fn_27_D3080(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_4ED8(void* self, short flag) {
    if (self != 0) {
        fn_27_614C4(static_cast<char*>(self) + 0xAC, -1);
        if (self != 0) {
            fn_27_D3080(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}  // namespace decomp_orch_fn_124_4ED8
// decomp-orchestrator: end fn_124_4ED8

// decomp-orchestrator: begin fn_124_2B5C
#pragma force_active on
namespace decomp_orch_fn_124_2B5C {
extern "C" void fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_2B5C(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_27_1966BC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}  // namespace decomp_orch_fn_124_2B5C
// decomp-orchestrator: end fn_124_2B5C

// decomp-orchestrator: begin fn_124_8228
#pragma force_active on
namespace decomp_orch_fn_124_8228 {
extern "C" void fn_27_1A76C4(void* receiver, short id, void* owner, signed char argument);
extern "C" void fn_124_8228(void* receiver, short id, int argument) {
    fn_27_1A76C4(receiver, id, receiver, static_cast<signed char>(argument));
}
}  // namespace decomp_orch_fn_124_8228
// decomp-orchestrator: end fn_124_8228

// decomp-orchestrator: begin fn_124_80D8
#pragma force_active on
namespace decomp_orch_fn_124_80D8 {
extern "C" void fn_27_D46B8(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_124_80D8(void* receiver, short id, int argument) {
    fn_27_D46B8(receiver, id, receiver, static_cast<signed char>(argument));
}
}  // namespace decomp_orch_fn_124_80D8
// decomp-orchestrator: end fn_124_80D8
