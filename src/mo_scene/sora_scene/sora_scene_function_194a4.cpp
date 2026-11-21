#include <ip/ip_switch.h>
#include <it/it_manager.h>
#include <gf/gf_slow_manager.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

struct SceneTaskBase {
    char pad[0x3c];
};

class SceneTask : public SceneTaskBase {
public:
    virtual void processDefault();
    virtual void fn_1_8AE0();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_1_8B3C();
    virtual void fn_1_8ADC();
    virtual void fn_1_8AD4();
    virtual int fn_1_8ACC();
};

struct SceneB0 { char pad[0x34]; unsigned char flag : 1; };

struct Scene {
    char pad[8];
    SceneTask* tasks[7];
    SceneTask* t24;
    SceneTask* t28;
    char pad2[8];
    SceneTask* t34;
    SceneTask* t38;
    SceneTask* t3c;
    char pad3[8];
    void* t48;
    void* t4c;
    void* t50;
    char pad4[0x14];
    void* t68;
    SceneTask* other[7];
    void* t88;
    char pad5[0x24];
    SceneB0* b0;
    char pad6[0x14];
    int state;
    int step;
    char pad7[8];
    unsigned char flags;
    char pad8[0x21];
    unsigned char slow;
    unsigned char getSlow() const { return slow; }
};

struct PadSystem {
    char pad[0x30];
    int field30;
    char pad2[0xb34];
    void* fieldb68;
};

struct Application {
    char pad[0xed];
    unsigned char flags;
};

struct Entry {
    char pad[0x10];
    unsigned char flags;
};

struct Record {
    char pad[0xc];
    unsigned short count;
    unsigned short ids[256];
    unsigned char types[244];
};

struct Mode {
    char pad[8];
    unsigned char kind;
    char pad2[0x59];
    unsigned char flags;
};

struct Global {
    char pad[8];
    Mode* mode;
    char pad2[0x38];
    Record* records;
    Mode* getMode() { return mode; }
};

extern int lbl_1_data_4FE0[];
extern Entry lbl_1_bss_1738;
extern void* g_ftManager;
extern void* lbl_27_bss_2CC8;
extern void* lbl_27_bss_6A34;
extern Application* g_gfApplication;
extern PadSystem* g_gfPadSystem;
extern Global* g_GameGlobal;

extern "C" void fn_27_109410(void*);
extern "C" int fn_27_C6EEC(void*);
extern "C" void fn_27_C6E60(void*);
extern "C" void fn_80016928(void*);
extern "C" void fn_8004B88C(void*);
extern "C" void fn_8002C49C(void*);
extern "C" void fn_8002C1B0(void*);
extern "C" void fn_27_2A7D3C(itManager*);
extern "C" void fn_27_2ABD04(itManager*, int);
extern "C" int fn_27_2ABEC4(itManager*, int);
extern "C" void fn_80060E20(void*, int, int, int, int, int);
extern "C" void fn_27_241F40(void*, int);
extern "C" void fn_27_240480(void*, int);
extern "C" void fn_80052704(unsigned short, int);
extern "C" void fn_80052AC0(unsigned short, int);
extern "C" void fn_80051858();
extern "C" void fn_8004FB48();
extern "C" void fn_80051440(unsigned short);

extern "C" void fn_1_194A4(Scene* self, int update) {
    int* data = lbl_1_data_4FE0;
    unsigned char sp8;

    if (self->state != 2) {
        do {
            switch (self->step) {
            case 0:
                self->state = data[0x158];
                self->step = 0xbf3;
            case 0xbf3:
                if ((self->flags >> 1) & 1) {
                    g_gfPadSystem->field30 = 0;
                    g_gfApplication->flags &= ~4;
                    self->state = data[0x159];
                    self->step = 0xbf9;
                    break;
                }
                goto task_check;

            wait_task:
                self->state = data[0x15a];
                self->step = 0xc00;
                break;

            case 0xbf9:
            case 0xc00:
            task_check:
                if (self->t34 && !self->t34->fn_1_8ACC())
                    goto wait_task;

                if (g_ftManager)
                    fn_27_109410(g_ftManager);
                if (fn_27_C6EEC(lbl_27_bss_2CC8))
                    fn_27_C6E60(lbl_27_bss_2CC8);

                fn_80016928(g_gfApplication);
                fn_8004B88C(ipSwitch::getInstance()->m_keyRecorder);

                if (self->slow != 0xff) {
                    sp8 = self->getSlow();
                    gfSlowManager::removeRequest(sp8);
                    self->slow = 0xff;
                }

                fn_8002C49C(g_gfPadSystem->fieldb68);
                fn_8002C1B0(g_gfPadSystem->fieldb68);

                if (lbl_27_bss_6A34) {
                    fn_27_2A7D3C(itManager::getInstance());
                    *((unsigned char*)itManager::getInstance() + 0xbc) = 1;
                    fn_27_2ABD04(itManager::getInstance(), 4);
                    goto item_check;

                item_wait:
                    self->state = data[0x15b];
                    self->step = 0xc43;
                    break;

                case 0xc43:
                item_check:
                    if (!fn_27_2ABEC4(itManager::getInstance(), 4))
                        goto item_wait;
                }

                if (self->b0)
                    self->b0->flag = 0;

                fn_80060E20(g_ecMgr, 0, 0, 1, 1, 0);

                for (int i = 0; i < 7; i++) {
                    if (self->tasks[i])
                        self->tasks[i]->fn_1_8AD4();
                }

                if (self->t24)
                    self->t24->fn_1_8AD4();
                if (self->t38)
                    self->t38->fn_1_8AD4();
                if (self->t28)
                    self->t28->fn_1_8AD4();
                if (self->t3c)
                    self->t3c->fn_1_8AD4();

                for (int i = 0; i < 7; i++) {
                    if (self->other[i])
                        self->other[i]->fn_1_8AD4();
                }

                if (self->t50)
                    fn_27_241F40(self->t50, 1);
                if (self->t88)
                    fn_27_241F40(self->t88, 1);
                if (self->t68)
                    fn_27_241F40(self->t68, 1);
                if (self->t34)
                    fn_27_240480(self->t34, 0);
                if (self->t48)
                    fn_27_241F40(self->t48, 1);
                if (self->t4c)
                    fn_27_241F40(self->t4c, 1);

                {
                    unsigned short j;
                    int i;
                    Record* records;
                    Record* record;
                    Mode* mode = g_GameGlobal->getMode();
                    if (!((lbl_1_bss_1738.flags >> 3) & 1) &&
                        !((self->flags >> 3) & 1) &&
                        ((unsigned int)((mode->kind >> 2) & 0x3f)) != 0x21 &&
                        !((mode->flags >> 4) & 1)) {
                        records = g_GameGlobal->records;
                        record = records;

                        for (i = 0; i < 4; i++, record++) {
                            for (j = 0; j < record->count; j++) {
                                switch (record->types[j]) {
                                case 0x17:
                                    fn_80052704(record->ids[j], 1);
                                    break;
                                case 0x33:
                                    fn_80052AC0(record->ids[j], 1);
                                    break;
                                case 0xb:
                                    fn_80051858();
                                    fn_8004FB48();
                                    break;
                                case 0xf:
                                    fn_80051440(record->ids[j]);
                                    break;
                                }
                            }
                        }

                        records[0].count = 0;
                        records[1].count = 0;
                        records[2].count = 0;
                        records[3].count = 0;
                    }
                }

                self->state = data[0x15c];
                self->step = 0xc67;
                break;
            }

            if (update)
                gfTaskScheduler::getInstance()->updateStatus();
        } while (update && self->state != 2);
    }
}
