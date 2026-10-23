#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

s32 fn_8027DD18(void *arg0)
{
    s32 off;
    s32 n;
    s32 cnt = *(s32 *)((char *)arg0 + 8);
    s32 i;

    n = 0;
    off = 0;
    for (i = 0; i <= cnt; i++) {
        if ((*(u32 *)((char *)*(char **)arg0 + off) + 0x10000) != 0xFFFF) {
            break;
        }
        off += 4;
        n += 1;
    }

    return n;
}
