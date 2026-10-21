#pragma force_active on

extern "C" {
extern char lbl_27_data_44A68[];
extern char lbl_27_data_66040[];
extern char lbl_27_data_660D0[];
extern char lbl_27_data_661C0[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_1BA438(void*);
void* fn_27_84118(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct EventManager {
    virtual short add(void*);
};

struct Sub {
    void* vtable;
    unsigned char active;
    char pad[3];
    void* v14;
    void* v18;
    void* v1c;
    void* v20;
    unsigned int flags;
    char elements[0x6c];
    unsigned char end;
};

struct Object {
    void* vtable;
    short manager;
    short id;
    Sub* sub;
    Sub storage;
};

extern "C" Object* fn_27_2909DC(Object* self, short manager, short id) {
    self->manager = manager;
    self->vtable = lbl_27_data_44A68;
    self->id = id;

    if (manager != -1) {
        short result = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager))->add(self);
        if (result > -1) {
            self->id = result;
        }
    }

    Sub* sub = &self->storage;
    self->sub = sub;
    self->vtable = lbl_27_data_66040;
    sub->active = 0;
    sub->vtable = lbl_27_data_660D0;
    sub->v14 = lbl_27_data_660D0 + 0x34;
    sub->v18 = lbl_27_data_660D0 + 0x40;
    sub->v1c = lbl_27_data_661C0;
    sub->v20 = lbl_27_data_661C0 + 0x48;
    sub->flags &= 0xffff;
    __construct_array(sub->elements, fn_27_1BA438,
                      (void (*)(void*, int))fn_27_84118, 12, 9);
    sub->end = 0;
    return self;
}
