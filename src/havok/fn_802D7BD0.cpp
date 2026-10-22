#pragma force_active on
struct Ctx {
    int a, b;
    int pad;
    int c, d;
    float e, f;
    int g, h;
};
struct Inner {
    char pad[8];
    int unk8;
    char pad2[0x1B8 - 0xC];
    int unk1B8;
};
struct Arg {
    int unk0;
    Inner* unk4;
    Inner* unk8;
    float unkC;
};
extern "C" void fn_802F4358(int, Ctx*);
extern "C" void fn_802E4044(Inner*, Ctx*);

extern "C" void fn_802D7BD0(int, Arg* p, float f) {
    Ctx c;
    int b = (int)p->unk8 + 0x1c;
    int a = (int)p->unk4 + 0x1c;
    float u = p->unkC;
    c.a = a;
    c.b = b;
    c.c = (int)p + 0x20;
    c.d = (int)p + 0x10;
    c.e = f;
    c.f = u;
    c.g = 0;
    c.h = 0;
    fn_802F4358(p->unk4->unk8, &c);
    if (p->unk4->unk1B8) fn_802E4044(p->unk4, &c);
    if (p->unk8->unk1B8) fn_802E4044(p->unk8, &c);
}
