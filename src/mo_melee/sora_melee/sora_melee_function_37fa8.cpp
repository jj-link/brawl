#include <types.h>
#pragma force_active on

extern "C" {

extern void* lbl_27_bss_B8;
extern s32 lbl_27_bss_B0;

void* fn_27_4FAB4(void* manager);
void fn_27_502EC(void* mgr, s16 val);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heapType);

struct WnPikachuStorage {
    u8 pad_00[0xC];
    void* m_0C;
    u8 pad_10[0x8];
    s32 m_18;
    u8 pad_1C[0xC];
    u8 m_28[0xC];
    void* m_34;
    void* m_38;
    void* m_3C;
    u8 pad_40[0x30];
    s16 m_70;
    u8 m_72;
    u8 pad_73[3];
};

void fn_27_37FA8(WnPikachuStorage* obj) {
    void* manager;
    if (!lbl_27_bss_B8) {
        void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
        if (mem) {
            mem = fn_27_4FAB4(mem);
        }
        lbl_27_bss_B8 = mem;
    }
    manager = lbl_27_bss_B8;
    fn_27_502EC(manager, obj->m_70);
    obj->m_34 = &obj->m_28;
    obj->m_38 = obj;
    obj->m_3C = &obj->m_0C;
    obj->m_18 = lbl_27_bss_B0++;
    obj->m_70 = -1;
    obj->m_72 = 0;
}

}
