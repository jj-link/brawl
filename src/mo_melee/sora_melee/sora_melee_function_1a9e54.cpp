#pragma force_active on

typedef short s16;
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_26028[];
extern char lbl_27_data_331D0[];
extern char lbl_27_data_40BD8[];
extern char lbl_27_data_40CC8[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF12C(void*);
void fn_27_84458(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct EventManager {
    virtual s16 add(void*);
};

struct Inner {
    void* vt;
    unsigned char active;
    unsigned char pad[3];
    void* vt1;
    void* vt2;
    void* vt3;
    void* vt4;
    u32 flags;
    unsigned char array[0xF0];
    unsigned char end;

    void init() {
        active = 0;
        vt = lbl_27_data_40BD8;
        vt1 = lbl_27_data_40BD8 + 0x34;
        vt2 = lbl_27_data_40BD8 + 0x40;
        vt3 = lbl_27_data_40CC8;
        vt4 = lbl_27_data_40CC8 + 0x48;
        flags &= 0x1FFF;
        __construct_array(array, fn_27_EF12C, fn_27_84458, 0xC, 0x14);
        end = 0;
    }
};

struct Object {
    void* vt;
    s16 id;
    s16 index;
    Inner* ptr;
    Inner inner;
};

extern "C" Object* fn_27_1A9E54(Object* self, s16 id, s16 index) {
    self->id = id;
    self->vt = lbl_27_data_26028;
    self->index = index;

    if (id != -1) {
        EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id);
        s16 result = mgr->add(self);
        if (result > -1)
            self->index = result;
    }

    self->ptr = &self->inner;
    self->vt = lbl_27_data_331D0;
    ((Inner*)((char*)self + 0xC))->init();
    return self;
}
