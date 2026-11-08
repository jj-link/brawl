#pragma force_active on
#include <cstdio>
#include <gf/gf_archive.h>
#include <ty/ty_fig_listmng.h>
#include <ut/ut_list.h>
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void fn_1_3C68(void*, int, void*, void*, int);
void fn_800FABEC(void*);
void fn_800FAC58(void*, const void*, int, int);
void loadMenuSound__6muMenuFv(void);
extern char lbl_33_data_30[];
extern char lbl_33_data_4C[];
extern utList lbl_8049E550;
}
struct FigMenuData { unsigned int fields[7]; bool flag1 : 1; bool flag2 : 1; bool flag3 : 1; unsigned char other : 5; };
extern "C" void fn_33_9F0(char* self) {
    char buf[24]; void* arc; void* obj; char* pa; char* pc; char* pb; utListNode* pd; int i; int zero;
    arc = __nw__FUlQ25Heaps8HeapType(0x80, 0x2A);
    if (arc != 0) { arc = __ct__9gfArchiveFv(arc); }
    *(void**)(self + 0x3F0) = arc;
    obj = __nw__FUlQ25Heaps8HeapType(0x20, 0x2A);
    if (obj != 0) {
        FigMenuData* fields = (FigMenuData*)obj;
        fields->fields[0] = 0; fields->fields[1] = 0; fields->fields[2] = 0; fields->fields[3] = 0; fields->fields[4] = 0;
        fields->flag1 = false; fields->flag2 = false; fields->fields[6] = 0; fields->fields[5] = 0xFF; fields->flag3 = false;
    }
    *(void**)(self + 0x3F4) = obj;
    fn_1_3C68(obj, 0x2A, lbl_33_data_30, *(void**)(self + 0x3F0), 0x7D000);
    pa = self; pc = self + 0x2C0; pb = self; pd = (utListNode*)(self + 0x2C4); i = 0; zero = 0;
    for (; i < 3U; i++, pa += 4, pc += 0x34, pb += 0x34, pd = (utListNode*)((char*)pd + 0x34)) {
        if (i < *(int*)(self + 0x1C4)) {
            tyFigListDataManager* manager = *(tyFigListDataManager**)(self + 0x27C);
            unsigned int id = *(unsigned int*)(pa + 0x1B8);
            tyFigListData* data = manager->getFigDataId(id);
            sprintf(buf, lbl_33_data_4C, data->name);
            fn_800FABEC(pc + 0x14);
            *(int*)(pb + 0x2C0) = zero;
            *(unsigned char*)(pb + 0x2EC) = zero;
            fn_800FAC58(pc + 0x14, buf, 0x2B, zero);
        } else { lbl_8049E550.removeExist(pd); *(int*)((char*)pd + 8) = zero; }
    }
    loadMenuSound__6muMenuFv();
}