#include <sr/sr_common.h>
#include <gf/gf_archive.h>
#include <gf/gf_scene.h>
#include <gf/gf_application.h>
#include <cm/cm_camera_controller.h>
#include <mu/menu.h>
#pragma force_active on

struct EndingA : gfTask {
    char pad40[0x978];
    int state;
};
struct EndingB : gfTask {
    char pad40[0x14];
    int state;
};
struct Scene {
    char pad[8];
    char paths[110][0x30];
    gfArchive* archive;
    EndingA* taskA;
    EndingB* taskB;
    unsigned int state;
    int result;
};

extern "C" {
EndingA* fn_19_5FC();
void fn_19_DEC(EndingA*);
EndingB* fn_19_0();
void fn_19_2EC(EndingB*);
void fn_19_ECC(EndingA*, int);
unsigned int fn_19_EF0(EndingA*);
void fn_19_F40(EndingA*, gfArchive*);
void fn_19_390(EndingB*, gfArchive*);
void fn_19_53C(EndingB*, int);
void fn_19_E48(EndingA*);
void fn_19_2FC(EndingB*);
void fn_800151FC(gfArchive*, const char*, int, int, int, int);
}

extern "C" int fn_1_5E70(Scene* self) {
    switch (self->state) {
    case 0: {
        self->archive = new (Heaps::MenuInstance) gfArchive;
        if (gfSceneManager::getInstance()->m_memoryLayout < 100) {
            self->taskA = fn_19_5FC();
            fn_19_DEC(self->taskA);
        }
        self->taskB = fn_19_0();
        fn_19_2EC(self->taskB);
        int kind = gfSceneManager::getInstance()->m_memoryLayout % 50;
        if (kind < 0) kind = 0;
        int base;
        int file = muMenu::exchangeGmCharacterKind2Something(kind) + 1;
        base = file;
        if (gfSceneManager::getInstance()->m_memoryLayout >= 50)
            file += 50;
        if (gfSceneManager::getInstance()->m_memoryLayout >= 100)
            file = gfSceneManager::getInstance()->m_memoryLayout;
        fn_800151FC(self->archive, self->paths[file], 0x2B, 0, 0, 0xFF);
        if (gfSceneManager::getInstance()->m_memoryLayout < 100)
            fn_19_ECC(self->taskA, base);
        self->state = 1;
        break;
    }
    case 1: {
        int waiting;
        if (!self->archive->unk9) waiting = 1;
        else if (gfSceneManager::getInstance()->m_memoryLayout < 100 &&
                 fn_19_EF0(self->taskA) == 1U)
            waiting = 1;
        else waiting = 0;
        if (!waiting) self->state = 2;
        break;
    }
    case 2:
        if (gfSceneManager::getInstance()->m_memoryLayout < 100)
            fn_19_F40(self->taskA, self->archive);
        fn_19_390(self->taskB, self->archive);
        CameraController::getInstance()->changeInput(CameraController::MenuFixed);
        g_gfApplication->unkD0.endKeepScreen();
        if (gfSceneManager::getInstance()->m_memoryLayout < 100) {
            self->state = 3;
        } else {
            fn_19_53C(self->taskB, self->result);
            self->state = 6;
        }
        break;
    case 3:
        self->taskA->state = 1;
        self->state = 4;
        break;
    case 4:
        if (self->taskA->state == 5) self->state = 5;
        break;
    case 5:
        self->state = 6;
        break;
    case 6:
        self->taskB->state = 1;
        self->state = 7;
        break;
    case 7:
        if (self->taskB->state == 8) self->state = 8;
        break;
    case 8:
        self->state = 9;
        break;
    case 9: {
        g_gfApplication->unkD0.startKeepScreen();
        delete self->archive;
        self->archive = 0;
        if (self->taskA) {
            fn_19_E48(self->taskA);
            self->taskA->exit();
            self->taskA = 0;
        }
        fn_19_2FC(self->taskB);
        self->taskB->exit();
        self->taskB = 0;
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 0;
        mgr->processStep = 2;
        self->state++;
        break;
    }
    }
    return 0;
}
