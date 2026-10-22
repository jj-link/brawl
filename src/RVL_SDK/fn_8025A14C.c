#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 type;
    u8 pad1[0x21];
    u16 id;
    u8 pad24[0x3F0];
    void (*callback)(u16);
} Object;

extern void fn_80231A14(u32, const char *, u32, u16);
extern void fn_8024AA7C(u16);
extern void fn_8025AFE8(Object *);
extern u8 lbl_8052D9C0[];
extern char lbl_80485110[];

void fn_8025A14C(Object *arg0) {
    if (lbl_8052D9C0[0x4630] >= 4U) {
        fn_80231A14(0xA0003, lbl_80485110, arg0->type, arg0->id);
    }
    fn_8024AA7C(arg0->id);
    if (arg0->callback != 0) {
        arg0->callback(0xFFF1);
    }
    fn_8025AFE8(arg0);
}
