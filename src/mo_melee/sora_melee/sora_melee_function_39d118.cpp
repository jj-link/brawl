#pragma force_active on

#include <types.h>

struct ResourceArray {
    u8 mFlag : 1;
    u8 mFlags : 7;
    u8 mPad[3];
    const u8* mBegin;
    const u8* mEnd;
    void* mData;
    s32 mCount;
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

class Class_C80 {
public:
    virtual void fn_27_FEE4();
};

struct Holder {
    char pad[8];
    First first;
};

struct Modules {
    char pad0[4];
    Class_C80* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

class Obj {
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

    void* p4;
    unsigned int f8;
    char arr[0x14];
    void* p20;
    void* p24;
    unsigned int f28;
    char arr2[0x40];
    void* p6c;
    int p70;
    void* p74;
    int f78;
    int f7c;
    void* p80;
    int f84;
    void* p88;
    int f8c;
    int f90;
    int f94;
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
extern char lbl_27_bss_89CC[];
extern char lbl_27_bss_89C0[];
extern char lbl_27_bss_89B4[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*, int, int, void*);
void __construct_array(void*, void*, void*, int, int);
void* __register_global_object(void*, void*, void*);
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_89CC);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754, lbl_27_bss_89C0);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_89B4);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

static inline void initializeArray(Obj* self) {
    ResourceArray sp18;
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(&sp18, i == 0 ? &self->p20 : 0);
        self->v10(&sp18);
        fn_27_AB18C(&sp18, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Obj* fn_27_39D118(Obj* self, Access* arg1, int arg2) {

    *(void**)self = lbl_27_data_1D4E8;
    self->p4 = lbl_27_data_1D4E8 + 0x48;
    self->f8 &= 0x01FFFFFF;

    __construct_array(self->arr, (void*)fn_27_AB128, (void*)fn_27_AB18C, 0x14, 1);

    self->p20 = lbl_27_data_1A3D8;
    self->p24 = lbl_27_data_1A3D8 + 0x48;
    self->f28 &= 0x7FFFF;

    __construct_array(self->arr2, (void*)fn_27_D2A0C, (void*)fn_27_AB510, 0x10, 4);

    self->p70 = (int)self;
    self->p6c = lbl_27_data_8E80;
    self->p74 = 0;
    self->p80 = 0;
    self->f78 = -1;
    self->f7c = -1;

    initializeArray(self);

    self->f8c = 0;
    self->p88 = lbl_27_data_2490;
    self->f90 = arg2;
    self->f94 = 10;
    if (arg2 == 0) {
        self->f94 = 0;
    }

    void* g1 = global1();
    void* g2 = global2();
    global3();

    Modules* modules = arg1->modules;
    char* transition = part((char*)self, 0x6c);
    fn_27_13844((char*)self + 0x9c, arg1, &self->p88, transition, g1, g2, lbl_27_bss_9BC, &lbl_27_bss_5204,
                modules->holder->first.slot7(), 0, lbl_27_bss_DBC);
    arg1->modules->other->fn_27_FEE4();
    return self;
}