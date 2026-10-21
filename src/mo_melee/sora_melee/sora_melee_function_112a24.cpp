#pragma force_active on
extern const float lbl_27_rodata_F48;
extern const float lbl_27_rodata_F4C;

struct Obj {
    char pad[0x7f8];
    int a;
    float b;
    float c;
    int d;
    float e;
    float f;
    int g;
    int h;
    float i;
    float j;
    float k;
    float l;
    int m;
    float n;
    int o;
    float q;
};

struct Holder {
    Obj* obj;
};

extern "C" {
void fn_27_112A24(Holder* h) {
    h->obj->a = 0;
    h->obj->b = lbl_27_rodata_F4C;
    h->obj->c = lbl_27_rodata_F4C;
    h->obj->d = 0;
    h->obj->e = lbl_27_rodata_F48;
    h->obj->f = lbl_27_rodata_F48;
    h->obj->g = 0;
    h->obj->h = 0;
    h->obj->i = lbl_27_rodata_F48;
    h->obj->j = lbl_27_rodata_F48;
    h->obj->k = lbl_27_rodata_F48;
    h->obj->l = lbl_27_rodata_F48;
    h->obj->m = 0;
    h->obj->n = lbl_27_rodata_F4C;
    h->obj->o = 0;
    h->obj->q = lbl_27_rodata_F48;
}
}
