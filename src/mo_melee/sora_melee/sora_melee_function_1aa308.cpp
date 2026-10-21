#pragma force_active on

typedef short s16;
typedef unsigned int u32;

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF12C(void*);
void fn_27_84458(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);

extern char lbl_27_data_26028[];
extern char lbl_27_data_3E530[];
extern char lbl_27_data_42DF0[];
extern char lbl_27_data_42EE0[];
}

struct Manager {
    virtual s16 add(void*);
};

struct Work {
    void* vt;
    unsigned char active;
    void* a;
    void* b;
    void* c;
    void* d;
    u32 flags;
    char entries[0x18C];
    unsigned char end;
};

struct Object {
    void* vt;
    s16 manager;
    s16 id;
    Work* work;
    Work data;
};

extern "C" Object* fn_27_1AA308(Object* self, s16 manager, s16 id) {
    self->manager = manager;
    self->vt = lbl_27_data_26028;
    self->id = id;

    if (manager != -1) {
        s16 result = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager))->add(self);
        if (result > -1)
            self->id = result;
    }

    Work* work = &self->data;
    self->work = work;
    self->vt = lbl_27_data_3E530;
    work->active = 0;
    work->vt = lbl_27_data_42DF0;
    work->a = lbl_27_data_42DF0 + 0x34;
    work->b = lbl_27_data_42DF0 + 0x40;
    work->c = lbl_27_data_42EE0;
    work->d = lbl_27_data_42EE0 + 0x48;
    work->flags &= 0x3FF;
    __construct_array(work->entries, fn_27_EF12C, fn_27_84458, 0xC, 0x21);
    work->end = 0;
    return self;
}
