#pragma force_active on
struct FPair {
    float x;
    float y;
};

struct CopyData {
    int f0, f1, f2, f3, f4, f5, f6;
    int f7, f8, f9, f10, f11, f12, f13;
};

class ObjB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual FPair v9();
    CopyData data;
};

class ObjA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual FPair v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(ObjB* arg);
};

class MainObj {
public:
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    char pad1[0x5c - 0x24];
    ObjA* f5c;
    ObjB* f60;
};

extern "C" void fn_801340C0(MainObj* self, const char* src) {
    self->f5c->v14(self->f60);

    ObjB& dst = *self->f60;
    dst.data.f0 = *(const int*)(src + 0);
    int a1 = *(const int*)(src + 4);
    int a2 = *(const int*)(src + 8);
    dst.data.f1 = a1;
    int a3 = *(const int*)(src + 12);
    dst.data.f2 = a2;
    int a4 = *(const int*)(src + 16);
    dst.data.f3 = a3;
    int a5 = *(const int*)(src + 20);
    dst.data.f4 = a4;
    int a6 = *(const int*)(src + 24);
    dst.data.f5 = a5;
    int a7 = *(const int*)(src + 28);
    dst.data.f6 = a6;
    int a8 = *(const int*)(src + 32);
    dst.data.f7 = a7;
    int a9 = *(const int*)(src + 36);
    dst.data.f8 = a8;
    int a10 = *(const int*)(src + 40);
    dst.data.f9 = a9;
    int a11 = *(const int*)(src + 44);
    dst.data.f10 = a10;
    int a12 = *(const int*)(src + 48);
    dst.data.f11 = a11;
    int a13 = *(const int*)(src + 52);
    dst.data.f12 = a12;
    dst.data.f13 = a13;

    FPair r = self->f5c->v9();
    self->f14 = r.x;
    self->f18 = r.y;

    FPair r2 = self->f60->v9();
    self->f1c = r2.x;
    self->f20 = r2.y;
}
