#pragma force_active on

struct Rec {
    int a;
    float b;
    float c;
    int d;
    int e;
    unsigned char f;
    unsigned char g;
    int h;
};

struct Self {
    unsigned char pad0[0x10];
    int unk10;
    int unk14;
    int unk18;
    unsigned char pad1C[4];
    unsigned char unk20;
    unsigned char pad21[3];
    Rec r24;
    Rec r40;
};

struct Child {
    unsigned char pad0[0x28];
    int v28;
    unsigned char pad2C[0x80];
    int type;
};

extern "C" void* fn_40_15694(void* self, int id);
extern "C" void fn_40_155A0(void* out, void* self, int a, int b, int c, void* d);

extern "C" void fn_40_16090(void* arg0, int arg1) {
    Self* s = (Self*)arg0;
    Rec l78;
    Rec l5C;
    Rec l40;
    Rec l24;
    Rec l8;
    Child* c;
    Child* c2;

    c = (Child*)fn_40_15694(arg0, arg1);
    if (c != 0 && c->type == 0x2E) {
        fn_40_155A0(&l78, arg0, arg1, s->unk10, 0, &s->r24);
        s->r24.a = l78.a;
        s->r24.b = l78.b;
        s->r24.c = l78.c;
        s->r24.d = l78.d;
        s->r24.e = l78.e;
        s->r24.f = l78.f;
        s->r24.g = l78.g;
        s->r24.h = l78.h;
        fn_40_155A0(&l5C, arg0, arg1, s->unk14, 1, &s->r40);
        s->r40.a = l5C.a;
        s->r40.b = l5C.b;
        s->r40.c = l5C.c;
        s->r40.d = l5C.d;
        s->r40.e = l5C.e;
        s->r40.f = l5C.f;
        s->r40.g = l5C.g;
        s->r40.h = l5C.h;
        return;
    }
    if (s->unk20 != 0) {
        if (c != 0 && c->type == 0x3B) {
            fn_40_155A0(&l40, arg0, arg1, c->v28, 0, &s->r24);
            s->r24.a = l40.a;
            s->r24.b = l40.b;
            s->r24.c = l40.c;
            s->r24.d = l40.d;
            s->r24.e = l40.e;
            s->r24.f = l40.f;
            s->r24.g = l40.g;
            s->r24.h = l40.h;
        }
        c2 = (Child*)fn_40_15694(arg0, s->unk18);
        if (c2 != 0 && c2->type == 0x3C) {
            fn_40_155A0(&l24, arg0, s->unk18, c2->v28, 1, &s->r40);
            s->r40.a = l24.a;
            s->r40.b = l24.b;
            s->r40.c = l24.c;
            s->r40.d = l24.d;
            s->r40.e = l24.e;
            s->r40.f = l24.f;
            s->r40.g = l24.g;
            s->r40.h = l24.h;
        }
    } else if (c != 0) {
        fn_40_155A0(&l8, arg0, arg1, c->v28, 0, &s->r24);
        s->r24.a = l8.a;
        s->r24.b = l8.b;
        s->r24.c = l8.c;
        s->r24.d = l8.d;
        s->r24.e = l8.e;
        s->r24.f = l8.f;
        s->r24.g = l8.g;
        s->r24.h = l8.h;
    }
}
