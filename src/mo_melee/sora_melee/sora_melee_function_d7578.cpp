#pragma force_active on

extern "C" {
extern char lbl_27_data_25F88[];
extern char lbl_27_data_225B0[];
extern char lbl_27_data_226A8[];
extern char lbl_27_data_18DE0[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF1BC(void*);
void fn_27_845D8(void*, int);
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
    unsigned char entries[0x24];
    unsigned char last;
};

struct Object {
    void* vtable;
    short manager;
    short id;
    Work* ptr;
    Work work;
};

extern "C" Object* fn_27_D7578(Object* self, short manager, short id) {
    self->manager = manager;
    self->vtable = lbl_27_data_25F88;
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
    self->vtable = lbl_27_data_18DE0;
    work->state = 0;
    work->vtable = lbl_27_data_225B0;
    work->base1 = lbl_27_data_225B0 + 0x34;
    work->base2 = lbl_27_data_225B0 + 0x40;
    work->base3 = lbl_27_data_226A8;
    work->base4 = lbl_27_data_226A8 + 0x48;
    work->flags &= 0x3FFFFF;
    __construct_array(work->entries, fn_27_EF1BC, fn_27_845D8, 0xC, 3);
    work->last = 0;

    return self;
}
