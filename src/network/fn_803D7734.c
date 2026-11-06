#pragma force_active on
typedef unsigned int u32;
#define SWAP(x) ((((x) << 24) | (((x) << 8) & 0x00ff0000)) | (((x) >> 24) | (((x) >> 8) & 0x0000ff00)))
int fn_803D7734(void *a, void *b, u32 *c, u32 *d) {
    u32 x, y, z, p, q;
    *c = -1;
    *d = -1;
    x = *(u32 *)((char *)b + 0);
    if (SWAP(x) == 0x41615252) {
        y = *(u32 *)((char *)b + 0x1e4);
        if (SWAP(y) == 0x61417272) {
            z = *(u32 *)((char *)b + 0x1fc);
            if (SWAP(z) == 0xaa550000) {
                x = *(u32 *)((char *)b + 0x1e8);
                y = *(u32 *)((char *)b + 0x1ec);
                p = SWAP(x);
                q = SWAP(y);
                if (p >= 2 && p < *(u32 *)((char *)a + 0x34) + 2) *c = p;
                if (q >= 2 && q < *(u32 *)((char *)a + 0x34) + 2) *d = q;
            }
        }
    }
    return 0;
}