#include <so/stageobject.h>
#pragma force_active on

class Class_7A04 {
public:
    virtual void fn_120_5CB0();
    virtual void fn_120_12188();
    virtual void fn_120_13D28();
    virtual void fn_120_13D20();
    virtual void fn_120_13D18();
    virtual void fn_120_13D10();
    virtual void fn_120_13D08();
    virtual void fn_120_13D00();
    virtual void fn_120_13CF8();
    virtual void fn_120_13CF0();
    virtual void fn_120_13CE8();
    virtual void fn_120_13CE0();
    virtual void fn_120_13CD8();
    virtual void fn_120_13CD0();
    virtual void fn_120_13C80();
    virtual void fn_120_13CC8(int, soLinkEventArgs&);
    virtual void fn_120_13CB8();
    virtual int fn_120_13CA8(unsigned int);
    virtual void fn_120_13C98();
    virtual void fn_120_13C88(unsigned int);
};

struct RobotLinkEvent : soLinkEventArgs {
    RobotLinkEvent() : soLinkEventArgs(0x456) {}
};

extern "C" void fn_27_1D9FF8(void*);

extern "C" void fn_120_180F0(StageObject* self)
{
    Class_7A04* work = reinterpret_cast<Class_7A04*>(
        self->m_moduleAccesser->m_enumerationStart->m_workManageModule);
    if (work->fn_120_13CA8(0x22000000) != 0) {
        RobotLinkEvent event;
        reinterpret_cast<Class_7A04*>(
            self->m_moduleAccesser->m_enumerationStart->m_linkModule)
            ->fn_120_13CC8(1, event);
        reinterpret_cast<Class_7A04*>(
            self->m_moduleAccesser->m_enumerationStart->m_workManageModule)
            ->fn_120_13C88(0x22000000);
    }
    fn_27_1D9FF8(self);
}
