#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, int);
void fn_27_EF144(void*);
void fn_27_844D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned int, unsigned int);

extern char lbl_27_data_260C8[];
extern char lbl_27_data_330B0[];
extern char lbl_27_data_407C8[];
extern char lbl_27_data_408B8[];
}

struct Manager {
    virtual short add(void*);
};

struct Sub {
    void* vtable;
    unsigned char active;
    char pad[3];
    void* v8;
    void* vC;
    void* v10;
    void* v14;
    unsigned int flags;
    char items[120];
    unsigned char end;
};

struct Object {
    void* vtable;
    short manager;
    short event;
    Sub* list;
    Sub sub;
};

extern "C" Object* fn_27_1AA6A8(Object* self, short manager, short event) {
    self->manager = manager;
    self->vtable = lbl_27_data_260C8;
    self->event = event;

    if (manager != -1) {
        short id = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager))->add(self);
        if (id > -1) {
            self->event = id;
        }
    }

    Sub* sub = &self->sub;
    self->list = sub;
    self->vtable = lbl_27_data_330B0;
    sub->active = 0;
    sub->vtable = lbl_27_data_407C8;
    sub->v8 = lbl_27_data_407C8 + 0x34;
    sub->vC = lbl_27_data_407C8 + 0x40;
    sub->v10 = lbl_27_data_408B8;
    sub->v14 = lbl_27_data_408B8 + 0x48;
    sub->flags &= 0xFFFF;
    __construct_array(sub->items, fn_27_EF144, fn_27_844D8, 12, 10);
    sub->end = 0;
    return self;
}
