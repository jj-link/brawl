#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;

struct Manager {
    virtual short attach(Obj*);
};

extern "C" {
void* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(void*, long);
void fn_27_EF18C(void*);
void fn_27_84598(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);

extern char lbl_27_data_25FB0[];
extern char lbl_27_data_32F38[];
extern char lbl_27_data_40208[];
extern char lbl_27_data_40300[];
}

struct Inner {
    void* v0;
    u8 flag;
    u8 pad[3];
    void* v8;
    void* vc;
    void* v10;
    void* v14;
    u32 flags;
    char entries[24];
    u8 end;
};

struct Obj {
    void* vt;
    short id;
    short index;
    Inner* ptr;
    Inner inner;
};

extern "C" Obj* fn_27_1AB068(Obj* self, short id, short index) {
    self->id = id;
    self->vt = lbl_27_data_25FB0;
    self->index = index;

    if (id != -1) {
        short result = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id)->attach(self);
        if (result > -1) {
            self->index = result;
        }
    }

    Inner* inner = &self->inner;
    self->ptr = inner;
    self->vt = lbl_27_data_32F38;
    inner->flag = 0;
    inner->v0 = lbl_27_data_40208;
    inner->v8 = lbl_27_data_40208 + 0x34;
    inner->vc = lbl_27_data_40208 + 0x40;
    inner->v10 = lbl_27_data_40300;
    inner->v14 = lbl_27_data_40300 + 0x48;
    inner->flags &= 0x3FFFFF;
    __construct_array(inner->entries, fn_27_EF18C, fn_27_84598, 12, 2);
    inner->end = 0;

    return self;
}
