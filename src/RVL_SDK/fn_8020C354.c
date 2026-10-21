#pragma force_active on
typedef unsigned char u8;

typedef struct Object {
    int handle;
    u8 pad04[0x84];
    u8 kind;
    u8 pad89;
    u8 state;
} Object;

typedef struct Request {
    int unk00;
    void *callback;
    Object *object;
    u8 pad0C[0x70];
    int command;
    u8 pad80[0x38];
    int flag;
} Request;

extern int fn_8020CAD4(void);
extern void fn_8020C614(int, void *);
extern void fn_8020C450(int, void *);
extern int fn_802152E4(int, void (*)(int, void *), Request *);
extern int fn_8020CAEC(int);

int fn_8020C354(Object *object, void *callback, Request *request, int flag)
{
    int result;

    if (!fn_8020CAD4())
        return -128;

    if (!((object->state == 3 && flag == 0) ||
          (object->state == 5 && flag != 0)))
        return -8;

    request->flag = flag;

    if (object->kind == 1) {
        request->object = object;
        request->callback = callback;
        result = fn_802152E4(object->handle, fn_8020C614, request);
    } else if (object->kind == 2 || object->kind == 3) {
        request->object = object;
        request->callback = callback;
        request->command = 10;
        result = fn_802152E4(object->handle, fn_8020C450, request);
    } else {
        result = -101;
    }

    return fn_8020CAEC(result);
}
