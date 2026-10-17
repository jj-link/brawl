#include <so/so_module_accesser.h>

// Opaque interfaces retain the virtual slots used by this callback.
class NessPKThunderLinkedArticle {
public:
    virtual bool isNull() const;
};

// NessPKThunderArticleManager: getArticle +0x14 (slot 3), activate +0x3C (slot 13),
// slot21 +0x5C (called with 0, result compared with 6).
class NessPKThunderArticleManager {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual NessPKThunderLinkedArticle* getArticle(int kind, int index, bool variation);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void deactivate(int kind, int index, int force);
    virtual void slot11();
    virtual void slot12();
    virtual void activate(NessPKThunderLinkedArticle* article);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21(int kind);
};

// wnNessPKThunderStatusUniqProcessMove::execFixPosCounter
// Every other counter tick, activate the manager's article 0 while the
// manager reports fewer than six active entries.
extern "C" void fn_101_1A3D0(void* /*uniqProcess*/, soModuleAccesser* accesser) {
    NessPKThunderArticleManager* articles =
        static_cast<NessPKThunderArticleManager*>(accesser->m_enumerationStart->m_generateArticleManageModule);
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x20000000);
    if (articles->slot21(0) < 6) {
        if (count % 2 == 0) {
            NessPKThunderLinkedArticle* article = articles->getArticle(0, 0, false);
            if (!article->isNull()) {
                articles->activate(article);
            }
        }
    }
    work->setInt(count + 1, 0x20000000);
}
