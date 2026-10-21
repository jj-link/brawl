#pragma force_active on

struct Manager {
    virtual short add(void*);
};

extern "C" {
void* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_25F60[];
extern char lbl_27_data_7D998[];
extern char lbl_27_data_7DA30[];
extern char lbl_27_data_7DB28[];
void fn_27_EF1D4(void*);
void* fn_27_84218(void*, int);
void __construct_array(void*, void (*)(void*), void* (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Work {
    void* vtable;
    char flag;
    char pad[3];
    void* vtable2;
    void* vtable3;
    void* vtable4;
    void* vtable5;
    unsigned flags;
    char array[36];
    char end;
};

struct Object {
    void* vtable;
    short manager;
    short event;
    Work* work;
    Work inner;
};

extern "C" Object* fn_27_2EA26C(Object* self, short manager, short event) {
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
    self->vtable = lbl_27_data_7D998;
    work->flag = 0;
    work->vtable = lbl_27_data_7DA30;
    work->vtable2 = lbl_27_data_7DA30 + 0x34;
    work->vtable3 = lbl_27_data_7DA30 + 0x40;
    work->vtable4 = lbl_27_data_7DB28;
    work->vtable5 = lbl_27_data_7DB28 + 0x48;
    work->flags &= 0x003FFFFF;
    __construct_array(work->array, fn_27_EF1D4, fn_27_84218, 12, 3);
    work->end = 0;
    return self;
}
