#pragma force_active on

#define V1(n) virtual void n();
#define V4(n) V1(n##a) V1(n##b) V1(n##c) V1(n##d)

struct Stage {
    char pad0[0x9c];
    void* f9c;
    char pad_a0[0x100];
    void* f1a0;
    char pad_1a4[0x4c];
    int f1f0[9];
    char pad_214[0x30];
    int f244;
};

struct Ground_base { char pad[0x3c]; };
struct Ground : Ground_base {
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    V1(j)
    virtual void f37(void*, int, int);
    V1(k)
    virtual void f39(void*);
    V4(l1) V4(l2) V4(l3) V4(l4) V4(l5) V4(l6) V4(l7) V4(l8) V4(l9)
    V4(m1) V4(m2) V4(m3) V4(m4) V4(m5) V4(m6) V4(m7) V4(m8) V4(m9)
    V1(p1) V1(p2) V1(p3) V1(p4) V1(p5) V1(p6) V1(p7) V1(p8) V1(p9) V1(p10)
    virtual void f122(int);
    virtual void f123(int);
    virtual void f124(void*);
    virtual void f125(void*);
};

extern "C" {
extern char lbl_67_data_0[];
Ground* fn_67_2194(int, const char*, const char*);
Ground* fn_67_8CE0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_67_88C(Stage* stage, int kind) {
    Ground* ground;
    unsigned char id1;
    int id2;
    int sp8;
    char* data = lbl_67_data_0;

    switch (kind) {
    case 2:
        ground = fn_67_2194(0, data + 0x44, data + 0x50);
        id1 = 0;
        id2 = 0;
        break;
    case 16:
        ground = fn_67_2194(0x3c, data + 0x44, data + 0x64);
        id1 = 0;
        id2 = 1;
        break;
    case 17:
        ground = fn_67_2194(0x46, data + 0x44, data + 0x7c);
        id1 = 0;
        id2 = 2;
        break;
    case 3:
        ground = fn_67_2194(1, data + 0x94, data + 0xa0);
        id1 = 1;
        id2 = 0;
        break;
    case 18:
        ground = fn_67_2194(0x3d, data + 0x94, data + 0xb4);
        id1 = 1;
        id2 = 1;
        break;
    case 19:
        ground = fn_67_2194(0x47, data + 0x94, data + 0xcc);
        id1 = 1;
        id2 = 2;
        break;
    case 4:
        ground = fn_67_2194(3, data + 0xe4, data + 0xf0);
        id1 = 2;
        id2 = 0;
        break;
    case 20:
        ground = fn_67_2194(0x3e, data + 0xe4, data + 0x104);
        id1 = 2;
        id2 = 1;
        break;
    case 21:
        ground = fn_67_2194(0x48, data + 0xe4, data + 0x11c);
        id1 = 2;
        id2 = 2;
        break;
    case 5:
        ground = fn_67_2194(4, data + 0x134, data + 0x140);
        id1 = 3;
        id2 = 0;
        break;
    case 22:
        ground = fn_67_2194(0x3f, data + 0x134, data + 0x154);
        id1 = 3;
        id2 = 1;
        break;
    case 23:
        ground = fn_67_2194(0x49, data + 0x134, data + 0x16c);
        id1 = 3;
        id2 = 2;
        break;
    case 6:
        ground = fn_67_2194(6, data + 0x184, data + 0x190);
        id1 = 4;
        id2 = 0;
        break;
    case 24:
        ground = fn_67_2194(0x40, data + 0x184, data + 0x1a4);
        id1 = 4;
        id2 = 1;
        break;
    case 25:
        ground = fn_67_2194(0x4a, data + 0x184, data + 0x1bc);
        id1 = 4;
        id2 = 2;
        break;
    case 7:
        ground = fn_67_2194(7, data + 0x1d4, data + 0x1e0);
        id1 = 5;
        id2 = 0;
        break;
    case 26:
        ground = fn_67_2194(0x41, data + 0x1d4, data + 0x1f4);
        id1 = 5;
        id2 = 1;
        break;
    case 27:
        ground = fn_67_2194(0x4b, data + 0x1d4, data + 0x20c);
        id1 = 5;
        id2 = 2;
        break;
    case 8:
        ground = fn_67_2194(8, data + 0x224, data + 0x230);
        id1 = 6;
        id2 = 0;
        break;
    case 28:
        ground = fn_67_2194(0x42, data + 0x224, data + 0x244);
        id1 = 6;
        id2 = 1;
        break;
    case 29:
        ground = fn_67_2194(0x4c, data + 0x224, data + 0x25c);
        id1 = 6;
        id2 = 2;
        break;
    case 9:
        ground = fn_67_2194(9, data + 0x274, data + 0x280);
        id1 = 7;
        id2 = 0;
        break;
    case 30:
        ground = fn_67_2194(0x43, data + 0x274, data + 0x294);
        id1 = 7;
        id2 = 1;
        break;
    case 31:
        ground = fn_67_2194(0x4d, data + 0x274, data + 0x2ac);
        id1 = 7;
        id2 = 2;
        break;
    case 10:
        ground = fn_67_8CE0(0xb, data + 0x2c4, data + 0x2d0);
        id1 = 8;
        id2 = 0;
        break;
    case 32:
        ground = fn_67_8CE0(0x44, data + 0x2c4, data + 0x2e4);
        id1 = 8;
        id2 = 1;
        break;
    case 33:
        ground = fn_67_8CE0(0x4e, data + 0x2c4, data + 0x2fc);
        id1 = 8;
        id2 = 2;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->f37(stage->f1a0, 0, 0);
        ground->f39(stage->f9c);
        sp8 = stage->f244;
        ground->f125(&sp8);
        ground->f122(id1);
        ground->f123(id2);
        ground->f124(&stage->f1f0[id1]);
    }
}
}
