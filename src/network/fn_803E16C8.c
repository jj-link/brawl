#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    s32 pad[7];
    s32 state;
    s32 pad2[5];
    s32 max_count;
    s32 count;
    s32 pad3[0x7DC];
    u16 flags;
    u16 pad4;
};

extern s32 fn_803DA454(void *, s32, void **, s32 *);
extern s32 fn_803DF760(void *, void *, s32);
extern void fn_803DA55C(void *, void *);
extern s32 fn_803E224C(void *);
extern s32 fn_803E2A70(void *, u16, s32 *, u32);
extern s32 fn_803E2FB0(void *, s32, s32 *);
extern s32 fn_803E3490(void *, s32, s32 *);

s32 fn_803E16C8(struct Obj *arg0, s32 *arg1) {
    s32 sp10;
    s32 spC;
    void *sp8;
    u32 counter;
    s32 var;
    s32 state;
    u32 helperArg;

    if (arg0->flags & 4) {
        s32 cached = arg0->count;
        if ((u32)cached + 0x10000 != 0xFFFF) {
            *arg1 = cached;
            return 0;
        }
    }

    *arg1 = 0;
    counter = 2;
    var = fn_803DA454(arg0, -1, &sp8, &spC);
    if (var != 0) {
        return var;
    }

    var = fn_803DF760(arg0, sp8, 2);
    if (var != 0) {
        fn_803DA55C(arg0, sp8);
        return var;
    }

    *(u16 *)((u8 *)sp8 + 2) = 0;

    while (counter >= 2 && counter < (u32)arg0->max_count + 2) {
        state = arg0->state;
        helperArg = (u32)sp8;
        switch (state) {
        case 0:
            var = fn_803E2A70(arg0, (u16)counter, &sp10, helperArg);
            break;
        case 1:
            var = fn_803E2FB0(arg0, counter, &sp10);
            break;
        case 2:
            var = fn_803E3490(arg0, counter, &sp10);
            break;
        default:
            var = 0xF;
            break;
        }

        if (var != 0) {
            fn_803DA55C(arg0, sp8);
            return var;
        }

        if (sp10 == 0) {
            (*arg1)++;
        }

        counter++;
    }

    fn_803DA55C(arg0, sp8);
    arg0->flags |= 4;
    arg0->count = *arg1;

    if (arg0->state == 2 && (arg0->flags & 2) &&
        fn_803E224C(arg0) != 0) {
        arg0->count = -1;
        arg0->flags = (u16)((u32)arg0->flags & ~4U);
    }

    return 0;
}
