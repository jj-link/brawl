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
extern char lbl_27_data_68270[];
extern char lbl_27_data_68300[];
extern char lbl_27_data_683F0[];
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
    char entries[0x168];
    unsigned char end;
};

struct Object {
    void* vt;
    s16 manager;
    s16 id;
    Work* work;
    Work data;
};

extern "C" Object* fn_27_290B9C(Object* self, s16 manager, s16 id) {
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
    self->vt = lbl_27_data_68270;
    work->active = 0;
    work->vt = lbl_27_data_68300;
    work->a = lbl_27_data_68300 + 0x34;
    work->b = lbl_27_data_68300 + 0x40;
    work->c = lbl_27_data_683F0;
    work->d = lbl_27_data_683F0 + 0x48;
    work->flags &= 0x1FFF;
    __construct_array(work->entries, fn_27_EF12C, fn_27_84458, 0xC, 0x1E);
    work->end = 0;
    return self;
}
