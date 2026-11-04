#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on
const float lbl_27_rodata_2B28[2] = {0.0f, 0.0f};
namespace {
struct Prefix8 { unsigned char prefix[8]; };
class PhysObj : public Prefix8 {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0; virtual void v4() = 0;
    virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0; virtual void v9() = 0;
    virtual void v10() = 0; virtual void v11() = 0; virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0;
    virtual void v15() = 0; virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void v20() = 0; virtual void v21() = 0; virtual void v22() = 0; virtual void v23() = 0; virtual void v24() = 0;
    virtual void v25() = 0; virtual void v26() = 0; virtual void v27() = 0; virtual void v28() = 0; virtual void v29() = 0;
    virtual void v30() = 0; virtual void v31() = 0; virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0;
    virtual void v35() = 0; virtual void v36() = 0; virtual void v37() = 0; virtual void v38() = 0; virtual void v39() = 0;
    virtual void v40() = 0; virtual void v41() = 0; virtual void v42() = 0; virtual void v43() = 0; virtual void v44() = 0;
    virtual void v45() = 0; virtual void v46() = 0; virtual void v47() = 0; virtual void v48() = 0;
    virtual void v49(int, Vec3f*) = 0;
};
struct PosEvent : soLinkEventArgs {
    Vec3f pos;
    PosEvent(const Vec3f& value) : soLinkEventArgs(0x836), pos(value) {}
};
}
extern "C" void fn_27_1DDE30(void*, soModuleAccesser* acc) {
    PosEvent ev(Vec3f(lbl_27_rodata_2B28[0], lbl_27_rodata_2B28[0], lbl_27_rodata_2B28[0]));
    acc->getLinkModule().sendEventParents(3, ev);
    if (ev._0x4) {
        static_cast<PhysObj*>(acc->m_enumerationStart->m_physicsModule)->v49(0, &ev.pos);
    }
}