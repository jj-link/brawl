#pragma force_active on
extern "C" int strcmp(const char* s1, const char* s2);

struct Scene {
    const char* mName;
};

struct SceneManager {
    char _pad[0x18];
    Scene* m_scenes[100];
    Scene* m_sequences[50];
    int m_sceneCount;
};

extern "C" Scene* searchScene__14gfSceneManagerFPCc(SceneManager* mgr,
                                                   const char* name) {
    int count = mgr->m_sceneCount;

    for (int i = 0; i < count; i++) {
        if (strcmp(mgr->m_scenes[i]->mName, name) == 0) {
            return mgr->m_scenes[i];
        }
    }

    return 0;
}
