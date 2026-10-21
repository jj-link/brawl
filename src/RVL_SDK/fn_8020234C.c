#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);

void fn_8020234C(void *arg0, void *arg1)
{
    int enabled = OSDisableInterrupts();

    *(u32 *)((char *)arg0 + 0x96) = *(u32 *)((char *)arg1 + 0);
    *(u32 *)((char *)arg0 + 0x9A) = *(u32 *)((char *)arg1 + 4);
    *(u32 *)((char *)arg0 + 0x9E) = *(u32 *)((char *)arg1 + 8);
    *(u32 *)((char *)arg0 + 0xA2) = *(u32 *)((char *)arg1 + 12);

    switch ((int)*(u16 *)((char *)arg1 + 2)) {
    case 0:
        break;
    case 10:
        *(u32 *)((char *)arg0 + 0xA6) = 0;
        *(u32 *)((char *)arg0 + 0xAA) = 0;
        *(u32 *)((char *)arg0 + 0xAE) = 0;
        *(u32 *)((char *)arg0 + 0xB2) = 0;
        *(u32 *)((char *)arg0 + 0xB6) = 0;
        *(u32 *)((char *)arg0 + 0xBA) = 0;
        *(u32 *)((char *)arg0 + 0xBE) = 0;
        *(u32 *)((char *)arg0 + 0xC2) = 0;
        *(u32 *)((char *)arg0 + 0xC6) = 0x08000000;
        *(u32 *)((char *)arg0 + 0xCA) = 0;
        break;
    case 25:
        *(u32 *)((char *)arg0 + 0xA6) = 0;
        *(u32 *)((char *)arg0 + 0xAA) = 0;
        *(u32 *)((char *)arg0 + 0xAE) = 0;
        *(u32 *)((char *)arg0 + 0xB2) = 0;
        *(u32 *)((char *)arg0 + 0xB6) = 0;
        *(u32 *)((char *)arg0 + 0xBA) = 0;
        *(u32 *)((char *)arg0 + 0xBE) = 0;
        *(u32 *)((char *)arg0 + 0xC2) = 0;
        *(u32 *)((char *)arg0 + 0xC6) = 0x01000000;
        *(u32 *)((char *)arg0 + 0xCA) = 0;
        break;
    }

    *(u32 *)((char *)arg0 + 0x1C) =
        (*(u32 *)((char *)arg0 + 0x1C) & 0xFFFF87FF) | 0x8400;

    OSRestoreInterrupts(enabled);
}
