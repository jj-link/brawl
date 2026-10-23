#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void fn_800B8A0C(void*, int);
extern char lbl_8045C720[];
}

struct Resource {
    char pad[0x5C];
    virtual ~Resource();
};

struct Self {
    Resource* field0;
    void* field4;
    char pad8[8];
    void* vptr;
};

extern "C" Self* fn_800FD220(Self* self, int flag) {
    if (self) {
        void* p = self->field4;
        self->vptr = lbl_8045C720;
        if (p) {
            fn_800B8A0C(p, 1);
            self->field4 = 0;
        }
        for (unsigned int i = 0; i < 1; ++i) {
            if ((&self->field0)[i]) {
                delete (&self->field0)[i];
                (&self->field0)[i] = 0;
            }
        }
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
