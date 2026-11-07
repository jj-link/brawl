#include <so/so_module_accesser.h>
#pragma force_active on
struct WarioEvent : soLinkEventArgs {
    Vec2f speed;
    WarioEvent(const Vec2f& v) : soLinkEventArgs(0x455), speed(v) {}
};
class WarioKinetic {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12();
public:
    virtual Vec2f getSumSpeed(short*);
};
extern "C" void fn_110_D2A4();
extern "C" void fn_110_D734(void* self, soModuleAccesser* accesser, int kind) {
    fn_110_D2A4();
    if (kind == 0x124) {
        soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
        if (link->isLink(6)) {
            short flag = 1;
            Vec2f speed;
            Vec2f::copy(speed, ((WarioKinetic*)accesser->m_enumerationStart->m_kineticModule)->getSumSpeed(&flag));
            WarioEvent event(speed);
            int node = accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(0x130);
            link->sendEventParents(6, event);
            link->setModelConstraintPosOrt(6, node, 8, 3, false);
            accesser->m_enumerationStart->m_situationModule->setKind((SituationKind)2, false);
        }
    }
}