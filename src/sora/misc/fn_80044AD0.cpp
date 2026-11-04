#include <types.h>
#include <gf/gf_archive_db.h>
#include <ut/ut_list.h>
#pragma force_active on

extern char lbl_8042B644[];

extern "C" {
void fn_80044BE8();
void* fn_80044BFC(void* arg0, int arg1);
void* __construct_new_array(void* block, void (*ctor)(), void (*dtor)(), u32 size, u32 count);
void* __nwa__FUlQ25Heaps8HeapType(u32 size, int heap);
}

extern "C" void* fn_80044AD0(void* arg0, u32 arg1) {
    u8* self = (u8*)arg0;
    u32 off;
    u32 i;
    u8* node;

    *(u32*)(self + 0x8) = arg1;
    *(void**)(self + 0x0) = lbl_8042B644;
    *(u32*)(self + 0x4) = 0;
    *(u32*)(self + 0x14) = 0;
    *(u32*)(self + 0x10) = 0;
    *(u32*)(self + 0x18) = 0;
    *(u32*)(self + 0x20) = 0;
    *(u32*)(self + 0x1C) = 0;
    *(u32*)(self + 0x24) = 0;
    *(u32*)(self + 0x2C) = 0;
    *(u32*)(self + 0x28) = 0;
    *(u32*)(self + 0x30) = 0;
    *(u32*)(self + 0x38) = 0;
    *(u32*)(self + 0x34) = 0;
    *(u32*)(self + 0x3C) = 0;
    *(u32*)(self + 0x44) = 0;
    *(u32*)(self + 0x40) = 0;
    *(u32*)(self + 0x48) = 0;

    *(gfArchiveDatabase**)(self + 0x4) = gfArchiveDatabase::create(arg1, (Heaps::HeapType)2);
    *(void**)(self + 0xC) = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(arg1 * 0x1C + 0x10, 2),
                                                  fn_80044BE8, (void (*)())fn_80044BFC, 0x1C, arg1);

    i = 0;
    off = 0;
    for (; i < arg1; i++) {
        node = *(u8**)(self + 0xC) + off;
        *(u32*)(node + 0xC) = 0xFFFF;
        *(u32*)(node + 0x10) = 0xFFFF;
        *(u16*)(node + 0x8) = 0;
        *(u32*)(node + 0x14) = 0;
        ((utList*)(self + 0x10))->addTail((utListNode*)(*(u8**)(self + 0xC) + off));
        off += 0x1C;
    }
    return arg0;
}
