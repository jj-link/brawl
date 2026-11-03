#include <types.h>
#include <gf/gf_camera.h>
#include <gf/gf_heap_manager.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" int strcmp(const char*, const char*);
extern "C" void fn_8000E708(void*);
extern "C" void fn_80018610(void*);
extern void* g_gfSceneRoot;

class gfCameraController_base {
public:
    const char* name;
};

class gfCameraController : public gfCameraController_base {
public:
    virtual void slot0();
    virtual void draw();
    virtual void slot2();
};

struct gfSceneEntry {
    s32 active;        // 0x00
    const char* name;  // 0x04
    u8 unk8;           // 0x08
    u8 state;          // 0x09
    u8 pad[2];         // 0x0A
};

class gfSceneManager {
public:
    char pad0[4];                      // 0x000
    gfCameraController* m_controller;  // 0x004
    char pad008[0x270];                // 0x008
    u8 m_flags;                        // 0x278
    char pad279[3];                    // 0x279
    gfCameraController* m_ctrl27C;     // 0x27C
    char pad280[8];                    // 0x280
    s32 processStep;                   // 0x288
    char pad28C[4];                    // 0x28C
    gfSceneEntry entries[11];          // 0x290

    s32 process();
    u32 loadModule();
    void changeNextScene();
};

s32 gfSceneManager::process() {
    if ((u32)((m_flags >> 7) & 1) == 1U && m_controller == NULL) {
        return 0;
    }
    if (processStep == 0) {
        if ((((u8*)g_GameGlobal->m_appData)[0x28] >> 5) & 1) {
            return 0;
        }
        if (loadModule() == 1U) {
            return 0;
        }
        if (g_gfSceneRoot != NULL) {
            fn_8000E708(g_gfSceneRoot);
        }
        gfCameraManager* mgr = gfCameraManager::getManager();
        if (mgr != NULL) {
            fn_80018610(mgr);
            fn_80018610(mgr->getCamera(1));
        }
        m_controller->slot0();
        gfHeapManager::dumpList();
        processStep = 1;
    }
    m_controller->draw();
    if (processStep == 2) {
        m_controller->slot2();
        m_flags |= 0x40;
        m_ctrl27C = m_controller;
        const char* name = m_controller->name;
        int i;
        char* p = (char*)this;
        for (i = 0; i < 11; i++) {
            if (*(s32*)(p + 0x290) != 0 && ((u8*)p)[0x299] == 2 && name != NULL &&
                strcmp(*(const char**)(p + 0x294), name) == 0) {
                ((u8*)p)[0x299] = 3;
            }
            p += 12;
        }
        changeNextScene();
    }
    return 0;
}
