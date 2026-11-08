#pragma force_active on
struct Input {
    unsigned int pad0;
    float a, b, c, d;
    unsigned int pad14;
    unsigned int e, f, g;
    unsigned int pad24;
    unsigned int h;
    unsigned char i, j, k, pad2f;
    unsigned int pad30[3];
    unsigned int l, m, n;
    unsigned char o;
    unsigned char pad49[11];
    unsigned int p;
};
struct Output {
    unsigned int a;
    float b, c, d, e;
    unsigned int f, g, h, i;
    float j, k, l;
    unsigned int x : 9, y : 10, z : 3, w : 1, v : 4, u : 5;
    unsigned int aa : 2, ab : 5, ac : 1, ad : 1, ae : 1, af : 1, ag : 2, ah : 9, ai : 10;
    unsigned int aj : 16, ak : 16;
    unsigned int al : 1, am : 31;
};
extern const float lbl_27_rodata_3700;
extern const float lbl_27_rodata_3704;
extern "C" void fn_27_22811C(void*, Input* a, Output* b)
{
    b->a = a->p;
    b->b = a->a;
    b->c = a->b;
    b->d = a->c;
    b->e = a->d;
    b->f = 0x169;
    b->g = a->e;
    b->h = a->f;
    b->i = a->g;
    b->x = 0;
    b->y = 0x3ff;
    b->z = a->k != 0 ? 2 : 0;
    b->w = 0;
    b->v = 15;
    b->u = a->h;
    b->aa = a->m;
    b->ab = a->n;
    b->ac = a->i;
    b->ad = a->j;
    b->ae = a->o;
    b->af = 1;
    b->ag = 0;
    b->ah = 1;
    b->aj = a->l;
    b->j = lbl_27_rodata_3700;
    b->k = lbl_27_rodata_3704;
    b->l = lbl_27_rodata_3704;
    b->ak = 0;
    b->al = 0;
}