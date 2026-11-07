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
    char pad0[4];
    Object_vptr_0* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[8];
    void* vtable;
    int zero;
    int arg;
    int flag;
    int pad18;
    char data[1];
};

extern "C" {
extern char lbl_27_data_2490[];
extern int lbl_27_data_11740;
extern char lbl_27_data_11600[];
extern char lbl_27_data_12380[];

extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_73A4;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_73A8;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_83A4[];
extern char lbl_27_bss_8398[];
extern char lbl_27_bss_838C[];
extern char lbl_27_bss_D7C[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void* __register_global_object(void*, void*, void*);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*,
                 int, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = &lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794,
                                 lbl_27_bss_83A4);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754,
                                 lbl_27_bss_8398);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_838C);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

extern "C" Object* fn_27_370108(Object* self, Access* access, int arg) {
    self->zero = 0;
    self->vtable = lbl_27_data_2490;
    self->arg = arg;
    self->flag = 3;
    if (arg == 0) {
        self->flag = 0;
    }

    void* g1 = global1();
    void* g2 = global2();
    void* g3 = global3();

    fn_27_13844(self->data, access, &self->vtable, lbl_27_bss_D7C,
                g1, g2, lbl_27_bss_9BC, g3,
                access->modules->holder->first.slot7(), 0, lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}
