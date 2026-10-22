#pragma force_active on
extern float lbl_805A1918;
struct Col { unsigned char r, g, b, a; };
struct Ent {
    unsigned char pad[0x9D]; unsigned char k; unsigned char pad2[3]; unsigned char m;
    unsigned char pad3[2]; unsigned char flags; unsigned char pad5[3]; float a8; float ac; Col c0; Col c1; Col c2;
};
struct Base { unsigned char b[0x20]; };

extern "C" {
void fn_8005E344(Base *base, signed char *idx, Col src, float farg0) {
    Ent *p = (Ent *)(base + *idx);
    if (p->k == 1 && p->m == 2) {
        float f = lbl_805A1918;
        p->flags &= 0xFFFFFF00;
        p->ac = f;
        p->a8 = farg0;
        p->c0 = p->c2;
        p->c1 = src;
    }
}
}
