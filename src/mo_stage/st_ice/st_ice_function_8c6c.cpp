#include <types.h>
#pragma force_active on

extern "C" {

extern const float lbl_62_rodata_F4;

#define DECLARE_VF(n) virtual void* vf##n(int a, int b);

struct IceThing {
    u8 pad_0000[0x3c];
    DECLARE_VF(0) DECLARE_VF(1) DECLARE_VF(2) DECLARE_VF(3) DECLARE_VF(4)
    DECLARE_VF(5) DECLARE_VF(6) DECLARE_VF(7) DECLARE_VF(8) DECLARE_VF(9)
    DECLARE_VF(10) DECLARE_VF(11) DECLARE_VF(12) DECLARE_VF(13) DECLARE_VF(14)
    DECLARE_VF(15) DECLARE_VF(16) DECLARE_VF(17) DECLARE_VF(18) DECLARE_VF(19)
    DECLARE_VF(20) DECLARE_VF(21) DECLARE_VF(22) DECLARE_VF(23) DECLARE_VF(24)
    DECLARE_VF(25) DECLARE_VF(26) DECLARE_VF(27) DECLARE_VF(28) DECLARE_VF(29)
    DECLARE_VF(30) DECLARE_VF(31) DECLARE_VF(32) DECLARE_VF(33) DECLARE_VF(34)
    DECLARE_VF(35) DECLARE_VF(36) DECLARE_VF(37) DECLARE_VF(38) DECLARE_VF(39)
    DECLARE_VF(40) DECLARE_VF(41) DECLARE_VF(42)
};

#undef DECLARE_VF

void* fn_62_8C6C(IceThing* self, int a, int b, unsigned int c) {
    void* result = self->vf40(a, b);
    if (result != 0) {
        s8* b150 = (s8*)((char*)self + 0x150);
        switch (*b150) {
        case 1:
            *(float*)((char*)self + 0x168) = lbl_62_rodata_F4;
            if (c == 1) {
                *(float*)((char*)self + 0x154) = *(float*)((char*)result + 0x3c);
            }
            break;
        }
    }
    return result;
}

}
