#pragma force_active on
#include <types.h>

extern "C" void OSReport(const char* msg, ...);
extern const char lbl_80422EB8[];
extern const char lbl_8059C660;

struct gfSceneBase {
    const char* m_sceneName;
};

struct gfScene : gfSceneBase {
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void unused3() = 0;
};

struct gfSequenceBase {
    const char* m_sequenceName;
};

struct gfSequence : gfSequenceBase {
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
};

class gfSceneManager {
public:
    gfScene* m_prevScene;
    gfScene* m_currentScene;
    gfScene* m_nextScene;
    gfSequence* m_prevSequence;
    gfSequence* m_currentSequence;
    gfSequence* m_nextSequence;
    char _pad[0x270];
    int m_field288;
    int m_processStep;

    void changeNextScene();
};

void gfSceneManager::changeNextScene() {
    m_prevScene = m_currentScene;
    m_currentScene = 0;

    for (;;) {
        m_currentSequence->unused1();

        if (m_processStep != 3) {
            break;
        }

        gfSequence* cur = m_currentSequence;
        const char* nextName = m_nextSequence->m_sequenceName;
        const char* name = cur ? cur->m_sequenceName : &lbl_8059C660;
        OSReport(lbl_80422EB8, name, nextName);

        m_currentSequence->unused2();

        gfSequence* tmp = m_nextSequence;
        m_nextSequence = 0;
        m_prevSequence = m_currentSequence;
        m_currentSequence = tmp;
        m_processStep = 0;
        tmp->unused0();
        m_processStep = 1;
    }

    gfScene* prev = m_prevScene;
    const char* nextName = m_nextScene->m_sceneName;
    const char* name = prev ? prev->m_sceneName : &lbl_8059C660;
    OSReport(lbl_80422EB8, name, nextName);

    gfScene* tmp = m_nextScene;
    m_field288 = 0;
    m_currentScene = tmp;
    m_nextScene = 0;
    tmp->unused3();
}
