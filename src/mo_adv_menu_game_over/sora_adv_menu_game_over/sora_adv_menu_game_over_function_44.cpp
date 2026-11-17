#pragma force_active on
#include <sr/sr_common.h>
#include <it/it_manager.h>

#include <mu/adv/mu_adv_game_over.h>

typedef adList<u32, Heaps::MenuInstance> FigureList;

extern "C" {
extern char lbl_33_data_0[];
extern char lbl_33_data_10[];
extern char lbl_33_data_164[];

void fn_33_45C(void*);
void fn_33_5E8(void*);
void fn_800FB408(void*, const char*, u8, int);
void fn_800FB77C(void*, int, const char*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
char* strcat(char*, const char*);
void* memset(void*, int, unsigned long);
void* fn_800AD808(void*, int);
void fn_800B96E8(void*, int);
}

extern "C" void* fn_33_44(void* arg0, const muAdvGameOverTaskParam* args) {
    int off3;
    int lim1;
    int lim3;
    int i3;
    FigureList* it3;
    char* p = (char*)arg0;

    fn_800FB408(p, lbl_33_data_0, (u8)args->unk4, 0x2A);

    u32 heap = args->unk4;
    *(u32*)(p + 0x1AC) = 0;
    *(char**)(p + 0x3C) = lbl_33_data_164;
    *(u32*)(p + 0x1B4) = heap;
    *(u32*)(p + 0x1C4) = 0;
    *(u32*)(p + 0x1F0) = 0;
    *(u32*)(p + 0x21C) = 0;
    *(u32*)(p + 0x22C) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x240) = 0;

    fn_800FB77C(p + 0x244, 8, lbl_33_data_164);

    *(u32*)(p + 0x248) = 0;
    *(u32*)(p + 0x24C) = 0;
    *(u32*)(p + 0x254) = 0;
    *(u32*)(p + 0x258) = 0;
    *(u32*)(p + 0x25C) = 0;
    *(u32*)(p + 0x260) = 0;
    *(u32*)(p + 0x2BC) = 0;

    __construct_array(p + 0x2C0, fn_33_45C, fn_33_5E8, 0x34, 3);

    *(u32*)(p + 0x3D8) = 0;
    *(u32*)(p + 0x3DC) = 0;
    *(u32*)(p + 0x3E0) = 0;
    *(u32*)(p + 0x3EC) = 0;
    *(u32*)(p + 0x3F0) = 0;
    *(u32*)(p + 0x3F4) = 0;
    p[0x7C] = 0;

    strcat(p + 0x7C, lbl_33_data_10);
    memset(p + 0x234, 0, 4);

    *(u32*)(p + 0x284) = 0;
    *(u32*)(p + 0x288) = 0;
    *(u32*)(p + 0x28C) = 0;
    *(u32*)(p + 0x290) = 0;
    *(u32*)(p + 0x294) = 0;
    *(u32*)(p + 0x298) = 0;
    *(u32*)(p + 0x29C) = 0;
    *(u32*)(p + 0x2A0) = 0;
    *(u32*)(p + 0x2A4) = 0;
    *(u32*)(p + 0x2A8) = 0;
    *(u32*)(p + 0x2AC) = 0;
    *(u32*)(p + 0x2B0) = 0;
    *(u32*)(p + 0x2B4) = 0;
    *(u32*)(p + 0x2B8) = 0;

    *(u32*)(p + 0x35C) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36C) = 0;
    *(u32*)(p + 0x370) = 0;
    *(u32*)(p + 0x374) = 0;
    *(u32*)(p + 0x378) = 0;
    *(u32*)(p + 0x37C) = 0;
    *(u32*)(p + 0x380) = 0;
    *(u32*)(p + 0x384) = 0;
    *(u32*)(p + 0x388) = 0;
    *(u32*)(p + 0x38C) = 0;
    *(u32*)(p + 0x390) = 0;
    *(u32*)(p + 0x394) = 0;
    *(u32*)(p + 0x398) = 0;
    *(u32*)(p + 0x39C) = 0;
    *(u32*)(p + 0x3A0) = 0;
    *(u32*)(p + 0x3A4) = 0;
    *(u32*)(p + 0x3A8) = 0;
    *(u32*)(p + 0x3AC) = 0;
    *(u32*)(p + 0x3B0) = 0;
    *(u32*)(p + 0x3B4) = 0;
    *(u32*)(p + 0x3B8) = 0;
    *(u32*)(p + 0x3BC) = 0;
    *(u32*)(p + 0x3C0) = 0;
    *(u32*)(p + 0x3C4) = 0;
    *(u32*)(p + 0x3C8) = 0;
    *(u32*)(p + 0x3CC) = 0;
    *(u32*)(p + 0x3D0) = 0;
    *(u32*)(p + 0x3D4) = 0;

    *(u32*)(p + 0x264) = 0;
    *(u32*)(p + 0x270) = 0;
    *(u32*)(p + 0x268) = 0;
    *(u32*)(p + 0x274) = 0;
    *(u32*)(p + 0x26C) = 0;
    *(u32*)(p + 0x278) = 0;

    void* obj = operator new(0x3EB4, Heaps::MenuInstance);
    if (obj != 0) {
        obj = fn_800AD808(obj, 1);
    }
    *(void**)(p + 0x280) = obj;

    char* item = *(char**)((char*)itManager::getInstance() + 0x14B8);
    if (item != 0) {
        *(u32*)(p + 0x27C) = *(u32*)(item + 4);
    }

    int n = 0;
    ((u8*)p)[0x1B0] = args->unk0;
    *(u32*)(p + 0x234 + n++ * 4) = 0;
    if (((u8*)p)[0x1B0] != 0) {
        *(u32*)(p + 0x234 + n++ * 4) = 2;
    }
    *(u32*)(p + 0x234 + n++ * 4) = 1;
    *(u32*)(p + 0x240) = n;

    fn_800B96E8(p + 0x100, (u8)*(u32*)(p + 0x1B4));

    int i1;
    *(FigureList**)(p + 0x220) = args->unk14;
    FigureList* it1 = args->unk8;
    *(FigureList**)(p + 0x224) = args->unk18;
    *(FigureList**)(p + 0x228) = args->unk1C;
    it1->reset();

    u32 c1 = it1->count();
    lim1 = 10;
    if (c1 < 10) {
        lim1 = c1;
    }

    i1 = 0;
    for (int off = 0; i1 < lim1; off += 4, i1++) {
        *(u32*)(p + 0x1F4 + off) = it1->get();
        it1->next();
    }

    int off2;
    FigureList* it2 = args->unkC;
    *(int*)(p + 0x21C) = lim1;
    it2->reset();

    u32 c2 = it2->count();
    int i2;
    int lim2;
    lim2 = 10;
    if (c2 < 10) {
        lim2 = c2;
    }

    i2 = 0;
    for (off2 = 0; i2 < lim2; off2 += 4, i2++) {
        *(u32*)(p + 0x1C8 + off2) = it2->get();
        it2->next();
    }

    it3 = args->unk10;
    *(int*)(p + 0x1F0) = lim2;
    it3->reset();

    u32 c3 = it3->count();
    lim3 = 3;
    if (c3 < 3) {
        lim3 = c3;
    }

    i3 = 0;
    for (off3 = 0; i3 < lim3; off3 += 4, i3++) {
        *(u32*)(p + 0x1B8 + off3) = it3->get();
        it3->next();
    }

    *(int*)(p + 0x1C4) = lim3;
    return arg0;
}
