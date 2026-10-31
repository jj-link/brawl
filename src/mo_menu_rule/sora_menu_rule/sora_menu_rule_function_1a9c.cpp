#include <gf/gf_scene.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, unsigned long long, short);

extern unsigned char lbl_18_data_6D0[];
extern unsigned char lbl_18_data_700[];

unsigned int fn_18_1A9C() {
    gfSceneManager* manager = gfSceneManager::getInstance();
    unsigned long long types =
        ((unsigned long long)(unsigned int)lbl_18_data_6D0 << 32) |
        (unsigned int)lbl_18_data_700;

    char* scene = (char*)__dynamic_cast(
        manager->m_currentScene, 4, types, 0
    );
    return *(unsigned int*)(scene + 0xAA0);
}
}
