#include <gf/gf_file_io_handle.h>
#include <gm/gm_global.h>
#include <mu/menu.h>
#pragma force_active on

extern "C" {
extern char lbl_32_data_0[];
extern char lbl_32_data_F0[];
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_32_230(void*);
void fn_32_264(void*);
void fn_32_2B0(void*);
void fn_32_2E4(void*);
void fn_32_2A4(void*);
void __dt__14gfFileIOHandleFv(void*);
}
#define W(o) (*(int*)(self + (o)))
#define B(o) (*(unsigned char*)(self + (o)))
struct DataFirst { char first; };
#pragma push
#pragma opt_propagation off
extern "C" void* fn_32_94(char* self) {
    char* data = lbl_32_data_0;
    DataFirst* p = (DataFirst*)data;
    char DataFirst::*first = &DataFirst::first;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, &(p->*first), 8, 15, 8, true);
    *(void**)(self + 0x3c) = lbl_32_data_F0;
    W(0x40) = 0;
    W(0x44) = 0;
    W(0x48) = 0;
    W(0x50) = 0;
    __construct_array(self + 0x54, fn_32_230, fn_32_264, 0xa8, 2);
    W(0x1c0) = 0;
    W(0x1c4) = 0;
    W(0x1c8) = 0;
    W(0x1cc) = 4;
    __construct_array(self + 0x1d0, fn_32_2B0, fn_32_2E4, 0xac, 2);
    B(0x33c) = 1;
    __construct_array(self + 0x340, fn_32_2A4, __dt__14gfFileIOHandleFv, 4, 3);
    W(0x1c0) = 0;
    W(0x1c4) = 0;
    W(0x1b0) = 0;
    W(0x1b4) = 0;
    W(0x1b8) = 0;
    W(0x1bc) = 0;
    B(0x34c) = 0;
    B(0x34d) = 0;
    B(0x34e) = 0;
    ((gfFileIOHandle*)(self + 0x340))->readRequest(data + 0x10, (HeapType)0x2b, 0, 0);
    if (!((((unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)) {
        ((gfFileIOHandle*)(self + 0x344))->readRequest(data + 0x2c, (HeapType)0x2b, 0, 0);
    } else {
        ((gfFileIOHandle*)(self + 0x344))->readRequest(data + 0x58, (HeapType)0x2b, 0, 0);
    }
    ((gfFileIOHandle*)(self + 0x348))->readRequest(data + 0x88, (HeapType)0x2b, 0, 0);
    muMenu::loadMenuSound();
    return self;
}
#pragma pop
