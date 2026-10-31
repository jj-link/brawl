#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct TriggerParam {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
};

extern void* g_stTriggerMng;
extern "C" void fn_27_2323EC(void* p, void* q);

extern "C" void fn_27_22B4C8(void* a, void* b, TriggerParam* p) {
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unk1 = 0;
    p->unkC = -1;
    p->unk10 = 0;
    if (g_stTriggerMng != 0) {
        fn_27_2323EC(g_stTriggerMng, b);
    }
}
