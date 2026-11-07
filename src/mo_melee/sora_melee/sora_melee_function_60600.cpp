#include <types.h>
#include <ft/ft_manager.h>
#pragma force_active on

struct Out {
    s8 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    s8 unk10;
    u32 unk14;
    s32 unk18;
    u32 unk1C;
    u32 unk20;
    s32 unk24;
};

struct Pad3c {
    char pad0[0x28];
    u32 f28;
    u32 f2C;
    char pad1[0x3c - 0x30];
};

class TaskObj : public Pad3c {
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
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual u32 slot39();
    virtual u32 slot40();
    char pad2[0x10c - 0x40];
    u32 f10C;
};

class TaskObjArg : public Pad3c {
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
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual u32 slot39(u32 arg);
    virtual u32 slot40();
};

extern "C" {

u32 fn_27_8CB9C(void* self);
void* __dynamic_cast(void* p, long from, const void* a, const void* b, long hint);
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];

void fn_27_60600(Out* arg0, u32 arg1, TaskObjArg* arg2, TaskObj* arg3) {
    TaskObj* obj;

    if (arg1 != fn_27_8CB9C(arg2)) {
        if (arg3->slot39() == 0) {
            s32 s0 = (s32)((arg2->f2C << 17) & 0xFF800000) >> 24;
            u32 v = arg2->f28;
            arg0->unk4 = v;
            arg0->unk0 = s0;
            arg0->unk8 = arg2->slot39(v);
            arg0->unkC = arg2->slot40();
            obj = (TaskObj*)__dynamic_cast(arg3, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
            arg0->unk14 = obj->f28;
            arg0->unk10 = (s32)((obj->f2C << 17) & 0xFF800000) >> 24;
            arg0->unk18 = obj->slot39();
            arg0->unk1C = obj->slot40();
            arg0->unk20 = obj->f10C;
        } else {
            u32 taskId = fn_27_8CB9C(arg2);
            if (taskId != arg2->f28) {
                s32 entry = g_ftManager->getEntryIdFromTaskId(taskId, 0);
                if (entry != -1) {
                    s32 s0 = (s32)((arg2->f2C << 17) & 0xFF800000) >> 24;
                    u32 v = arg2->f28;
                    arg0->unk4 = v;
                    arg0->unk0 = s0;
                    arg0->unk8 = arg2->slot39(v);
                    arg0->unkC = arg2->slot40();
                    obj = (TaskObj*)g_ftManager->getFighter(entry, -1);
                    arg0->unk14 = obj->f28;
                    arg0->unk10 = (s32)((obj->f2C << 17) & 0xFF800000) >> 24;
                    arg0->unk18 = obj->slot39();
                    arg0->unk1C = obj->slot40();
                    arg0->unk20 = obj->f10C;
                }
            }
        }
        if (arg0->unk18 != -1) {
            arg0->unk24 = -1;
        }
    }
}

}