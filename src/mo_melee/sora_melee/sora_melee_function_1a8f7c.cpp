#pragma force_active on

extern "C" {
extern char lbl_27_data_25948[];
extern char lbl_27_data_3E4A0[];
extern char lbl_27_data_42BE8[];
extern char lbl_27_data_42CD8[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF0CC(void*);
void fn_27_84198(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual short add(void*);
};

struct Work {
    void* vtable;
    unsigned char state;
    void* base1;
    void* base2;
    void* base3;
    void* base4;
    unsigned int flags;
    unsigned char entries[0x3C];
    unsigned char last;
};

struct Object {
    void* vtable;
    short manager;
    short id;
    Work* ptr;
    Work work;
};

extern "C" Object* fn_27_1A8F7C(Object* self, short manager, short id) {
    self->manager = manager;
    self->vtable = lbl_27_data_25948;
    self->id = id;

    if (manager != -1) {
        Manager* mgr = (Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager);
        short result = mgr->add(self);
        if (result > -1)
            self->id = result;
    }

    Work* work = &self->work;
    self->ptr = work;
    self->vtable = lbl_27_data_3E4A0;
    work->state = 0;
    work->vtable = lbl_27_data_42BE8;
    work->base1 = lbl_27_data_42BE8 + 0x34;
    work->base2 = lbl_27_data_42BE8 + 0x40;
    work->base3 = lbl_27_data_42CD8;
    work->base4 = lbl_27_data_42CD8 + 0x48;
    work->flags &= 0x7FFFF;
    __construct_array(work->entries, fn_27_EF0CC, fn_27_84198, 0xC, 5);
    work->last = 0;

    return self;
}
