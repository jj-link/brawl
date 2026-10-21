#include <types.h>
#pragma force_active on

extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void* fn_25_E48(void);
void fn_25_1104(void);
void fn_25_123C(void* p);
void* fn_25_0(void);
void fn_25_3F8(void);
void fn_25_56C(void* p);
void* fn_25_166C(void);
void fn_25_286C(void);
void fn_25_2E14(void* p);
void* fn_37_0(void);
void fn_37_CC8(void);
void fn_37_FF8(void* p);
extern const char lbl_1_data_6560[];
extern const char lbl_1_data_6584[];

void fn_1_20540(u8* self) {
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x18, lbl_1_data_6560, 0x2b, 0, 0);
    *(void**)(self + 0x8) = fn_25_E48();
    fn_25_1104();
    fn_25_123C(*(void**)(self + 0x8));
    *(void**)(self + 0xC) = fn_25_0();
    fn_25_3F8();
    fn_25_56C(*(void**)(self + 0xC));
    *(void**)(self + 0x10) = fn_25_166C();
    fn_25_286C();
    ((u8*)*(void**)(self + 0x10))[0x144C] = 1;
    fn_25_2E14(*(void**)(self + 0x10));
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x2C, lbl_1_data_6584, 0x2b, 0, 0);
    *(void**)(self + 0x14) = fn_37_0();
    fn_37_CC8();
    fn_37_FF8(*(void**)(self + 0x14));
    self[0x24] = 0;
    self[0x25] = 0;
}
}
