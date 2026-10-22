#pragma force_active on
extern "C" const float lbl_56_rodata_40;
extern "C" void update__9grGimmickFf(void*, float);

struct Info { char pad[0x24]; float limit; };

struct Base { unsigned char padding[0x3c]; };

#define SLOT(n) virtual void unused##n();
#define SLOTS8(n) SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) SLOT(n##5) SLOT(n##6) SLOT(n##7)

struct Object : Base {
    SLOTS8(a) SLOTS8(b) SLOTS8(c) SLOTS8(d) SLOTS8(e)
    virtual Info* getInfo();
    unsigned char padding1[0x110];
    unsigned char* ptr;
    unsigned char old;
    float t1;
    unsigned char idx;
    float t2;
};

extern "C" void fn_56_106C(Object* self, float delta) {
    update__9grGimmickFf(self, delta);
    Info* info = self->getInfo();
    if (info && *self->ptr != 4) {
        self->t1 += delta;
        self->t2 += delta;
        unsigned char cur = *self->ptr;
        if (cur != self->old) {
            if (self->idx == 8) {
                switch (cur) {
                case 0: self->idx = 0; break;
                case 1: self->idx = 2; break;
                case 2: self->idx = 4; break;
                case 3: self->idx = 6; break;
                }
            } else {
                self->idx++;
                if (self->idx >= 8) self->idx = 0;
            }
            self->t2 = lbl_56_rodata_40;
            self->old = *self->ptr;
        } else if (self->t2 >= info->limit) {
            self->idx = self->idx + 1;
            self->t2 = lbl_56_rodata_40;
        }
    }
}
