#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Event {
    u32 value;
    u16 id;
    u8 pad6[0xE];
    u8 flags;
    u8 flags15;
} Event;
typedef struct Owner {
    u8 pad0[4];
    int field4;
    u8 pad8[0x7C8];
    u16 flags;
} Owner;
typedef struct Context Context;
struct Context {
    u8 pad0[0x10];
    int field10;
    u8 pad14[0x2C];
    int field40;
    u8 pad44[8];
    int field4C;
    u8 pad50[0x6A0];
    u32 field6F0;
    u8 pad6F4[0x134];
    int field828;
    int field82C;
    u32 value;
    u16 id;
    u16 pad836;
    void (*callback)(Context *, int, Event *, void *);
    void *user;
};
extern void fn_80387E4C(Context *, Event *, int, int, int);
extern void fn_803884B8(Context *, Event *);
extern void fn_8038AE04(void *);
extern int fn_8035A590(int);
extern void fn_80387DD0(Context *, u32);

void fn_803891B8(Owner *owner, u32 type, Event *event, Context *context)
{
    u8 flags;
    int mode;
    switch (type) {
    case 0:
        context->callback(context, 0, event, context->user);
        flags = event->flags;
        if ((!(flags & 3) || !(flags & 0x40)) && !(flags & 0x2C) && context->field82C == 0) {
            if (event->flags15 & 1) {
                if (context->field4C == 0 || context->field40 == 0)
                    mode = 1;
                else
                    mode = 0;
            } else {
                mode = 2;
            }
            if (owner->flags & 0x80)
                fn_80387E4C(context, event, 0, mode, 1);
            else
                fn_80387E4C(context, event, 0, mode, 0);
        }
        break;
    case 1:
        if (!(event->flags & 0x43))
            context->callback(context, 2, event, context->user);
        else
            context->callback(context, 1, event, context->user);
        break;
    case 2:
        if (event->flags & 0x2C)
            fn_803884B8(context, event);
        context->callback(context, 3, event, context->user);
        break;
    case 3:
        if (context->field828 != 0)
            fn_8038AE04(owner);
        if (fn_8035A590(owner->field4) == 0 || context->field10 == 0)
            context->callback(context, 4, 0, context->user);
        break;
    case 5:
        context->callback(context, 5, 0, context->user);
        break;
    case 6:
        fn_80387DD0(context, context->field6F0);
        break;
    case 4:
    case 7:
        break;
    }
    if (event && event->value == context->value && event->id == context->id)
        context->value = 0;
}
