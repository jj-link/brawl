#pragma force_active on

struct Obj {
    void* v;
    unsigned short x4;
    unsigned short x6;
    float x8;
    float xc;
};

extern unsigned char lbl_80488600[];
extern const float lbl_805A44E8;
extern const float lbl_805A44EC;

extern "C" void fn_802F0714(Obj* p)
{
    float b;
    float a;
    a = lbl_805A44E8;
    b = lbl_805A44EC;
    p->v = lbl_80488600;
    p->x6 = 1;
    p->x8 = a;
    p->xc = b;
}
