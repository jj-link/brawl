#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern void* g_GameGlobal;

u32* fn_8004E5F8(void*);
void fn_800506C0(u32, u32);
u32 getInfoMsgID__6muMenuFiii(u32);
void printIndex__5MuMsgFUlUlPv(void*, u32, u32, void*);
void printf__5MuMsgFUlPCce(void*, u32, const char*, ...);
s32 getLanguage__10GameGlobalFv(void*);
void setFrameVisible__8MuObjectFf(void*, float);

extern const char lbl_2_data_2750[];
extern const char lbl_2_data_276C[];
extern const float lbl_2_rodata_6D4;
extern const double lbl_2_rodata_6F0;
}

struct VirtTarget {
    virtual ~VirtTarget() = 0;
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void target(float, void*) = 0;
};

extern "C" void fn_2_1C6F0(void* self, s32 arg1) {
    u8* pself = (u8*)self;
    u32* bits = fn_8004E5F8(g_GameGlobal);
    s32 time_data[10];

    u32 msgIdx;
    u32 lineIdx;
    s32 iter;
    s32 idx;
    iter = 0;
    msgIdx = 0;
    lineIdx = 1;
    idx = arg1;

    while (iter < 4 && idx < *(s32*)(pself + 0x67c)) {
        u32 entry = *(u32*)(*(u32*)(pself + 0x678) + idx * 4);
        u32 msgId = getInfoMsgID__6muMenuFiii(entry);

        printIndex__5MuMsgFUlUlPv(
            *(void**)(pself + 0x688), msgIdx, msgId, 0);
        fn_800506C0(
            (u32)time_data,
            *(u32*)((u8*)bits + entry * 4 + 0x20));

        s32 lang = getLanguage__10GameGlobalFv(g_GameGlobal);
        if (lang == 0) {
            printf__5MuMsgFUlPCce(
                *(void**)(pself + 0x688), lineIdx, lbl_2_data_2750,
                time_data[5], time_data[4] + 1, time_data[3],
                time_data[2], time_data[1], time_data[0]);
        } else {
            printf__5MuMsgFUlPCce(
                *(void**)(pself + 0x688), lineIdx, lbl_2_data_276C,
                time_data[4] + 1, time_data[3], time_data[5],
                time_data[2], time_data[1], time_data[0]);
        }

        msgIdx += 2;
        lineIdx += 2;
        iter++;
        idx++;
    }

    u8 flag = 0;
    if (arg1 > 0) {
        flag |= 2;
    }
    if (arg1 + 4 < *(s32*)(pself + 0x67c)) {
        flag |= 1;
    }

    void* container = *(void**)(pself + 0x64c);
    void* muObj = *(void**)((u8*)container + 0x1c0);
    setFrameVisible__8MuObjectFf(muObj, (float)flag);

    void* p1 = *(void**)(pself + 0x64c);
    void* p2 = *(void**)((u8*)*(void**)((u8*)p1 + 0x1c0) + 0x14);
    void* p3 = *(void**)((u8*)p2 + 8);
    ((VirtTarget*)p3)->target(lbl_2_rodata_6D4, p1);
}