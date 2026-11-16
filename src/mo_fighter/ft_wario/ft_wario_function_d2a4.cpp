#include <so/so_module_accesser.h>
#pragma force_active on
class ArticleModule {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void remove(int, int);
};

struct WarioEvent : soLinkEventArgs {
    Vec2f speed;
    WarioEvent(const Vec2f& v) : soLinkEventArgs(0x45A), speed(v) {}
};
struct WarioSimpleEvent : soLinkEventArgs {
    float x, y;
    WarioSimpleEvent() : soLinkEventArgs(0x457) {}
};

extern "C" void fn_110_D2A4(void*, soModuleAccesser* accesser, int kind) {
    accesser->m_enumerationStart->m_collisionHitModule->initMultiSituation(0);
    soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
    if (link->isLink(6)) {
        if (kind == 0x10B || kind == -1) {
            accesser->getWorkManageModule().onFlag(0x12000041);
            ((ArticleModule*)accesser->m_enumerationStart->m_generateArticleManageModule)->remove(0, 0);
        } else if ((unsigned)(kind - 0x43) <= 3U) {
            soDamageLog* info = accesser->m_enumerationStart->m_damageModule->getDamageLog();
            WarioEvent event(info->m_speed);
            link->sendEventParents(6, event);
            if (link->isModelConstraint())
                link->removeModelConstraint(true);
            link->unlink(6);
        } else if (kind < 0x121 || kind > 0x12D) {
            WarioSimpleEvent event;
            link->sendEventParents(6, event);
            if (link->isModelConstraint())
                link->removeModelConstraint(true);
            link->unlink(6);
        }
        if (accesser->m_enumerationStart->m_statusModule->getStatusKind() == 0x129 && kind == 0x124) {
            soLinkModule* link2 = accesser->m_enumerationStart->m_linkModule;
            if (link2->isLink(6)) {
                int node = accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(0x130);
                link2->removeModelConstraint(true);
                link2->setModelConstraintPosOrt(6, node, 8, 3, false);
            }
        }
    }
}
