#include <gf/gf_3d_scene.h>
#include <gf/gf_heap_manager.h>
#include <ut/ut_list.h>
#pragma force_active on

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
void* __construct_new_array(void*, void (*)(void*), void*, unsigned long, unsigned long);
void fn_27_22890C(void*);
void fn_27_229C1C();
void fn_27_229C58();
void* fn_801B5AD0(void*, void*, void (*)(), int, int, int);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
extern char lbl_27_data_4A730[];
extern char lbl_27_data_4A770[];
extern float lbl_27_rodata_3708;
}
struct Entry { char pad[12]; void* ptr; };
struct Item { char pad[0x34]; };
struct Slot { unsigned char unused : 1; unsigned char flags : 1; unsigned char rest : 6; char pad[3]; unsigned char byte; char pad2[3]; int value; };
struct Block { char byte; char pad[3]; int value; char pad2[5]; char byte2, byte3, pad3; };
struct Object {
 char base[0x40];
 unsigned char a : 8; unsigned char b : 8; unsigned char c : 8; unsigned char d : 8;
 unsigned short count, count2;
 Entry* entries;
 int zero;
 char pad50[4];
 float floats[6];
 int minus;
 char pad70[4];
 nw4r::g3d::ScnMdl *model1, *model2;
 int zero7c;
 Item* items;
 utList list1, list2;
 Slot slots[36];
 Block blocks[4];
};
inline void clearBlocks(Block* q, Block* end) {
 do { q->value = 0; ++q; } while (q < end);
}
extern "C" Object* fn_27_228454(Object* p, unsigned short a, unsigned short b) {
 int zero = 0;
 __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_27_data_4A730, 0x21, 14, 6, true);
 p->a = 1;
 *(void**)((char*)p + 0x3c) = lbl_27_data_4A770;
 p->b = 0;
 *(unsigned int*)((char*)p + 0x40) &= 0xffffff00;
 p->count = a;
 p->count2 = b;
 p->model1 = (nw4r::g3d::ScnMdl*)zero;
 p->model2 = (nw4r::g3d::ScnMdl*)zero;
 clearBlocks(&p->blocks[0], &p->blocks[4]);
 unsigned short n = p->count2;
 float f = lbl_27_rodata_3708;
 p->zero = zero;
 p->floats[0] = f;
 p->floats[1] = f;
 p->floats[2] = f;
 p->floats[3] = f;
 p->floats[4] = f;
 p->floats[5] = f;
 p->minus = -1;
 p->items = (Item*)__construct_new_array(__nwa__FUlQ25Heaps8HeapType(n * 0x34 + 0x10, 15), fn_27_22890C, 0, 0x34, n);
 *(void**)((char*)&p->list1 + 4) = 0;
 *(void**)&p->list1 = 0;
 *(int*)((char*)&p->list1 + 8) = 0;
 *(void**)((char*)&p->list2 + 4) = 0;
 *(void**)&p->list2 = 0;
 *(int*)((char*)&p->list2 + 8) = 0;
 unsigned int i = 0;
 unsigned int offset = 0;
 for (; i < p->count2; offset += 0x34, ++i) p->list2.addTail((utListNode*)((char*)p->items + offset));
 p->zero7c = zero;
 p->entries = (Entry*)__nwa__FUlQ25Heaps8HeapType(p->count * 0x10, 15);
 unsigned int j = 0;
 unsigned int offset2 = 0;
 for (; j < p->count; ++j, offset2 += 0x10)
  ((Entry*)((char*)p->entries + offset2))->ptr = __nwa__FUlQ25Heaps8HeapType(p->count2 * 4, 15);
 for (int i = 0; i < 36; ++i) {
  p->slots[i].flags = 0;
  p->slots[i].value = 0;
  p->slots[i].byte = 0;
 }
 for (int i = 0; i < 4; ++i) {
  p->blocks[i].byte = 0;
  p->blocks[i].byte2 = 0;
  p->blocks[i].byte3 = 0;
 }
 p->c = 0;
 MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
 p->model1 = (nw4r::g3d::ScnMdl*)fn_801B5AD0(alloc, 0, fn_27_229C1C, 0, 1, 0);
 p->model2 = (nw4r::g3d::ScnMdl*)fn_801B5AD0(alloc, 0, fn_27_229C58, 0, 1, 0);
 fn_801AAFF0(p->model1, 255);
 fn_801AAFF0(p->model2, 255);
 fn_801AB014(p->model1, 255);
 fn_801AB014(p->model2, 255);
 g_gfSceneRoot->add(gfSceneRoot::Layer_Ground, p->model1);
 g_gfSceneRoot->add(gfSceneRoot::Layer_All, p->model2);
 return p;
}
