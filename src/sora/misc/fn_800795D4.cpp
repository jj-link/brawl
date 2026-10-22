#pragma force_active on
extern "C" {
void __dl__FPv(void*);
extern char lbl_80454530[];
}

struct SubObj {
    virtual void vf0(int);
};

struct snd3DGen {
    SubObj* sub;
    void* vtable;
};

extern "C" void* __dt__14snd3DGeneratorFv(snd3DGen* self, int flag) {
    if (self != 0) {
        SubObj* sub = self->sub;
        self->vtable = lbl_80454530;
        if (sub != 0) {
            if (sub != 0) {
                sub->vf0(1);
            }
            self->sub = 0;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
