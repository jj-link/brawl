#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef void (*Handler)(int, ...);

struct Handlers {
    unsigned char pad[0x3C];
    Handler callback;
};

extern struct Handlers lbl_804DD190;
extern void fn_801D8A44(int, void *, u32, u32);

void fn_801DE3D4(int interrupt, void *context)
{
    u32 status = *(u16 *)0xCC00401E;
    u32 address = ((*(u16 *)0xCC004024 & 0x3FF) << 16)
                | *(u16 *)0xCC004022;

    *(u16 *)0xCC004020 = 0;

    if (lbl_804DD190.callback)
        lbl_804DD190.callback(15, context, status, address);
    else
        fn_801D8A44(15, context, status, address);
}
