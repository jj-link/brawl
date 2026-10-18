#include <gf/gf_scene.h>
#include <sr/sr_common.h>
#pragma force_active on

class SceneObject {
public:
    const char* m_name;
    const void* m_data;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    gfSceneManager* m_sceneManager;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const char lbl_1_data_6B94[];
extern "C" const char lbl_1_data_6C44[];

extern "C" SceneObject* fn_1_214A0() {
    SceneObject* scene =
        static_cast<SceneObject*>(__nw__FUlQ25Heaps8HeapType(0x18, 0x2e));
    if (scene != nullptr) {
        scene->m_name = lbl_1_data_6B94;
        scene->m_data = lbl_1_data_6C44;
        scene->m_sceneManager = gfSceneManager::getInstance();
    }
    return scene;
}
