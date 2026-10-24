#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 OSGetTick(void);

void fn_801D71F4(s32 arg0) {
    u32 t;
    u32 v;
    u32 s;
    u32 *hw;

    hw = (u32 *)0xCD800000;
    s = arg0 << 8;
    v = hw[0x60];
    v &= 0xFFFFFEFF;
    v |= s;
    hw[0x60] = v & 0xFFFFFF7F;
    hw[0x74] &= 0x3FFFFFFF;

    t = OSGetTick();
    do {
    } while ((u32)((OSGetTick() - t) * 8) / ((*(u32 *)0x800000F8 >> 2) / 125000) < 100);

    if (arg0 == 0) {
        v = hw[0x73];
        v = ((v & 0xFFFC003F) | 0xFC0) & 0xF803FFC0 | 0x04640000;
        hw[0x73] = v;
    } else {
        v = hw[0x73];
        v = ((((v & 0xFFFC003F) | 0xFFC0) & 0xFFFFFFC0) | 0xE) & 0xF803FFFF | 0x04B00000;
        hw[0x73] = v;
    }

    t = OSGetTick();
    do {
    } while ((u32)((OSGetTick() - t) * 8) / ((*(u32 *)0x800000F8 >> 2) / 125000) < 100);

    hw[0x74] &= 0xEFFFFFFF;

    t = OSGetTick();
    do {
    } while ((u32)((OSGetTick() - t) * 8) / ((*(u32 *)0x800000F8 >> 2) / 125000) < 1000);

    hw[0x74] = (hw[0x74] & 0xBFFFFFFF) | 0x40000000;

    t = OSGetTick();
    do {
    } while ((u32)((OSGetTick() - t) * 8) / ((*(u32 *)0x800000F8 >> 2) / 125000) < 1000);

    hw[0x74] = (hw[0x74] & 0x7FFFFFFF) | 0x80000000;

    t = OSGetTick();
    do {
    } while ((u32)((OSGetTick() - t) * 8) / ((*(u32 *)0x800000F8 >> 2) / 125000) < 1000);
}
