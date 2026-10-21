#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);

extern char lbl_27_data_25F10[];
extern char lbl_27_data_188F0[];
extern char lbl_27_data_211B0[];
extern char lbl_27_data_212A8[];

void fn_27_EF21C(void*);
void* fn_27_84318(void*, int);
void __construct_array(void*, void (*)(void*), void* (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual short addUnit(void*);
};

struct Inner {
    void* vtable;
    unsigned char byte;
    char pad[3];
    void* v14;
    void* v18;
    void* v1C;
    void* v20;
    unsigned int flags;
    char array[12];
    unsigned char end;
};

struct Object {
    void* vtable;
    short id;
    short index;
    Inner* ptr;
    Inner inner;
};

extern "C" Object* fn_27_D8058(Object* self, short id, short index) {
    self->id = id;
    self->vtable = lbl_27_data_25F10;
    self->index = index;

    if (id != -1) {
        short result = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id))->addUnit(self);
        if (result > -1) {
            self->index = result;
        }
    }

    Inner* inner = &self->inner;
    self->ptr = inner;
    self->vtable = lbl_27_data_188F0;

    inner->byte = 0;
    inner->vtable = lbl_27_data_211B0;
    inner->v14 = lbl_27_data_211B0 + 0x34;
    inner->v18 = lbl_27_data_211B0 + 0x40;
    inner->v1C = lbl_27_data_212A8;
    inner->v20 = lbl_27_data_212A8 + 0x48;
    inner->flags &= 0x01FFFFFF;

    __construct_array(inner->array, fn_27_EF21C, fn_27_84318, 12, 1);
    inner->end = 0;

    return self;
}
