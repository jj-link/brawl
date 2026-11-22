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

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(void*);
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
extern char lbl_27_bss_7744[];
extern char lbl_27_bss_7738[];
extern char lbl_27_bss_772C[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*);
void fn_27_AB15C(void*, void*);
void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*,
                 int, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794,
                                 lbl_27_bss_7744);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754,
                                 lbl_27_bss_7738);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_772C);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

static inline void initializeArray(char* self) {
    char tmp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(tmp, i == 0 ? self + 0x20 : 0);
        ((Self*)self)->v10(tmp);
        fn_27_AB18C(tmp, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" void* fn_27_30922C(char* self, Access* access, int arg) {
    unsigned int f;
    f = *(unsigned int*)(self + 0x08);
    *(void**)(self + 0x00) = lbl_27_data_1D4E8;
    *(void**)(self + 0x04) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(self + 0x08) = f & 0x01FFFFFF;
    __construct_array(self + 0x0c, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);
    f = *(unsigned int*)(self + 0x28);
    *(void**)(self + 0x20) = lbl_27_data_1A3D8;
    *(void**)(self + 0x24) = lbl_27_data_1A3D8 + 0x48;
    *(unsigned int*)(self + 0x28) = f & 0x7FFFF;
    __construct_array(self + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 4);
    *(void**)(self + 0x70) = self;
    *(void**)(self + 0x6c) = lbl_27_data_8E80;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x78) = -1;
    *(int*)(self + 0x7c) = -1;
    initializeArray(self);

    int zero = 0;
    *(int*)(self + 0x8c) = zero;
    *(void**)(self + 0x88) = lbl_27_data_2490;
    *(int*)(self + 0x90) = arg;
    *(int*)(self + 0x94) = 2;
    if (arg == 0) {
        *(int*)(self + 0x94) = zero;
    }

    void* g1 = global1();
    void* g2 = global2();
    global3();

    Modules* modules = access->modules;
    char* mod = part(self, 0x6c);
    fn_27_13844(self + 0x9c, access, self + 0x88, mod, g1, g2,
                lbl_27_bss_9BC, &lbl_27_bss_5204,
                modules->holder->first.slot7(), 0, lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}
