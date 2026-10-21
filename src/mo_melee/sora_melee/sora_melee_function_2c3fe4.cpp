#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct gfArchive;

struct muAdvSealTaskParam {
    u8 mode;
};

struct muAdvSealTask {
    u8 pad0[0x44];
    u8 mode;
    u8 pad45[0xF];
    u32 state;
    u8 pad58[0x1AF24 - 0x58];
    void* scene;
    u8 tail[0x1B018 - 0x1AF28];
};

struct GameData {
    u8 pad0[0x24];
    u32 value;
};

struct GameGlobal {
    u8 pad0[0x1C];
    GameData* data;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
muAdvSealTask* fn_27_2C4104(muAdvSealTask*, gfArchive*);
void fn_800B96E8(void*, int);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* fn_801AB6CC(void*, void*, int);
void setBGMVol__9sndSystemFbf(void*, bool, float);

extern muAdvSealTask* lbl_27_bss_7328;
extern GameGlobal* g_GameGlobal;
extern void* g_sndSystem;
extern float lbl_27_rodata_61C4;
}

extern "C" muAdvSealTask* create__13muAdvSealTaskFPC18muAdvSealTaskParamP9gfArchive(
    const muAdvSealTaskParam* param, gfArchive* archive)
{
    muAdvSealTask* task =
        (muAdvSealTask*)__nw__FUlQ25Heaps8HeapType(0x1B018, 0x2A);

    if (task)
        task = fn_27_2C4104(task, archive);

    lbl_27_bss_7328 = task;
    task->mode = param->mode;

    if (param->mode == 1)
        fn_800B96E8((u8*)task + 0x58, 0xF0);
    else
        fn_800B96E8((u8*)task + 0x58, (u8)g_GameGlobal->data->value);

    switch (task->mode) {
    case 1:
        task->state = 0x135;
        task->scene = fn_801AB6CC(
            getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A),
            0, 6);
        break;

    default:
        setBGMVol__9sndSystemFbf(g_sndSystem, true, lbl_27_rodata_61C4);
        task->state = 0x134;
        break;
    }

    return task;
}
