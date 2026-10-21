#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Event {
    u32 value;
    u16 id;
} Event;

typedef struct Context Context;

struct Context {
    char padding[0x830];
    u32 value;
    u16 id;
    u16 padding836;
    void (*callback)(Context *, int, Event *, void *);
    void *user;
};

void fn_803893F0(void *unused, int type, Event *event, Context *context)
{
    switch (type) {
    case 1:
        context->callback(context, 2, event, context->user);
        break;
    case 0:
        context->callback(context, 1, event, context->user);
        break;
    case 2:
        context->callback(context, 4, event, context->user);
        break;
    case 3:
        context->callback(context, 6, event, context->user);
        return;
    }

    if (event && event->value == context->value && event->id == context->id)
        context->value = 0;
}
