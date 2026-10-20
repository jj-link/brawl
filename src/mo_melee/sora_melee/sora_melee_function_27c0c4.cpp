#pragma force_active on
extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__10grYakumonoFv(void*, int);
extern unsigned char lbl_27_data_5A900[];
}

struct Work {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x150 - 0x40];
    void* field150;
    int field154;
};

extern "C" Work* fn_27_27C0C4(Work* self, int deleting) {
    if (self) {
        void* block = self->field150;
        self->vtable = lbl_27_data_5A900;
        if (block) {
            if (block)
                __dla__FPv((char*)block - 0x10);
            self->field150 = 0;
            self->field154 = 0;
        }
        __dt__10grYakumonoFv(self, 0);
        if (deleting > 0)
            __dl__FPv(self);
    }
    return self;
}
