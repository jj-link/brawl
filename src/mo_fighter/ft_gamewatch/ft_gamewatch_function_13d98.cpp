#include <so/so_value_accesser.h>
#pragma force_active on

struct M8 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float getFrame();
};

struct Work {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16();
    virtual int isFlag(unsigned long);
    virtual void onFlag(unsigned long);
};

struct Status {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual int getStatusKind();
};

struct Holder {
    char pad0[0x8];
    M8* m8;
    char pad1[0x58];
    Work* work;
    char pad2[0x8];
    Status* status;
};

struct Module {
    char pad[0xD8];
    Holder* holder;
};

extern const float lbl_107_rodata_B8;

extern "C" void fn_107_13D98(void*, Module* self) {
    if (self->holder->work->isFlag(0x12000003) == 0) {
        Holder* h = self->holder;
        M8* m = h->m8;
        int kind = h->status->getStatusKind();
        float v = lbl_107_rodata_B8;
        if (kind == 0x12b) {
            v = soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xc02, 0);
        } else if (kind == 0x12c) {
            v = soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xc01, 0);
        }
        if (lbl_107_rodata_B8 != v) {
            if (m->getFrame() >= v) {
                self->holder->work->onFlag(0x22000010);
            }
        }
    }
}
