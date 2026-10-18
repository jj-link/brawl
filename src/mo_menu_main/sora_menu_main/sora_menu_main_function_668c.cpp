#include <types.h>
#pragma force_active on

extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void fn_800151FC(void* self, const char* name, int heap, int a, int b, int c);
void* getInstance__9itManagerFv();
void loadMenuSound__6muMenuFv();

void fn_2_668C(u8* self);
}

extern void* g_GameGlobal;
extern u8 lbl_2_data_B98[];

void fn_2_668C(u8* self) {
    u8* base = lbl_2_data_B98;
    u32 r30 = 0;
    u8* rec;
    const char* name;

    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x148, (const char*)(base + 0x8), 0x2b, 0, 0);

    rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    {
        u8* dst = self + 0x14c;
        name = (const char*)(base + 0x5c);
        if ((rec[0x28] >> 7) & 1) {
            name = (const char*)(base + 0x2c);
        }
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(dst, name, 0x2b, 0, 0);
    }

    rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    {
        u8* dst = self + 0x150;
        name = (const char*)(base + 0xb8);
        if ((rec[0x28] >> 7) & 1) {
            name = (const char*)(base + 0x88);
        }
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(dst, name, 0x2b, 0, 0);
    }

    fn_800151FC(self + 0x154, (const char*)(base + 0xe4), 0x2b, 0, 0, 0xff);

    {
        u8* itm = (u8*)getInstance__9itManagerFv();
        u32* p = *(u32**)(itm + 0x14b8);
        if (p != nullptr) {
            r30 = p[1];
        }
    }

    *(u32*)(*(u8**)(self + 0x40) + 0x162c) = r30;
    loadMenuSound__6muMenuFv();
}
