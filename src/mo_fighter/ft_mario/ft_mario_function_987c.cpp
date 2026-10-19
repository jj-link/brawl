#include <so/stageobject.h>
#pragma force_active on

// Only the article-manager interface used here is absent from the shared headers.
class MarioArticleManageModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void remove(int kind, int target);
};

extern "C" {

void fn_27_130D64(void* p);

void fn_91_987C(StageObject* self) {
    self->m_moduleAccesser->getWorkManageModule().setInt(0, 0x10000041);
    static_cast<MarioArticleManageModule*>(
        self->m_moduleAccesser->m_enumerationStart->m_generateArticleManageModule)
        ->remove(2, 0);
    fn_27_130D64(self);
}

}
