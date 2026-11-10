#include <types.h>
#include <so/so_array.h>

#pragma force_active on

class First {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual short slot7();
};

class Object_vptr_0 {
public:
    virtual void slot0();
};

struct Holder {
    char pad[8];
    First first;
};

struct Modules {
    char pad[4];
    Object_vptr_0* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Flags {
    u32 hi : 4;
    u32 m : 2;
    u32 b : 1;
    u32 lo : 25;
};

struct Object {
    char pad[4];
    void* vtable;
    void* calc;
    Flags flags;
    char array[0x30];
    void* vtable2;
    int zero;
    int arg;
    int flag;
    int pad50;
    char data[1];
};

extern "C" {
extern char lbl_27_data_20248[];
extern char lbl_27_data_2490[];
extern char lbl_27_data_11740[];
extern char lbl_27_data_12380[];

extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_7580[];
extern char lbl_27_bss_7574[];
extern char lbl_27_bss_DBC[];
extern char lbl_27_bss_D7C[];
extern char lbl_27_bss_9BC[];

void* fn_27_137B4(void*);
void fn_27_137EC(void*, int);
void fn_27_82794(void*, short);
void fn_27_82A14(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*,
                 int, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794,
                                 lbl_27_bss_7580);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_7574);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

extern "C" Object* fn_27_2F5640(Object* self, Access* access, int arg) {
    self->calc = lbl_27_data_20248 + 0x48;
    self->vtable = lbl_27_data_20248;
    self->flags.hi = 0;
    self->flags.m = 1;
    self->flags.b = 0;

    __construct_array(self->array, (void (*)(void*))fn_27_137B4,
                      (void (*)(void*))fn_27_137EC, 0x2C, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&self->calc, 1, 1);

    self->zero = 0;
    self->vtable2 = lbl_27_data_2490;
    self->arg = arg;
    self->flag = 8;
    if (arg == 0) {
        self->flag = 0;
    }

    void* g1 = global1();
    void* g2 = global2();
    char* calc = (char*)self + 4;

    fn_27_13844(self->data, access, (char*)self + 0x40, lbl_27_bss_D7C,
                g1, calc, lbl_27_bss_9BC, g2,
                access->modules->holder->first.slot7(), 0, lbl_27_bss_DBC);

    access->modules->other->slot0();
    return (Object*)((char*)self + (calc - ((char*)self + 4)));
}