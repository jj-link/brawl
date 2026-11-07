#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

namespace {
struct RobotSituationLinkEvent : soLinkEventArgs {
    explicit RobotSituationLinkEvent(int kind) : soLinkEventArgs(kind) {}
};

struct RobotMotionModule {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
    virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14();
    virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23(); virtual void p24();
    virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28(); virtual void p29();
    virtual void p30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34();
    virtual void p35(); virtual void p36(); virtual void p37(); virtual void p38();
    virtual void doAction(int, int, int, int, float, float, u8); // 0xA4
    virtual void p40(int); // 0xA8
};
}

extern "C" const float lbl_120_rodata_4;
extern "C" const float lbl_120_rodata_8;
extern "C" void fn_27_131CD0(void*, int, int, soModuleAccesser*);

extern "C" void fn_120_8414(void* fighter, int situation, int previous,
        soModuleAccesser* accesser) {
    int kind = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    if (kind < 0x11B) {
        if (kind == 0x115) {
            goto block;
        }
        goto after;
    }
    if (kind >= 0x11E) {
        goto after;
    }
block:
    if (situation == 2) {
        RobotSituationLinkEvent event(0x83D);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(-1, event, 0);
    } else {
        RobotSituationLinkEvent event(0x83C);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(-1, event, 0);
    }
after:
    if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000040) != 0) {
        if (situation == 0) {
            soModuleAccesser* a = *reinterpret_cast<soModuleAccesser**>(reinterpret_cast<unsigned char*>(fighter) + 0x60);
            reinterpret_cast<RobotMotionModule*>(a->m_enumerationStart->m_motionModule)->p40(2);
            reinterpret_cast<RobotMotionModule*>(accesser->m_enumerationStart->m_motionModule)
                ->doAction(2, 0x1D9, 0x60, 0, lbl_120_rodata_8, lbl_120_rodata_4, 0);
            accesser->m_enumerationStart->m_workManageModule->offFlag(0x12000040);
            accesser->m_enumerationStart->m_workManageModule->onFlag(0x12000041);
        }
    }
    fn_27_131CD0(fighter, situation, previous, accesser);
}
