#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 id;
    u8 pad1[0x63];
    u8 state;
    u8 pad65[0x23];
    u32 mask;
    void (*cb)(u32, u8);
} Obj;

extern void fn_802319E4(u32, const char *);
extern Obj *fn_80251AD0(void);
extern u32 fn_802515EC(void *);
extern unsigned char lbl_8052D5A8[];
extern char lbl_80484088[];

void fn_80250F90(void) {
    Obj *obj;
    u32 bits;
    u8 flags;
    void (*cb)(u32, u8);

    obj = fn_80251AD0();
    bits = 0;
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_80484088);
    }
    if (obj != 0) {
        flags = obj->state;
        if (!(flags & 2)) {
            flags |= 2;
            obj->state = flags;
            if (flags & 4) {
                bits = obj->mask & 0x200;
            }
        }
        if (flags & 4) {
            bits |= fn_802515EC(obj);
        }
        if (bits != 0) {
            cb = obj->cb;
            if (cb != 0) {
                cb(bits, obj->id);
            }
        }
    }
}
