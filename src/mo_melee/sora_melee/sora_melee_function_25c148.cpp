#include <cm/cm_quake.h>
#include <ec/ec_mgr.h>
#include <gf/gf_scene.h>
#include <gf/gf_task.h>
#include <gf/gf_task_scheduler.h>
#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_53B00[];
extern char lbl_27_data_53B20[];
extern char lbl_27_data_53B30[];
extern void* lbl_27_bss_5668;
extern const float lbl_27_rodata_426C;
extern ecMgr* g_ecMgr;

void cmReqQuake(int id, Vec3f* vec);

struct gfTaskBase0 {
    char pad[0x3c];
};

class gfTaskVt : public gfTaskBase0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void* slot27();
};

extern "C" void fn_27_25C148(gfTask* self) {
    gfSceneManager* sm = gfSceneManager::getInstance();
    void* found = sm->searchScene(lbl_27_data_53B00);
    char* obj = (char*)__dynamic_cast(found, 4, lbl_27_data_53B20, lbl_27_data_53B30, 0);
    gfTaskVt* t = *(gfTaskVt**)(obj + 0x54);
    if (t == NULL || t->slot27() == NULL) {
        gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)0, true);
        gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)0xA, true);
        gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)0x2, true);
        gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)0xC, true);
        self->setPaused(false);
        float f = lbl_27_rodata_426C;
        float vec[3];
        vec[0] = f;
        vec[1] = f;
        vec[2] = f;
        cmReqQuake(5, (Vec3f*)vec);
        if (lbl_27_bss_5668 != NULL && ((u8*)lbl_27_bss_5668)[0x19d] == 0) {
            if (*((u8*)self + 0x50) != 0) {
                g_ecMgr->setEffect((EfID)0x01030011);
            } else {
                g_ecMgr->setEffect((EfID)0x0103000F);
            }
        }
        *(s32*)((char*)self + 0x4c) = 0;
        *(s32*)((char*)self + 0x48) = 3;
    }
}
