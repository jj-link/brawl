#pragma force_active on
typedef struct Callback {
    int a;
    int b;
} Callback;
typedef struct Object {
    char pad[0x1a8];
    Callback cb;
    char pad2[0x284];
    int value;
    int flag;
} Object;
typedef struct Event {
    int arg;
    int value;
    Object *obj;
    int type;
} Event;
extern void *fn_8035DFE8(int);
extern int fn_8036ABB0(Object **, Callback, Event *, int, int);
void fn_8036AAF0(Object **ctx, int arg, int type) {
    Object *obj = *ctx;
    Callback cb;
    Event *event;
    if (type == 1)
        obj->flag = 1;
    cb = obj->cb;
    if (cb.a != 0) {
        event = fn_8035DFE8(0x10);
        if (event != 0) {
            event->arg = arg;
            event->type = type;
            event->value = obj->value;
            event->obj = obj;
        }
        fn_8036ABB0(ctx, cb, event, 0, 1);
    }
}