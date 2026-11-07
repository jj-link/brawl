#pragma force_active on
extern char lbl_80486460[];
extern void fn_80280CEC(void *, int);

typedef struct Ref {
    char pad[4];
    unsigned short active;
    short count;
} Ref;

typedef struct Obj {
    char *vtable;
    short pad;
    short flag;
    Ref *ref;
    char data[1];
} Obj;

Obj *fn_80280DCC(Obj *self, Ref *ref, int arg)
{
    self->flag = 1;
    self->vtable = lbl_80486460;
    self->ref = ref;
    fn_80280CEC(self->data, arg);
    if (self->ref->active != 0)
        self->ref->count++;
    return self;
}