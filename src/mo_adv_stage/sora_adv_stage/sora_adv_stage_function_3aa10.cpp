#include <types.h>
#pragma force_active on
struct Col {
    u8 r, g, b, a;
};
extern "C" {
extern char lbl_40_data_14BD8[];
Col fn_27_26C3F0(void*, const u32*, const char*, const u32*);
Col fn_27_26C520(void*, const u32*, const char*, const u32*);
}
#define C(off) (*(Col*)(self + (off)))
#define U(off) ((const u32*)(data + (off)))
extern "C" void fn_40_3AA10(char* self) {
    char* data = lbl_40_data_14BD8;
    C(0x1c0) = fn_27_26C3F0(self, U(0x14c), data + 0x80, U(0x150));
    C(0x1c4) = fn_27_26C3F0(self, U(0x154), data + 0x88, U(0x158));
    C(0x1c8) = fn_27_26C520(self, U(0x15c), data + 0x94, U(0x160));
    C(0x1cc) = fn_27_26C520(self, U(0x164), data + 0xa0, U(0x168));
    C(0x1d0) = fn_27_26C520(self, U(0x16c), data + 0xb0, U(0x170));
    C(0x1d4) = fn_27_26C3F0(self, U(0x174), data + 0xc0, U(0x178));
    C(0x1d8) = fn_27_26C3F0(self, U(0x17c), data + 0xc8, U(0x180));
    C(0x1dc) = fn_27_26C520(self, U(0x184), data + 0xd4, U(0x188));
    C(0x1e0) = fn_27_26C520(self, U(0x18c), data + 0xe4, U(0x190));
    C(0x1e4) = fn_27_26C520(self, U(0x194), data + 0xf4, U(0x198));
    C(0x1e8) = fn_27_26C3F0(self, U(0x19c), data + 0x104, U(0x1a0));
    C(0x1ec) = fn_27_26C3F0(self, U(0x1a4), data + 0x10c, U(0x1a8));
    C(0x1f0) = fn_27_26C520(self, U(0x1ac), data + 0x118, U(0x1b0));
    C(0x1f4) = fn_27_26C520(self, U(0x1b4), data + 0x124, U(0x1b8));
    C(0x1f8) = fn_27_26C3F0(self, U(0x1bc), data + 0x130, U(0x1c0));
    C(0x1fc) = fn_27_26C520(self, U(0x1c4), data + 0x13c, U(0x1c8));
}
