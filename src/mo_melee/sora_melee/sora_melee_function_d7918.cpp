#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
extern char lbl_27_data_25F60[];
extern char lbl_27_data_18C58[];
extern char lbl_27_data_21FB8[];
extern char lbl_27_data_220B0[];
void fn_27_EF1D4(void*);
void* fn_27_84218(void*, int);
void __construct_array(void*, void (*)(void*), void* (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual short add(void*);
};

extern "C" Manager* getManager__13soEventSystemFl(void*, long);

struct Work {
    void* vtable;
    char flag;
    char pad[3];
    void* vtable2;
    void* vtable3;
    void* vtable4;
    void* vtable5;
    unsigned flags;
    char array[12];
    char end;
};

struct Object {
    void* vtable;
    short manager;
    short event;
    Work* work;
    Work inner;
};

extern "C" Object* fn_27_D7918(Object* self, short manager, short event) {
    self->manager = manager;
    self->vtable = lbl_27_data_25F60;
    self->event = event;

    if (manager != -1) {
        short id = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager)->add(self);
        if (id > -1)
            self->event = id;
    }

    Work* work = &self->inner;
    self->work = work;
    self->vtable = lbl_27_data_18C58;
    work->flag = 0;
    work->vtable = lbl_27_data_21FB8;
    work->vtable2 = lbl_27_data_21FB8 + 0x34;
    work->vtable3 = lbl_27_data_21FB8 + 0x40;
    work->vtable4 = lbl_27_data_220B0;
    work->vtable5 = lbl_27_data_220B0 + 0x48;
    work->flags &= 0x01FFFFFF;
    __construct_array(work->array, fn_27_EF1D4, fn_27_84218, 12, 1);
    work->end = 0;
    return self;
}
