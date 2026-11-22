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

class OtherObj {
public:
    virtual void slot0();
};

class VptrSelf {
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

struct Holder {
    char pad[8];
    First first;
};

struct Modules {
    char pad0[4];
    OtherObj* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    void* vtbl;
    void* unk4;
    unsigned int unk8;
    char arr0[0x14];
    void* unk20;
    void* unk24;
    unsigned int unk28;
    char arr1[0x40];
    void* unk6C;
    Self* unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    char pad84[4];
    void* unk88;
    int unk8C;
    int unk90;
    int unk94;
    char pad98[4];
    char unk9C[0x10];
};

extern "C" {
extern char lbl_27_data_2490[];
extern char lbl_27_data_11740[];
extern char lbl_27_data_11600[];
extern char lbl_27_data_12380[];
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[];

extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_73A4;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_73A8;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_7D3C[];
extern char lbl_27_bss_7D30[];
extern char lbl_27_bss_7D24[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void* fn_27_AB510(void*, int);
void fn_27_AB15C(void*, void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*,
                 short, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794,
                                 lbl_27_bss_7D3C);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754,
                                 lbl_27_bss_7D30);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_7D24);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

static inline void initializeArray(Self* self) {
    char entry[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(entry, i == 0 ? &self->unk20 : 0);
        ((VptrSelf*)self)->slot10(entry);
        fn_27_AB18C(entry, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Self* fn_27_32B7F0(Self* self, Access* access, int arg) {
    self->vtbl = lbl_27_data_1D4E8;
    self->unk4 = lbl_27_data_1D4E8 + 0x48;
    self->unk8 = self->unk8 & 0x01FFFFFF;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_AB128,
                      (void (*)(void*))fn_27_AB18C, 0x14, 1);
    self->unk20 = lbl_27_data_1A3D8;
    self->unk24 = lbl_27_data_1A3D8 + 0x48;
    self->unk28 = self->unk28 & 0x0007FFFF;
    __construct_array((char*)self + 0x2C, (void (*)(void*))fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 4);
    self->unk70 = self;
    self->unk6C = lbl_27_data_8E80;
    self->unk74 = 0;
    self->unk80 = 0;
    self->unk78 = -1;
    self->unk7C = -1;

    initializeArray(self);

    self->unk8C = 0;
    self->unk88 = lbl_27_data_2490;
    self->unk90 = arg;
    self->unk94 = 4;
    if (arg == 0) {
        self->unk94 = 0;
    }

    void* g1 = global1();
    void* g2 = global2();
    global3();

    Modules* modules = access->modules;
    char* transition = part((char*)self, 0x6c);
    fn_27_13844((char*)self + 0x9C, access, &self->unk88, transition,
                g1, g2, lbl_27_bss_9BC, &lbl_27_bss_5204,
                modules->holder->first.slot7(), 0, lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}
