#pragma force_active on
#define V1(n) virtual void n();
#define V4(n) V1(n##a) V1(n##b) V1(n##c) V1(n##d)
struct Pad { char p[0x3c]; };
struct Ground : Pad {
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    V1(j)
    virtual void f37(void*, int, int);
    V1(k)
    virtual void f39(void*);
    V4(l1) V4(l2) V4(l3) V4(l4) V4(l5) V4(l6) V4(l7) V4(l8) V4(l9)
    V4(m1) V4(m2) V4(m3) V4(m4) V4(m5) V4(m6) V4(m7) V4(m8) V4(m9)
    virtual void f112(void*);
    V1(n1) V1(n2) V1(n3)
    virtual void f116(void*);
    virtual void f117(void*);
    virtual void f118(void*);
    virtual void f119(void*);
    virtual void f120(int);
    virtual void f121(void*);
};
struct Stage {
    char pad0[0x9c];
    void* f9c;
    char pad_a0[0x100];
    void* f1a0;
};

extern "C" {
extern char lbl_52_data_0[];
Ground* fn_52_CFC4(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_52_1320(Stage* stage, int kind) {
    Ground* ground;
    char* ptr;
    int id;
    char* data = lbl_52_data_0;

    switch (kind) {
    case 8:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x1e8);
        ptr = (char*)stage + 0x364;
        id = 0;
        break;
    case 9:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x1fc);
        ptr = (char*)stage + 0x394;
        id = 1;
        break;
    case 10:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x210);
        ptr = (char*)stage + 0x3c4;
        id = 2;
        break;
    case 11:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x224);
        ptr = (char*)stage + 0x3f4;
        id = 3;
        break;
    case 12:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x238);
        ptr = (char*)stage + 0x424;
        id = 4;
        break;
    case 13:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x24c);
        ptr = (char*)stage + 0x454;
        id = 5;
        break;
    case 14:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x260);
        ptr = (char*)stage + 0x484;
        id = 6;
        break;
    case 15:
        ground = fn_52_CFC4(0x12, data + 0x1d8, data + 0x274);
        ptr = (char*)stage + 0x4b4;
        id = 7;
        break;
    default:
        ptr = 0;
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->f37(stage->f1a0, 0, 0);
        ground->f39(stage->f9c);
        ground->f116(ptr);
        ground->f117((char*)stage + 0x568);
        ground->f120(id);
        ground->f121((char*)stage + 0x570);
        ground->f118((char*)stage + 0x56f);
        ground->f119((char*)stage + 0x5d4);
        ground->f112((char*)stage + 0x1dc);
    }
}
}
