#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void fn_801F45A8(u8, u16, void *);
extern "C" void GXSetFog(int, u8 *, float, float, float, float);

extern "C" void fn_801B5F34(void **arg0) {
    char *obj;
    u8 color[4];

    obj = (char *)*arg0;
    if (obj != 0) {
        if (*(int *)obj != 0) {
            fn_801F45A8((u8)obj[0x18], *(u16 *)(obj + 0x1A), obj + 0x1C);
        }
        color[0] = (u8)obj[0x14];
        color[1] = (u8)obj[0x15];
        color[2] = (u8)obj[0x16];
        color[3] = (u8)obj[0x17];
        GXSetFog(*(int *)obj, color, *(float *)(obj + 4), *(float *)(obj + 8), *(float *)(obj + 0xC), *(float *)(obj + 0x10));
    }
}
