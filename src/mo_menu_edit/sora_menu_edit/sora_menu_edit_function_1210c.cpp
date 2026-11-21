#include <types.h>
#include <ut/ut_list.h>
#include <sr/sr_common.h>
#pragma force_active on
extern "C" {
void fn_6_180(void*, void*);
void fn_6_278(void*, int, int, void*);
void fn_80078990(int);
extern u8 lbl_5_data_660[];
extern u8 lbl_5_data_66C[];
extern u8 lbl_5_data_9B0[];
extern u8 lbl_5_data_BD0[];
extern u8 lbl_5_data_CD8[];
extern utList lbl_8049E550;
extern int lbl_805A01D8;
}
struct Task {
    u8 pad[0x1b0];
    Task() {
        fn_6_180(this, lbl_5_data_660);
        *(void**)((u8*)this + 0x3c) = lbl_5_data_9B0;
    }
};
inline void construct(void* obj2) {
    u8* node;
    u8* node2;
    fn_6_278(obj2, 0x1f, 6, lbl_5_data_66C);
    *(void**)((u8*)obj2 + 0x1D08) = lbl_5_data_BD0;
    node = (u8*)obj2 + 0x1D0C;
    *(int*)((u8*)obj2 + 0x1D14) = 0;
    *(int*)((u8*)obj2 + 0x1D0C) = 0;
    *(int*)((u8*)obj2 + 0x1D10) = 0;
    lbl_8049E550.addTail((utListNode*)node);
    *(void**)(node + 0x8) = &lbl_8049E550;
    *(void**)(node + 0xC) = lbl_5_data_CD8;
    *(int*)(node + 0x10) = 0;
    *(u8*)(node + 0x14) = 0;
    node2 = (u8*)obj2 + 0x1D24;
    *(int*)((u8*)obj2 + 0x1D2C) = 0;
    *(int*)((u8*)obj2 + 0x1D24) = 0;
    *(int*)((u8*)obj2 + 0x1D28) = 0;
    lbl_8049E550.addTail((utListNode*)node2);
    *(void**)(node2 + 0x8) = &lbl_8049E550;
    *(void**)(node2 + 0xC) = lbl_5_data_CD8;
    *(int*)(node2 + 0x10) = 0;
    *(u8*)(node2 + 0x14) = 0;
    *(int*)((u8*)obj2 + 0x1D3C) = 0;
    *(int*)((u8*)obj2 + 0x1D40) = -1;
    *(int*)((u8*)obj2 + 0x1D4C) = 0;
    *(int*)((u8*)obj2 + 0x1D50) = 0;
    *(int*)((u8*)obj2 + 0x1D54) = -1;
    *(int*)((u8*)obj2 + 0x1D58) = 0;
    *(int*)((u8*)obj2 + 0x1D5C) = 0;
    *(int*)((u8*)obj2 + 0x1D60) = 0;
    *(int*)((u8*)obj2 + 0x1D64) = 0;
    *(int*)((u8*)obj2 + 0x1D68) = 0;
    *(u8*)((u8*)obj2 + 0x1CEE) = 1;
    *(int*)((u8*)obj2 + 0x1CF8) = 0x32;
}
extern "C" void* fn_5_1210C(int arg0) {
    Task* obj = new ((Heaps::HeapType)0x2a) Task;
    void* obj2 = operator new(0x1D6C, (Heaps::HeapType)0x2a);
    if (obj2) construct(obj2);
    *(void**)((u8*)obj + 0x1AC) = obj2;
    *(int*)((u8*)obj2 + 0x1D3C) = arg0;
    fn_80078990(lbl_805A01D8);
    return obj;
}