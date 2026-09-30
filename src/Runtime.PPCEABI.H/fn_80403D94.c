typedef unsigned long u32;

extern u32 gTRKCPUState[];

u32 fn_80403D94(void) {
    return gTRKCPUState[0x80 / sizeof(u32)];
}
