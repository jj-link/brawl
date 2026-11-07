#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_100_6C60();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int, void*);
};

struct Inner {
    char pad0[0x54];
    Object_vptr_0* link;
    char pad1[0x64 - 0x58];
    Object_vptr_0* work;
};

struct Acc {
    char pad[0xd8];
    Inner* inner;
};

struct Hit {
    unsigned int taskId;
    int linkIndex;
    char pad[0xc];
    float v[4];
    unsigned char active : 1;
    unsigned char b1 : 1;
    unsigned char done : 1;
    unsigned char rest : 5;
    char padding[3];
};

struct Ev {
    int type;
    bool flag;
    int op;
    float f[5];
    char pad[0x30 - 0x20];
};

extern "C" {
extern Hit* lbl_100_bss_268;
extern float lbl_100_rodata_48;
void fn_100_FB5C(Acc*, Ev*);

void fn_100_10A4C(Acc* acc) {
    int count = acc->inner->work->slot4(0x20000000);
    int i;
    Hit* hit = lbl_100_bss_268;
    for (i = 0; i < count; ++i, ++hit) {
        if (hit->taskId != 0xFFFFFFFF && hit->active && !hit->done) {
            Ev ev;
            ev.type = 0x44f;
            ev.flag = false;
            ev.op = 6;
            ev.f[0] = hit->v[0];
            ev.f[1] = hit->v[1];
            ev.f[2] = hit->v[2];
            ev.f[3] = hit->v[3];
            ev.f[4] = lbl_100_rodata_48;
            acc->inner->link->slot15(hit->linkIndex, &ev);
            hit->done = 1;
        }
    }
    Ev ev2;
    ev2.type = 0x44f;
    ev2.flag = false;
    ev2.op = 7;
    fn_100_FB5C(acc, &ev2);
}
}
