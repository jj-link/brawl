#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Src {
    u32 val;
};

class Obj {
public:
    virtual void v0();
    virtual void v5(const Src* s);
    virtual void v6(const Src* s);
    u32 m_val;
};

struct Self {
    char pad0[0xc];
    u8 b0c;
    char pad1[3];
    int w10;
    u8 b14;
    char pad2[3];
    const Src* p18;
    Obj* p1c;
};

extern "C" {
extern u8 lbl_40_data_1E08[];
void fn_40_2E60C(Obj* self, const Src* s);

void fn_40_10A6C(Self* self) {
    u8* base = lbl_40_data_1E08;
    if (self->b0c) {
        if (self->w10 == 1) {
            if (self->b14) {
                fn_40_2E60C(self->p1c, (const Src*)(base + 0x30));
                self->p1c->v5(self->p18);
            } else {
                fn_40_2E60C(self->p1c, (const Src*)(base + 0x34));
                self->p1c->v6(self->p18);
            }
        } else if (self->w10 == 0) {
            if (self->b14) {
                fn_40_2E60C(self->p1c, (const Src*)(base + 0x38));
                self->p1c->v6(self->p18);
            } else {
                fn_40_2E60C(self->p1c, (const Src*)(base + 0x3c));
                self->p1c->v5(self->p18);
            }
        }
    }
}
}
