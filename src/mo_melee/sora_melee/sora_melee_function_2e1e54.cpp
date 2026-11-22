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

class VirtualSelf {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*);
};

struct Self {
    void* vtbl;
    void* p04;
    unsigned f08;
    char a0c[0x14];
    void* p20;
    void* p24;
    unsigned f28;
    char a2c[0x40];
    void* p6c;
    Self* p70;
    unsigned p74;
    int f78;
    int f7c;
    unsigned p80;
    char a84[4];
    void* p88;
    void* p8c;
    int f90;
    int f94;
    char a98[4];
    char a9c[0x20];
};

struct Holder {
    char pad[8];
    First first;
};

struct Modules {
    char pad0[4];
    Self* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_2490[];
extern char lbl_27_data_11740[];
extern char lbl_27_data_11600[];
extern char lbl_27_data_12380[];

extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_73A4;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_73A8;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_747C[];
extern char lbl_27_bss_7470[];
extern char lbl_27_bss_7464[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void* __register_global_object(void*, void*, void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*,
                 int, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_747C);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754, lbl_27_bss_7470);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_7464);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

static inline void initializeArray(Self* self) {
    char entry[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(entry, i == 0 ? &self->p20 : 0);
        ((VirtualSelf*)self)->slot10(entry);
        fn_27_AB18C(entry, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Self* fn_27_2E1E54(Self* self, Access* access, int arg) {
    self->vtbl = lbl_27_data_1D4E8;
    self->p04 = lbl_27_data_1D4E8 + 0x48;
    self->f08 &= 0x01FFFFFF;
    __construct_array(self->a0c, (void (*)(void*))fn_27_AB128,
                      (void (*)(void*))fn_27_AB18C, 0x14, 1);
    self->p20 = lbl_27_data_1A3D8;
    self->p24 = lbl_27_data_1A3D8 + 0x48;
    self->f28 &= 0x7FFFF;
    __construct_array(self->a2c, (void (*)(void*))fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 4);
    self->p70 = self;
    self->p6c = lbl_27_data_8E80;
    self->p74 = 0;
    self->p80 = 0;
    self->f78 = -1;
    self->f7c = -1;
    initializeArray(self);
    self->p8c = 0;
    self->p88 = lbl_27_data_2490;
    self->f90 = arg;
    self->f94 = 3;
    if (arg == 0) {
        self->f94 = 0;
    }

    void* g1 = global1();
    void* g2 = global2();
    global3();

    Modules* modules = access->modules;
    char* transition = part((char*)self, 0x6c);
    fn_27_13844(self->a9c, access, &self->p88, transition, g1, g2,
                lbl_27_bss_9BC, &lbl_27_bss_5204, modules->holder->first.slot7(), 0,
                lbl_27_bss_DBC);
    ((VirtualSelf*)access->modules->other)->slot0();
    return self;
}