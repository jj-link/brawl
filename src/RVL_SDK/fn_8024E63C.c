#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Object {
    u8 active;
    u8 pad01[3];
    u32 state;
    void *head;
    u8 pad0C[0x1E];
    u8 sub[0xE];
    u16 amount;
    u8 pad3A[0xA];
    void *list;
    u8 pad48[8];
    void *resource;
    void (*callback)(int);
} Object;

typedef struct Global {
    u8 pad00[4];
    u16 amount;
    u8 pad06[0x7B2];
    u16 count;
    u8 pad7BA[0x2E];
} Global;

extern Global lbl_8052CDC0;

extern void fn_80232020(void *);
extern void fn_8022F0E0(void *);
extern void fn_8023ED38(void *);
extern void fn_8024FA74(void *);
extern void fn_802382B4(void *);
extern void *fn_8022F77C(void *);
extern void fn_8024CE60(void);

void fn_8024E63C(Object *self)
{
    void (*callback)(int);
    void *head;

    self->active = 0;
    fn_80232020((u8 *)self + 0x10);

    if (self->resource != 0) {
        fn_8022F0E0(self->resource);
        self->resource = 0;
    }

    fn_8023ED38(self->sub);

    head = self->head;
    while (head != 0) {
        fn_8024FA74(head);
        head = self->head;
    }

    if (self->state - 4 <= 1U) {
        fn_802382B4((u8 *)self + 0x2A);
    }

    while (self->list != 0) {
        fn_8022F0E0(fn_8022F77C(&self->list));
    }

    if (lbl_8052CDC0.count >= 1U) {
        lbl_8052CDC0.count--;
    }

    lbl_8052CDC0.amount += self->amount;
    fn_8024CE60();

    callback = self->callback;
    if (callback != 0) {
        self->callback = 0;
        callback(1);
    }
}
