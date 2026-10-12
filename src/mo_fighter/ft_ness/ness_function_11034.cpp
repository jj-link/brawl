#include <so/so_module_accesser.h>

class NessLinkedArticle {
public:
    virtual bool isNull() const = 0;
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual int getTaskId();
};

// Opaque interfaces retain the virtual slots used by this callback.
class NessArticleManager {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual NessLinkedArticle* getArticle(int kind, bool index, bool variation);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void deactivate(int kind, int index, int force);
    virtual void slot11();
    virtual void slot12();
    virtual void activate(NessLinkedArticle* article);
};
struct NessArticleLinkEvent {
    int id;
    bool handled;
    int taskId;
    int nodeId;
};
class NessArticleLinkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool link(int index, int taskId);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void sendEvent(int index, int taskId, NessArticleLinkEvent& event);
};
extern "C" void fn_101_11260(NessArticleLinkEvent*, int taskId, int nodeId);

extern "C" void fn_101_11034(void*, soModuleAccesser* accesser) {
    int status = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    if (status == 48 || status == 45) {
        NessArticleManager* articles = static_cast<NessArticleManager*>(accesser->m_enumerationStart->m_generateArticleManageModule);
        NessArticleLinkModule* links = reinterpret_cast<NessArticleLinkModule*>(accesser->m_enumerationStart->m_linkModule);
        NessLinkedArticle* fifth = articles->getArticle(5, false, false);
        if (!fifth->isNull()) articles->activate(fifth);
        NessLinkedArticle* fourth = articles->getArticle(4, false, false);
        if (!fourth->isNull()) articles->activate(fourth);
        NessArticleLinkEvent fourthEvent;
        NessArticleLinkEvent fifthEvent;
        fn_101_11260(&fourthEvent, fourth->getTaskId(), 19);
        fn_101_11260(&fifthEvent, fifth->getTaskId(), 1);
        links->sendEvent(-1, fifth->getTaskId(), fourthEvent);
        links->sendEvent(-1, fourth->getTaskId(), fifthEvent);
        links->link(7, fifth->getTaskId());
        articles->deactivate(5, 0, false);
        articles->deactivate(4, 0, false);
    }
}
