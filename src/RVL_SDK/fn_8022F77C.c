#pragma force_active on
#define NULL ((void *)0)

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void fn_8023052C(void);
extern int fn_80230508(void);

typedef struct Pool {
    void *head;
    u32 unk4;
    u16 count;
} Pool;

void *fn_8022F77C(Pool *arg0) {
    void *node;
    int next;

    fn_8023052C();
    if (arg0 == NULL || arg0->count == 0) {
        fn_80230508();
        return NULL;
    }

    node = arg0->head;
    next = *(int *)((u8 *)node - 8);
    if (next != 0) {
        arg0->head = (void *)(next + 8);
    } else {
        arg0->head = NULL;
        arg0->unk4 = 0;
    }

    arg0->count--;
    *(void **)((u8 *)node - 8) = NULL;
    *(u8 *)((u8 *)node - 2) = 1;
    fn_80230508();
    return node;
}
