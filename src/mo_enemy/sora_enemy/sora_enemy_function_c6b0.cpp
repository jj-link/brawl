#include <em/em_manager.h>
#pragma force_active on

extern emManager* lbl_41_bss_30;

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __dla__FPv(void*);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" u32 fn_27_6FCF4(u32, u32);
extern "C" void fn_27_6FDE0(u32);
extern "C" void* fn_41_C810(void*, u32, void*, u32, void*, u8);

void emManager::create(u32 numEntries1, u32 numEntries2, u8 primidFaceType) {
    if (!lbl_41_bss_30) {
        void* entries1 = __nwa__FUlQ25Heaps8HeapType(numEntries1 * 0x18, 0x25);
        if (entries1) {
            void* entries2 = __nwa__FUlQ25Heaps8HeapType(numEntries2 * 0x18, 0x25);
            if (!entries2) {
                __dla__FPv(entries1);
            } else if (!fn_27_6FCF4(1, (numEntries2 << 1) + 1)) {
                __dla__FPv(entries1);
                __dla__FPv(entries2);
            } else {
                emManager* manager = (emManager*)__nw__FUlQ25Heaps8HeapType(0x20, 0x25);
                if (manager) {
                    manager = (emManager*)fn_41_C810(manager, numEntries1, entries1,
                                                     numEntries2, entries2, primidFaceType);
                }
                lbl_41_bss_30 = manager;
                if (!manager) {
                    __dla__FPv(entries1);
                    __dla__FPv(entries2);
                    fn_27_6FDE0(1);
                }
            }
        }
    }
}
