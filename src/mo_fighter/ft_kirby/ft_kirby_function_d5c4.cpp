#include <ft/fighter.h>
#include <ft/ft_manager.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" bool fn_96_E110(Fighter*);
extern "C" int fn_27_111E30(void*);
extern "C" int getPlayerNo__9ftManagerFi(ftManager*, int);
extern "C" void fn_96_1C8A0(void*, int, int, int, bool);
extern "C" void fn_27_15B6FC(void*, int);

struct KirbyArticle {
    virtual int isNull();
};
struct KirbyArticles {
    virtual ~KirbyArticles();
    virtual void activate();
    virtual void deactivate();
    virtual KirbyArticle* generate(int, bool, bool);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void remove(KirbyArticle*);
};
struct KirbySound {
    virtual ~KirbySound();
    virtual void update(Vec3f*);
    virtual void deactivate();
    virtual void activate(Vec3f*);
    virtual void setPos(Vec3f*, int);
    virtual int playSE(SndID, bool, bool, int);
};

static inline void setupCopy(Fighter* self) {
    ftManager* manager;
    int entryId = self->m_entryId;
    manager = g_ftManager;
    fn_96_1C8A0((char*)self + 0x1b72c, -1,
        getPlayerNo__9ftManagerFi(manager, entryId),
        fn_27_111E30(self->getOwner()), fn_96_E110(self));
}

extern "C" void fn_96_D5C4(Fighter* self, soModuleAccesser* acc, int flag) {
    int value = acc->getWorkManageModule().getInt(0x10000048);
    acc->getWorkManageModule().setInt(-1, 0x10000048);
    acc->getWorkManageModule().offFlag(0x12000042);
    acc->getWorkManageModule().offFlag(0x1200001f);
    setupCopy(self);
    if (flag) {
        acc->getWorkManageModule().setInt(2, 0x1000004b);
        KirbyArticles* articles = (KirbyArticles*)acc->m_enumerationStart->m_generateArticleManageModule;
        KirbyArticle* article = articles->generate(2, false, false);
        if (!article->isNull()) articles->remove(article);
        ((KirbySound*)&acc->getSoundModule())->playSE((SndID)0xc2f, false, false, 0);
    }
    fn_27_15B6FC((char*)self + 0x13c, value);
    acc->getEffectModule().removeCommon(0x1a);
    acc->getWorkManageModule().setInt(-1, 0x10000049);
}
