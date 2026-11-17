#include <types.h>
#pragma force_active on
class Class_CF8 {
public:
 virtual void fn_27_1000C();
 virtual void fn_27_100D0();
 virtual u32 fn_27_100CC();
 virtual void fn_27_10094();
 virtual u32 fn_27_100C8();
 virtual u32 fn_27_100C4();
};
extern "C" {
void* fn_27_2816D0();
Class_CF8* fn_27_2DF188(void*);
void fn_27_1DC5E8(void*, int, const void*, u32, u32, u32, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_3A6734(void*, void*, void*, void*, void*);
void fn_27_1DC870(void*, int);
void fn_27_1D8FC8(void*, int);
extern char lbl_27_data_9D540[];
extern char lbl_27_data_9D550[];
}
extern "C" void* fn_27_3A62BC(void* self, void* a, void* b, const u32* c) {
 unsigned char buf[0x40];
 fn_27_1DC5E8(buf, 0x8b, c, fn_27_2DF188(b)->fn_27_100CC(), fn_27_2DF188(b)->fn_27_100C8(), fn_27_2DF188(b)->fn_27_100C4(), (unsigned char)*c, -1, fn_27_2816D0(), 0, 0, 0, 0, 0, 0, 0);
 fn_27_3A6734(self, lbl_27_data_9D540, a, b, buf);
 fn_27_1DC870(buf, -1);
 *(void**)((char*)self + 0x3c) = lbl_27_data_9D550;
 *(void**)((char*)self + 0x40) = lbl_27_data_9D550 + 0x64;
 *(void**)((char*)self + 0x48) = lbl_27_data_9D550 + 0x70;
 *(void**)((char*)self + 0x54) = lbl_27_data_9D550 + 0x84;
 *(void**)((char*)self + 0x64) = lbl_27_data_9D550 + 0xdc;
 *(void**)((char*)self + 0x70) = lbl_27_data_9D550 + 0xec;
 *(void**)((char*)self + 0x7c) = lbl_27_data_9D550 + 0x100;
 *(void**)((char*)self + 0x88) = lbl_27_data_9D550 + 0x118;
 *(void**)((char*)self + 0x90) = lbl_27_data_9D550 + 0x124;
 fn_27_1D8FC8(self, 0);
 return self;
}