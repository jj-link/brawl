#include <gf/gf_scene.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <string.h>
#pragma force_active on

extern "C" char lbl_80457158[];
extern "C" void fn_800CCF30(int, int, int, int, int);

extern "C" int fn_800CC540(int arg0) {
    char* base = lbl_80457158;
    const char* name = gfSceneManager::getInstance()->m_currentSequence->m_sequenceName;
    if (strcmp(name, base + 0xbc8) == 0) {
        netReport(base + 0xbd8);
        fn_800CCF30(arg0, 4, 5, 1, -1);
    } else if (strcmp(name, base + 0xc04) == 0) {
        netReport(base + 0xc18);
        fn_800CCF30(arg0, 4, 7, 1, -1);
    }
    return 1;
}