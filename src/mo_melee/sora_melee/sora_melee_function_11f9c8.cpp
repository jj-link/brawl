#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
int fn_27_11F9C8(char *p) {
    int j;
    char *q;
    char *e;
    int count = 0;
    u32 i;
    u32 val;
    for (i = 0; i < 8; i++) {
        e = p + (unsigned char)i * 0x30;
        if (*(s32 *)(e + 0x338) != -1) {
            q = e;
            for (j = 0; j < 4; j++) {
                if (*(u32 *)(q + 0x310) != 0xffff) {
                    val = *(u32 *)(e + 0x310 + j * 8);
                    goto found;
                }
                q += 8;
            }
            val = 0x10000 - 1;
found:
            if (val != 0xffff) {
                count++;
            }
        }
    }
    return count;
}
}
