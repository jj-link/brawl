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
