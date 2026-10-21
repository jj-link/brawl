#pragma force_active on

typedef short s16;
typedef unsigned int u32;

extern "C" {
char lbl_27_data_26028[];
char lbl_27_data_19478[];
char lbl_27_data_240A0[];
char lbl_27_data_24190[];

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
    unsigned char array[0x108];
    unsigned char end;

    void init() {
        active = 0;
        vt = lbl_27_data_240A0;
        vt1 = lbl_27_data_240A0 + 0x34;
        vt2 = lbl_27_data_240A0 + 0x40;
        vt3 = lbl_27_data_24190;
        vt4 = lbl_27_data_24190 + 0x48;
        flags &= 0x1fff;
        __construct_array(array, fn_27_EF12C, fn_27_84458, 0xc, 0x16);
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

extern "C" Object* fn_27_D66F8(Object* self, s16 id, s16 index) {
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
    self->vt = lbl_27_data_19478;
    ((Inner*)((char*)self + 0xC))->init();
    return self;
}
