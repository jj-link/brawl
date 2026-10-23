#pragma force_active on
extern "C" {
typedef unsigned int u32;
typedef int s32;

void fn_800F09D0(u32 v, s32* out, s32 flag) {
    s32 ok;
    u32 val = v;
    if (flag == 0) {
        val = 0x01000000;
        ok = 0;
    } else {
        ok = 1;
    }
    switch (ok) {
    case 0:
        val >>= 17;
        ok = 0;
        break;
    }
    out[0] = ok;
    out[1] = (s32)val;
}
}
