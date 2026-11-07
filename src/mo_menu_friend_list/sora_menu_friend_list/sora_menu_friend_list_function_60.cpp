#pragma force_active on
#include <types.h>
#include <string.h>

class gfTask {
public:
    enum Category {};
};

struct FriendListArr {
    char pad[0x48];
    s32 arr[93];
    s32 arr2[18];
};

extern "C" {
extern const char lbl_14_data_0[];
extern u8 lbl_14_data_4C4[];
extern const float lbl_14_rodata_0;
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);
void fn_800B96E8(void*, int);
void fn_16_3B4(void*);
}

extern "C" gfTask* fn_14_60(gfTask* obj) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        obj, lbl_14_data_0, static_cast<gfTask::Category>(8), 0xF, 8, true);
    char* self = reinterpret_cast<char*>(obj);
    *(s8*)(self + 0x40) = 0;
    *(void**)(self + 0x3C) = lbl_14_data_4C4;
    *(s32*)(self + 0x44) = 0;
    *(s32*)(self + 0x204) = 0;
    fn_800B96E8(self + 0x208, 0xFF);
    *(s32*)(self + 0x2B0) = 0;
    *(s32*)(self + 0x24C0) = 0;
    *(s32*)(self + 0x24C4) = 0;
    *(f32*)(self + 0x24C8) = lbl_14_rodata_0;
    *(s32*)(self + 0x24CC) = 0;
    *(s32*)(self + 0x24D0) = 0;
    *(s32*)(self + 0x24D4) = 0;
    *(s32*)(self + 0x24D8) = 0;
    *(s32*)(self + 0x24DC) = 0;
    *(s32*)(self + 0x24E0) = 0;
    *(s32*)(self + 0x24E4) = 0;
    *(s8*)(self + 0x24E8) = 0;
    *(s32*)(self + 0x24EC) = 0;
    *(s32*)(self + 0x24F0) = 0;
    *(s32*)(self + 0x24F4) = 0;
    *(s32*)(self + 0x24F8) = 0;
    *(s32*)(self + 0x24FC) = 0;
    *(s32*)(self + 0x2510) = 0;
    *(s32*)(self + 0x2514) = 0;
    *(s32*)(self + 0x2518) = 0;
    fn_16_3B4(self + 0x2570);
    *(s32*)(self + 0x2A04) = 0;
    *(f32*)(self + 0x2A08) = lbl_14_rodata_0;
    *(s32*)(self + 0x2A0C) = 0;
    *(s32*)(self + 0x2A10) = 0;
    *(s32*)(self + 0x2A14) = 0;
    *(s8*)(self + 0x2A18) = 0;
    *(s32*)(self + 0x2A1C) = 0;
    *(s32*)(self + 0x2A20) = 0;
    *(s8*)(self + 0x2A24) = 0;
    *(s32*)(self + 0x2A28) = 0;
    *(s32*)(self + 0x2A2C) = 0;
    *(s32*)(self + 0x2A34) = 0;
    *(s8*)(self + 0x2A38) = 0;
    *(s32*)(self + 0x2ABC) = 0;
    *(s32*)(self + 0x2AC0) = 0;
    *(s32*)(self + 0x2AC4) = 0;
    *(u8*)(self + 0x2C) &= ~2;
    FriendListArr* s = reinterpret_cast<FriendListArr*>(obj);
    for (int i = 0; i < 93; i++) {
        s->arr[i] = 0;
    }
    for (int i = 0; i < 18; i++) {
        s->arr2[i] = 0;
    }
    memset(self + 0x2B8, 0, 0x2000);
    memset(self + 0x22B8, 0, 0x40);
    memset(self + 0x2500, 0, 0xD);
    memset(self + 0x22F8, 0, 0x1C8);
    memset(self + 0x2604, 0, 0x400);
    memset(self + 0x2A39, 0, 0x80);
    return obj;
}
