#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_78_8978(u8* self, int a, int b, unsigned int mode)
{
    u8* p;
    if (mode != 1) {
        return;
    }
    p = *(u8**)(self + 0x160);
    if (*p == 0) {
        return;
    }
    if (**(u8**)(self + 0x164) == 1) {
        return;
    }
    *p = *p - 1;
    if (**(u8**)(self + 0x160) == 0) {
        **(u8**)(self + 0x15c) = **(u8**)(self + 0x15c) + 1;
        if (**(u8**)(self + 0x15c) > 3) {
            **(u8**)(self + 0x15c) = 3;
        }
    }
    **(u8**)(self + 0x164) = 1;
}
}
