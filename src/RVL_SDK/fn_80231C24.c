#pragma force_active on
#define NULL ((void *)0)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;

typedef struct Node {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s32 unkC;
    void *unk10;
    u16 unk14;
} Node;

extern u8 lbl_805297D0[];
extern s32 lbl_8059EDEC;
extern u8 lbl_8059EDE8;
extern u32 lbl_805A0D28;
extern u32 lbl_805A0D2C;

extern u64 OSGetTime(void);
extern void fn_8023052C(u32);
extern void fn_80230508(void);
extern u16 *fn_8022F450(s32);
extern void fn_80230078(void *, s32);
extern void fn_802301F0(void *, void *);
extern void fn_8022F0E0(void *);
extern void fn_8023EF84(void *);
extern void fn_8024D418(void *);
extern void fn_8024D64C(void *);
extern void fn_80242350(void *);
extern void fn_80242908(void *);
extern void fn_802323C0(void);
extern void fn_802324AC(void);
extern void fn_8023D824(void);
extern void fn_8023BDC8(void);
extern void fn_8023A6B0(void *);
extern void fn_802391A4(void *);
extern void fn_8024E3EC(void *);
extern void fn_8025A14C(void *);
extern void fn_802565A8(void *);
extern void fn_80243374(void);
extern void fn_80248848(void *);

static inline void invoke(void (*fn)(void *), void *p, int *found)
{
    if (fn != NULL) {
        fn(p);
        *found = 1;
    }
}

static inline int dispatch(u32 key, void *p, u8 *i)
{
    int found = 0;
    while (found == 0 && *i < 6) {
        u8 *e = lbl_805297D0 + *i * 8;
        void (*fn)(void *) = *(void (**)(void *))(e + 0x14);
        if (fn != NULL && key == *(u16 *)(e + 0x10))
            invoke(fn, p, &found);
        (*i)++;
    }
    return found;
}
static inline void dispatch2(Node *node, u8 *i)
{
    int found = 0;
    while (found == 0 && *i < 2) {
        u32 *e = (u32 *)(lbl_805297D0 + *i * 8);
        void (*fn)(void *) = (void (*)(void *))e[1];
        if (fn != NULL && e[0] == (u32)node) {
            fn(node);
            found = 1;
        }
        (*i)++;
    }
}
#define node ((Node *)key)
void fn_80231C24(void)
{
    u16 *p;
    u32 key;
    u32 t;
    u16 flags;
    s32 done;
    s32 found;
    u8 i;

    done = 0;
    OSGetTime();
    t = lbl_805A0D28;
    lbl_805A0D28 = t + 1;
    fn_8023052C(t);

    if (lbl_8059EDEC != 0) {
        lbl_8059EDEC = 0;
        lbl_8059EDE8 = 1;
    } else {
        lbl_8059EDE8++;
        fn_80230508();
        return;
    }
    fn_80230508();

    flags = 5;
    if (lbl_805A0D28 > lbl_805A0D2C + 0x1F4) {
        lbl_805A0D2C = lbl_805A0D28;
        flags |= 0x30;
    }

    while (done == 0) {
        done = 1;
        if (flags & 1) {
            while ((p = fn_8022F450(0)) != NULL) {
                done = 0;
                key = *p & 0xFF00;
                switch (key) {
                case 0x1100:
                    fn_8024D64C(p);
                    break;
                case 0x1900:
                    fn_8024D418(p);
                    break;
                case 0x1200:
                    fn_8023EF84(p);
                    break;
                case 0x1000:
                    fn_80242350(p);
                    fn_8022F0E0(p);
                    break;
                case 0x1600:
                    fn_80242908(p);
                    break;
                default:
                    i = 0;
                    if (!dispatch(key, p, &i)) {
                        fn_8022F0E0(p);
                    }
                    break;
                }
            }
        }

        if (flags & 0x10) {
            fn_80230078(lbl_805297D0 + 0x40, 1);
            flags &= ~0x10;
            while ((key = *(u32 *)(lbl_805297D0 + 0x40)) != 0 && node->unkC == 0) {
                done = 0;
                fn_802301F0(lbl_805297D0 + 0x40, node);
                switch (node->unk14) {
                case 1:
                    fn_8023A6B0(node);
                    break;
                case 9:
                    fn_802391A4(node);
                    break;
                case 2:
                case 3:
                case 4:
                    fn_8024E3EC(node);
                    break;
                case 5:
                    fn_8025A14C(node->unk10);
                    break;
                case 0xA:
                    fn_8023D824();
                    break;
                case 8:
                    fn_8023BDC8();
                    break;
                case 0xB:
                case 0xC:
                    fn_802565A8(node);
                    break;
                case 0x3C:
                    fn_80243374();
                    break;
                case 0x42:
                    fn_80248848(node);
                    break;
                case 0x16:
                    ((void (*)(void *))node->unk10)(node);
                    break;
                default:
                    i = 0;
                    dispatch2(node, &i);
                    break;
                }
            }
        }

        if (flags & 4) {
            while (fn_8022F450(2) != NULL) {
                done = 0;
                fn_802323C0();
            }
        }

        if (flags & 0x20) {
            flags &= ~0x20;
            fn_802324AC();
        }

        if (flags & 0x8000) {
            break;
        }
    }
    lbl_8059EDEC = 1;
}
