#pragma force_active on

class Array {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(const void*);
};

class Object_vptr_0 {
public:
    virtual void slot0();
};

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

struct Array1 {
    void* vtable;
    void* calc;
    unsigned int flags;
    char elems[0x14];
};

struct Array2 {
    void* vtable;
    void* calc;
    unsigned int flags;
    char elems[0x40];
};

struct Object {
    Array1 a1;
    Array2 a2;
    void* transitionVt;
    void* selfPtr;
    int zero74;
    int minus78;
    int minus7c;
    int zero80;
    char pad84[4];
    void* innerVt;
    int zero8c;
    int arg;
    int enabled;
    char pad98[4];
    char impl[1];
};

extern "C" {
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_2490[];
extern int lbl_27_data_11740;
extern int lbl_27_data_11600;
extern int lbl_27_data_12380;
extern signed char lbl_27_bss_5208;
extern void* lbl_27_bss_520C;
extern signed char lbl_27_bss_73A4;
extern void* lbl_27_bss_73A8;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_738C[];
extern char lbl_27_bss_7380[];
extern char lbl_27_bss_7374[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void*, void*);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*,
                 int, int, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = &lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794,
                                 lbl_27_bss_738C);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = &lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754,
                                 lbl_27_bss_7380);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = &lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_7374);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

static inline void initializeArray(Object* self) {
    char temp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(temp, i == 0 ? &self->a2 : 0);
        ((Array*)self)->v10(temp);
        fn_27_AB18C(temp, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Object* fn_27_2DA8FC(Object* self, Access* access, int arg) {
    void* vt = lbl_27_data_8E80;

    self->a1.vtable = lbl_27_data_1D4E8;
    self->a1.calc = lbl_27_data_1D4E8 + 0x48;
    self->a1.flags &= 0x01ffffff;
    __construct_array(self->a1.elems, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);

    self->a2.vtable = lbl_27_data_1A3D8;
    self->a2.calc = lbl_27_data_1A3D8 + 0x48;
    self->a2.flags &= 0x0007ffff;
    __construct_array(self->a2.elems, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 4);

    self->selfPtr = self;
    self->transitionVt = vt;
    self->zero74 = 0;
    self->zero80 = 0;
    self->minus78 = -1;
    self->minus7c = -1;

    initializeArray(self);

    self->zero8c = 0;
    self->innerVt = lbl_27_data_2490;
    self->arg = arg;
    self->enabled = 1;
    if (arg == 0) {
        self->enabled = 0;
    }

    void* g1 = global1();
    void* g2 = global2();
    global3();

    Modules* modules = access->modules;
    char* transition = part((char*)self, 0x6c);
    int id = modules->holder->first.slot7();
    fn_27_13844(self->impl, access, &self->innerVt, transition,
                g1, g2, lbl_27_bss_9BC, &lbl_27_bss_5204, id, 0, lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}
