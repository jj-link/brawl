#include <ft/fighter.h>
#include <ft/ft_manager.h>
#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" unsigned int fn_27_109C10(ftManager*, unsigned int, unsigned int);
extern "C" int fn_27_111E30(void*);
extern "C" void fn_96_1C8A0(void*, int, int, int, bool);
extern "C" void fn_27_15B4F0(void*, int);
struct KirbySound {
    virtual ~KirbySound();
    virtual void update(Vec3f*);
    virtual void deactivate();
    virtual void activate(Vec3f*);
    virtual void setPos(Vec3f*, int);
    virtual int playSE(SndID, bool, bool, int);
};
static inline void setupCopy(Fighter* self, int kind) {
    ftManager* manager;
    int entryId = self->m_entryId;
    manager = g_ftManager;
    fn_96_1C8A0((char*)self + 0x1b72c, kind,
        manager->getPlayerNo(entryId), fn_27_111E30(self->getOwner()), false);
}
extern "C" void fn_96_D3E8(Fighter* self, soModuleAccesser* acc, int arg2, int arg3, int arg4) {
    if (arg3 != 5 && (arg3 < 0x32 || arg3 > 0x35) &&
        fn_27_109C10(g_ftManager, self->m_entryId, arg3) == 1) {
        acc->getWorkManageModule().setInt(arg3, 0x10000048);
        acc->getWorkManageModule().onFlag(0x12000042);
        acc->getWorkManageModule().setInt(arg2, 0x10000049);
        if (arg3 == 0x20) acc->getWorkManageModule().onFlag(0x1200001f);
        else acc->getWorkManageModule().offFlag(0x1200001f);
        setupCopy(self, arg3);
        fn_27_15B4F0((char*)self + 0x13c, arg3);
        if (arg4) ((KirbySound*)&acc->getSoundModule())->playSE((SndID)0xc2e, false, false, 0);
    } else if (arg4) ((KirbySound*)&acc->getSoundModule())->playSE((SndID)0xc33, false, false, 0);
}