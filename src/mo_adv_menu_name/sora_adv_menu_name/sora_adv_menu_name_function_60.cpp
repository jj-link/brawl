#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_task.h>
#include <mu/menu.h>
#pragma force_active on
struct DataFirst { char first; };
extern "C" {
extern char lbl_28_data_0[];
extern u8 lbl_28_data_230[];
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_28_25C(void*);
void fn_28_290(void*);
void fn_28_250(void*);
void __dt__14gfFileIOHandleFv(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
#pragma push
#pragma opt_propagation off
void* fn_28_60(u8* object) {
    char* data = lbl_28_data_0;
    DataFirst* p = (DataFirst*)data;
    char DataFirst::*first = &DataFirst::first;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(object, &(p->*first), 8, 15, 8, true);
    *(void**)(object + 0x3C) = (void*)lbl_28_data_230;
    *(int*)(object + 0x48) = 0;
    fn_800B96E8(object + 0x60, 255);
    *(int*)(object + 0x108) = 0;
    *(int*)(object + 0x120) = 0;
    object[0x124] = 0;
    *(int*)(object + 0x160) = 0;
    *(int*)(object + 0x164) = 0;
    *(int*)(object + 0x168) = 0;
    *(int*)(object + 0x16C) = 8;
    __construct_array(object + 0x170, fn_28_25C, fn_28_290, 0xB8, 2);
    __construct_array(object + 0x340, fn_28_250, __dt__14gfFileIOHandleFv, 4, 2);
    object[0x350] = 0;
    object[0x351] = 0;
    *(int*)(object + 0x160) = 0;
    *(int*)(object + 0x164) = 0;
    *(int*)(object + 0x12c) = 0;
    *(int*)(object + 0x130) = 0;
    *(int*)(object + 0x134) = 0;
    *(int*)(object + 0x138) = 0;
    *(int*)(object + 0x13c) = 0;
    *(int*)(object + 0x140) = 0;
    *(int*)(object + 0x144) = 0;
    *(int*)(object + 0x148) = 0;
    *(int*)(object + 0x14c) = 0;
    *(int*)(object + 0x150) = 0;
    *(int*)(object + 0x154) = 0;
    *(int*)(object + 0x158) = 0;
    *(int*)(object + 0x15c) = 0;
    *(int*)(object + 0x40) = 0;
    for (int j = 0; j < 4; ++j) *(int*)(object + 0x218 + j * 4) = 0;
    *(int*)(object + 0x10c) = 0;
    *(int*)(object + 0x114) = 0;
    *(int*)(object + 0x50) = 0;
    *(int*)(object + 0x58) = 0;
    *(int*)(object + 0x44) = 0;
    for (int j = 0; j < 4; ++j) *(int*)(object + 0x2d0 + j * 4) = 0;
    *(int*)(object + 0x110) = 0;
    *(int*)(object + 0x118) = 0;
    *(int*)(object + 0x54) = 0;
    *(int*)(object + 0x5c) = 0;
    object[0x323] = 127;
    object[0x30E] = 127;
    object[0x324] = 126;
    object[0x30F] = 126;
    object[0x325] = 125;
    object[0x310] = 125;
    object[0x326] = 124;
    object[0x311] = 124;
    object[0x327] = 123;
    object[0x312] = 123;
    object[0x328] = 0;
    object[0x313] = 0;
    object[0x348] = 0;
    object[0x349] = 0;
    object[0x352] = 0;
    object[0x353] = 0;
    ((gfFileIOHandle*)(object + 0x340))->readRequest(data + 0xC, (HeapType)0x2B, 0, 0);
    ((gfFileIOHandle*)(object + 0x344))->readRequest(data + 0x2C, (HeapType)0x2B, 0, 0);
    muMenu::loadMenuSound();
    return object;
}
#pragma pop
}
