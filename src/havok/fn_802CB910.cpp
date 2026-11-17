#pragma force_active on
class Class_802CB910;
extern "C" void fn_802CB64C(Class_802CB910*);
extern "C" char lbl_804872A8[];

class Class_8008080C {
public:
    void* vptr;
    unsigned short m04;
    short m06;
    Class_8008080C() { m06 = 1; }
    ~Class_8008080C() {}
};

struct RefCounted {
    int pad0;
    unsigned short f4;
    short f6;
};

class Class_802CBEA0 {
public:
    void* data;
    int count;
    unsigned int raw;
    Class_802CBEA0() : data(0), count(0), raw(0x80000000) {}
    ~Class_802CBEA0() {}
};

struct Head {
    int m8;
    Head(void** vp, int a0) {
        *vp = lbl_804872A8;
        m8 = a0;
    }
};

struct E1 { char pad[0x10]; unsigned char a; unsigned char b; char pad2[2]; };
struct E2 { char pad[0x18]; int a, b, c, d; char pad2[4]; unsigned char e, f; char pad3[6]; };

inline void clear1(E1* begin, E1* end) {
    E1* p = begin;
    do {
        p->a = 0;
        p->b = 0;
        p++;
    } while (p < end);
}

inline void clear2(E2* begin, E2* end) {
    E2* q = begin;
    do {
        q->a = 0; q->b = 0; q->c = 0; q->d = 0;
        q->e = 0; q->f = 0;
        q++;
    } while (q < end);
}

struct LayerA {
    int flag;
    char pad[0x800];
    E1 arr[64];
    LayerA() { clear1(arr, arr + 64); }
};

struct LayerB {
    int flag;
    char pad[0x800];
    E2 arr[16];
    LayerB() { clear2(arr, arr + 16); }
};

class Class_802CB910 : public Class_8008080C {
public:
    Class_802CB910(int, int);
    Head h;
    RefCounted* refs[8][8];
    unsigned int bits[32];
    LayerA la;
    LayerB lb;
    char pad19D4[0x1C08 - 0x19D4];
    unsigned char m1C08, m1C09;
    char pad1C0A[2];
    int m1C0C, m1C10;
    unsigned char m1C14;
    char pad1C15[3];
    Class_802CBEA0 m_1C18;
    int m1C24, m1C28, m1C2C, m1C30;
};

Class_802CB910::Class_802CB910(int a0, int a1) : h(&vptr, a0) {
    m1C24 = 0; m1C28 = 0; m1C2C = 0; m1C30 = 0;
    m1C08 = 0;
    m1C14 = 1;
    lb.flag = 0;
    RefCounted* ref = (RefCounted*)a1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            refs[i][j] = ref;
            if (ref != 0 && ref->f4 != 0) ref->f6 += 1;
        }
    }
    for (int i = 0; i < 32; i++) bits[i] = 1u << i;
    fn_802CB64C(this);
    m1C10 = 0x80;
    m1C0C = 0x200;
    m1C09 = 0;
}
