#include <types.h>
#pragma force_active on
extern "C" {

extern void* g_GameGlobal;
extern void* g_gfSceneRoot;
extern char lbl_34_rodata_48[];

struct Record {
    char pad[0x28];
    unsigned char flags;
};

extern void* fn_1_3E50(void*);
extern int isLoadFinishMenuSound__6muMenuFv(void*);
extern Record* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
extern void* fn_80015DB4(void*, int, int, int, u16);
extern void Init__Q34nw4r3g3d7ResFileFPv(void*);
extern void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
extern void fn_801971D0(void*, void*);
extern void fn_8000D6DC(void*, void*);
extern void fn_34_B1C(void*, void*, int, void*);

int fn_34_C10(void* self) {
    char* p = (char*)self;
    void* spC;
    void* sp8;

    void* menu = fn_1_3E50(*(void**)(p + 0x5ac));
    if (menu == 0) {
        return *(int*)(p + 0x1bc);
    }
    if (isLoadFinishMenuSound__6muMenuFv(menu) == 0) {
        return *(int*)(p + 0x1bc);
    }

    sp8 = 0;
    Record* record = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    int r6 = 0x14 + ((record->flags >> 7) & 1);
    void* r = fn_80015DB4(*(void**)(p + 0x5a8), 0, 1, r6, (u16)0xFFFE);
    *(void**)(p + 0x12c) = r;
    Init__Q34nw4r3g3d7ResFileFPv(p + 0x12c);
    void* anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(p + 0x12c, 0);
    sp8 = anm;
    spC = anm;
    fn_801971D0(&sp8, &spC);
    fn_8000D6DC(g_gfSceneRoot, &sp8);

    r = fn_80015DB4(*(void**)(p + 0x5a8), 0, 1, 0, (u16)0xFFFE);
    *(void**)(p + 0x130) = r;
    Init__Q34nw4r3g3d7ResFileFPv(p + 0x130);

    r = fn_80015DB4(*(void**)(p + 0x5a8), 0, 1, 0xa, (u16)0xFFFE);
    *(void**)(p + 0x134) = r;
    Init__Q34nw4r3g3d7ResFileFPv(p + 0x134);

    fn_34_B1C(self, lbl_34_rodata_48, 2, p + 0x130);
    return 1;
}
}
