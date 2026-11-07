#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct Pair {
    unsigned int a, b;

    Pair() {}
    Pair(const u64& x) {
        a = ((const unsigned int*)&x)[0];
        b = ((const unsigned int*)&x)[1];
    }
};

struct Item {
    char pad0[0x38];
    u8 kind;
};

struct Accesser;

class Provider {
public:
    virtual void isNull();
    virtual Item* slot1(int);
    virtual void slot2();
    virtual int count();
};

class State {
public:
    virtual void isNull();
    virtual void slot1(Item*, Accesser*);
    virtual void slot2(Item*, Accesser*);
    virtual void slot3(Item*, Accesser*);
    virtual void slot4(Item*, Accesser*, int);
};

#define D(n) virtual void d##n();

class Mod7C {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6)
    D(7) D(8) D(9) D(10) D(11) D(12)
    virtual u64 get(u16*);
};

struct Modules {
    char p[0x7C];
    Mod7C* m7c;
};

struct Accesser {
    char p[0xD8];
    Modules* modules;
};

struct Self {
    char p[0x28];
    Provider* provider;  // 0x28
    char p2c[4];
    void* unk30;         // 0x30
    char p34[4];
    u8 f38a : 1;         // 0x38
    u8 f38b : 7;
    char p39[0x17];
    u8 b50a : 1;         // 0x50
    u8 b50b : 7;
    char p51[3];
    Accesser* accesser;  // 0x54
};

extern State lbl_27_bss_3C;
extern State lbl_27_bss_4C;
extern State lbl_27_bss_5C;
extern State lbl_27_bss_6C;
extern State lbl_27_bss_7C;
extern State lbl_27_bss_8C;
extern State lbl_27_bss_9C;
extern State lbl_27_bss_AC;

extern "C" void fn_27_2F064(Item*, const Pair*);
extern "C" void fn_80112218(void*);

extern "C" void fn_27_264B0(Self* self, int arg1) {
    Item* item;
    int i;
    int count = self->provider->count();

    for (i = 0; i < count; i++) {
        item = self->provider->slot1(i);
        u16 key = 8;
        u64 value = self->accesser->modules->m7c->get(&key);
        Pair pair = value;
        fn_27_2F064(item, &pair);

        State* state;
        switch (item->kind) {
        case 1: state = &lbl_27_bss_4C; break;
        case 2: state = &lbl_27_bss_5C; break;
        case 3: state = &lbl_27_bss_7C; break;
        case 4: state = &lbl_27_bss_AC; break;
        case 5: state = &lbl_27_bss_8C; break;
        case 6: state = &lbl_27_bss_9C; break;
        case 8: state = &lbl_27_bss_6C; break;
        default: state = &lbl_27_bss_3C; break;
        }

        state->slot3(item, self->accesser);
        state->slot4(item, self->accesser, arg1);
    }

    self->b50a = 0;

    if (self->f38a == 1 && self->unk30 != 0) {
        fn_80112218(self->unk30);
    }
}
