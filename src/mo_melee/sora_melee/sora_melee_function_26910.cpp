#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

struct Pair {
    unsigned int a, b;

    Pair() {}
    Pair(const u64& x) {
        a = ((const unsigned int*)&x)[0];
        b = ((const unsigned int*)&x)[1];
    }
};

struct FirstPair {
    unsigned int a, b;

    FirstPair(const u64& x) {
        a = ((const unsigned int*)&x)[0];
        b = ((const unsigned int*)&x)[1];
    }
};

struct Item {
    char pad0[4];
    void* data;
    char pad1[0x30];
    u8 kind;
};

class Provider {
public:
    virtual void isNull();
    virtual Item* slot1(int);
};

struct Accesser;

class State {
public:
    virtual void isNull();
    virtual void slot1(Item*, Accesser*);
    virtual void slot2(Item*, Accesser*);
    virtual void slot3(Item*, Accesser*);
    virtual void slot4(Item*, Accesser*, bool);
};

extern State lbl_27_bss_3C;
extern State lbl_27_bss_4C;
extern State lbl_27_bss_5C;
extern State lbl_27_bss_6C;
extern State lbl_27_bss_7C;
extern State lbl_27_bss_8C;
extern State lbl_27_bss_9C;
extern State lbl_27_bss_AC;

#define SELECT(k, out)                       \
    switch (k) {                             \
    case 1: out = &lbl_27_bss_4C; break;    \
    case 2: out = &lbl_27_bss_5C; break;    \
    case 3: out = &lbl_27_bss_7C; break;    \
    case 4: out = &lbl_27_bss_AC; break;    \
    case 5: out = &lbl_27_bss_8C; break;    \
    case 6: out = &lbl_27_bss_9C; break;    \
    case 8: out = &lbl_27_bss_6C; break;    \
    default: out = &lbl_27_bss_3C; break;    \
    }

#define D(n) virtual void d##n();

class ModC {
public:
    D(0) D(1) D(2) D(3) D(4)
    virtual void set(const struct Vec&);
};

class Mod7C {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6)
    D(7) D(8) D(9) D(10) D(11) D(12)
    virtual u64 get(u16*);
};

struct Modules {
    char p[0xC];
    ModC* c;
    char p2[0x6C];
    Mod7C* m7c;
};

struct TaskBase {
    char p[0x3C];
};

class Task : public TaskBase {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23)
    D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31)
    D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42)
    virtual void call();
};

struct Accesser {
    char p[8];
    Task* task;
    char p2[0xCC];
    Modules* modules;
};

struct Vec {
    char data[12];
};

struct SelfBase {
    char p[8];
};

class Self : public SelfBase {
public:
    D(v0) D(v1) D(v2) D(v3) D(v4) D(v5) D(v6) D(v7)
    D(v8) D(v9) D(v10) D(v11) D(v12) D(v13) D(v14) D(v15)
    D(v16) D(v17) D(v18) D(v19) D(v20) D(v21) D(v22) D(v23)
    D(v24) D(v25) D(v26) D(v27) D(v28) D(v29) D(v30) D(v31)
    D(v32) D(v33) D(v34)
    virtual Vec getVec(int);
    D(w0) D(w1) D(w2) D(w3) D(w4) D(w5) D(w6) D(w7)
    D(w8) D(w9) D(w10) D(w11) D(w12) D(w13) D(w14) D(w15)
    D(w16) D(w17) D(w18) D(w19) D(w20) D(w21) D(w22) D(w23)
    D(w24) D(w25) D(w26) D(w27) D(w28) D(w29) D(w30) D(w31)
    D(w32) D(w33) D(w34) D(w35) D(w36) D(w37) D(w38) D(w39)
    D(w40) D(w41) D(w42) D(w43) D(w44) D(w45) D(w46) D(w47)
    D(w48) D(w49)
    virtual u64 getPair(int);

    char p2[0x1C];
    Provider* provider;
    char p3[0x24];
    u8 flags;
    char p4[3];
    Accesser* accesser;
};

extern "C" void fn_27_2F064(Item*, const FirstPair*);
extern "C" void fn_27_2F044(Item*, Pair*);
extern "C" void fn_80134CA0(void*);

extern "C" void fn_27_26910(Self* self, u8 kind, int index) {
    Pair pair2;
    u64 value;
    u64 firstValue;

    if (kind != 7) {
        u8 old = self->provider->slot1(index)->kind;

        if (old != kind) {
            State* state;
            SELECT(self->provider->slot1(index)->kind, state)
            state->slot2(self->provider->slot1(index), self->accesser);

            SELECT(kind, state)
            state->slot1(self->provider->slot1(index), self->accesser);
        }

        self->provider->slot1(index)->kind = kind;

        if ((unsigned int)((self->flags >> 6) & 1) == 1 &&
            old == 0 && kind != 0) {
            self->accesser->task->call();

            Item* item = self->provider->slot1(index);
            u16 key = 8;
            firstValue = self->accesser->modules->m7c->get(&key);
            const FirstPair& pair = firstValue;
            fn_27_2F064(item, &pair);

            State* state;
            SELECT(item->kind, state)
            state->slot3(item, self->accesser);
            state->slot4(item, self->accesser, true);

            fn_80134CA0(self->provider->slot1(index)->data);
            self->accesser->modules->c->set(self->getVec(0));
            self->accesser->task->call();

            value = self->getPair(index);
            pair2 = value;
            fn_27_2F044(self->provider->slot1(index), &pair2);
        }
    }
}
