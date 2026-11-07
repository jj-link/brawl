#include <sr/sr_common.h>
#include <gf/gf_archive.h>
#include <gf/gf_scene.h>
#include <gf/gf_application.h>
#include <cm/cm_camera_controller.h>
#include <mu/menu.h>
#pragma force_active on
struct Challenger : gfTask { char pad[0x3dc - sizeof(gfTask)]; int state; };
struct Scene { char pad[8]; char paths[15][0x30]; gfArchive* archive; Challenger* task; unsigned int state; int index; };
struct Table { int values[14]; };
extern "C" {
extern Table lbl_1_data_4938;
Challenger* fn_23_0();
void fn_23_5BC(Challenger*, int);
void fn_23_5D8(Challenger*);
void fn_23_670(Challenger*, gfArchive*);
void fn_800151FC(gfArchive*, const char*, int, int, int, int);
}
extern "C" int fn_1_E76C(Scene* self) {
    switch (self->state) {
    case 0: {
        CameraController::getInstance()->changeInput(CameraController::MenuFixed);
        Table table = lbl_1_data_4938;
        int index = gfSceneManager::getInstance()->m_memoryLayout;
        if (index < 0) index = 0;
        self->index = table.values[index];
        self->archive = new (Heaps::MenuInstance) gfArchive;
        self->task = fn_23_0();
        fn_23_5BC(self->task, self->index);
        fn_800151FC(self->archive, self->paths[self->index], 0x2b, 0, 0, 0xff);
        muMenu::loadMenuSound();
        self->state = 1;
        break;
    }
    case 1: {
        int waiting = !self->archive->unk9 ? 1 : !muMenu::isLoadFinishMenuSound();
        if (!waiting) self->state = 2;
        break;
    }
    case 2:
        fn_23_670(self->task, self->archive);
        g_gfApplication->unkD0.endKeepScreen();
        self->state = 3;
        break;
    case 3:
        self->task->state = 1;
        self->state = 4;
        break;
    case 4:
        if (self->task->state == 11) self->state = 5;
        break;
    case 5:
        self->state = 6;
        break;
    case 6: {
        g_gfApplication->unkD0.startKeepScreen();
        delete self->archive;
        self->archive = 0;
        fn_23_5D8(self->task);
        self->task->exit();
        self->task = 0;
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 0;
        mgr->processStep = 2;
        self->state++;
        break;
    }
    }
    return 0;
}