#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);
extern "C" int fn_800C9A4C(int);
extern "C" int fn_800C9B00(int);

struct VObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(int); };
struct Sub { char pad[0x10]; int f10; };
struct Data { char pad[0x34c]; unsigned char f34c; char p2[3]; int f350; char p3[0x378-0x354]; int f378; char p4[4]; unsigned int f380; };
struct Self {
    char pad[0x6c]; Sub* f6c; char p1[4]; VObj* f74; char p2[0x128-0x78];
    int f128; char p3[4]; Data* f130; char p4[0x140-0x134]; void* f140; char p5[0x154-0x144];
    int f154; int f158; int f15c; int f160;
};

extern "C" int fn_6_BB34(Self* self) {
    Data* d = self->f130;
    int r = self->f128;
    if (d->f34c) {
        exit__6gfTaskFv(self->f140);
        self->f140 = 0;
        self->f74->v13(self->f6c->f10);
        if (d->f350 != 0) {
            switch (d->f350) {
            case 1:
                break;
            case 3:
                self->f158 = 2;
                self->f160 = d->f380;
                if (d->f380 == 0x27e0) self->f154 = 0x18;
                else self->f154 = 0x17;
                break;
            case 2: {
                self->f158 = 1;
                int v = d->f378;
                self->f160 = v;
                self->f15c = fn_800C9A4C(v);
                self->f154 = fn_800C9B00(self->f15c);
                break;
            }
            }
            r = 11;
        } else {
            r = 9;
        }
    }
    return r;
}
