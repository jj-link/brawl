#include <so/so_array_vector_calculator.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual short slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*);
};

struct Holder {
    char pad[8];
    Object_vptr_0 first;
};

struct Modules {
    char pad[4];
    Object_vptr_0* other;
    char pad2[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Bits {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 1;
    unsigned int rest : 22;
};

struct Object {
    Object_vptr_0 base;
    void* calc;
    unsigned int flags;
    char elements[0x14];

    void* vt2;
    void* calc2;
    unsigned int flags2;
    char elements2[0x40];

    void* vt3;
    void* owner;
    int zero;
    int minus1;
    int minus2;
    int zero2;
    int pad84;

    void* vt4;
    void* calc4;
    Bits bits;
    char elements4[0x58];
    int padEC;

    void* vt5;
    int zero3;
    int arg;
    int flag;
    int pad100;
    char data[1];
};

extern "C" {
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_3A6F8[];
extern char lbl_27_data_2490[];
extern char lbl_27_data_11740;
extern char lbl_27_data_12380;

extern char lbl_27_bss_8B90[];
extern char lbl_27_bss_8B84[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];
extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_5204;

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_137B4(void*);
void fn_27_137EC(void*, short);
void fn_27_82794(void*, short);
void fn_27_82A14(void*, short);

void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*,
                 void*, int, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = &lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794,
                                 lbl_27_bss_8B90);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = &lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_8B84);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

inline void initializeArray(Object* self) {
    char tmp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(tmp, i == 0 ? &self->vt2 : 0);
        self->base.slot10(tmp);
        fn_27_AB18C(tmp, -1);
    }
}

inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Object* fn_27_3B22D0(Object* self, Access* access, int arg) {
    *(void**)&self->base = lbl_27_data_1D4E8;
    self->calc = lbl_27_data_1D4E8 + 0x48;
    self->flags &= 0x1ffffff;
    __construct_array(self->elements, fn_27_AB128,
                      (void (*)(void*))fn_27_AB18C, 0x14, 1);

    self->vt2 = lbl_27_data_1A3D8;
    self->calc2 = lbl_27_data_1A3D8 + 0x48;
    self->flags2 &= 0x7ffff;
    __construct_array(self->elements2, fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 4);

    self->owner = self;
    self->vt3 = lbl_27_data_8E80;
    self->zero = 0;
    self->zero2 = 0;
    self->minus1 = -1;
    self->minus2 = -1;

    initializeArray(self);

    self->vt4 = lbl_27_data_3A6F8;
    self->calc4 = lbl_27_data_3A6F8 + 0x48;
    self->bits.a = 0;
    self->bits.b = 2;
    self->bits.c = 0;
    __construct_array(self->elements4, fn_27_137B4,
                      (void (*)(void*))fn_27_137EC, 0x2c, 2);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&self->calc4, 2, 2);

    self->zero3 = 0;
    self->vt5 = lbl_27_data_2490;
    self->arg = arg;
    self->flag = 2;
    if (arg == 0) {
        self->flag = 0;
    }

    void* g = global1();
    global3();

    Modules* modules = access->modules;
    char* vector = part((char*)self, 0x88);
    char* transition = part((char*)self, 0x6c);
    short value = modules->holder->first.slot7();
    fn_27_13844(self->data, access, &self->vt5, transition, g,
                vector, lbl_27_bss_9BC, &lbl_27_bss_5204, value, 0,
                lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}
