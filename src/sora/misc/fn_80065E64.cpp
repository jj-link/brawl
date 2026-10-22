#pragma force_active on
extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void endEffect__5ecMgrFUl(void*, unsigned long);
}

extern void* g_ecMgr;

struct ecTrace {
    void* field0;
    void* field4;
    char pad8[0x24];
    unsigned int unk2C;
};

extern "C" ecTrace* __dt__7ecTraceFv(ecTrace* self, int destroyFlag) {
    if (self) {
        if (self->field0) {
            if (self->field0) {
                __dla__FPv((char*)self->field0 - 0x10);
            }
            self->field0 = 0;
        }
        if (self->field4) {
            if (self->field4) {
                __dla__FPv((char*)self->field4 - 0x10);
            }
            self->field4 = 0;
        }
        endEffect__5ecMgrFUl(g_ecMgr, self->unk2C);
        if (destroyFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
