#pragma force_active on
#include <types.h>
#include "ut/ut_list.h"

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
extern "C" void fn_27_57D38();
extern "C" void fn_27_57D6C();

struct Node {
    utListNode m_node;
    s32 m_index;
    s32 unk_C;
    s32 unk_10;
};

struct Self {
    u32 unk0;
    Node* m_arr;
    s32 m_count;
    utList m_list;
};

extern "C" void fn_27_57C88(Self* self, int count, int heap_type) {
    self->m_count = count;
    void* heap = __nwa__FUlQ25Heaps8HeapType((unsigned long)count * 0x14 + 0x10, heap_type);
    self->m_arr = (Node*)__construct_new_array(heap, fn_27_57D38, fn_27_57D6C, (unsigned long)0x14, count);
    int off, i;
    i = 0;
    off = 0;
    while (i < count) {
        ((Node*)((char*)self->m_arr + off))->m_index = i;
        self->m_list.addTail((utListNode*)((char*)self->m_arr + off));
        off += 0x14;
        i++;
    }
}