#pragma force_active on
typedef unsigned long u32;
typedef float f32;

extern "C" f32 fn_27_192278(void* self, u32 arg);
extern f32 lbl_27_rodata_7E9C;

class W {
public:
    virtual ~W();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual f32 v14(u32 id);
    virtual void v15();
    virtual void v16();
    virtual void v17(u32 id, f32 value);
    virtual void v18();
    virtual u32 v19(u32 id);
};

class Sub {
public:
    char pad[0x64];
    W* m_64;
};

class Self {
public:
    char pad[0xd8];
    Sub* m_d8;
};

extern "C" {
void fn_27_3A2D10(void* unused, Self* self) {
    if (self->m_d8->m_64->v19(0x12000047) != 1) {
        W* w = self->m_d8->m_64;
        f32 f = fn_27_192278(self, 0xfa6);
        if (w->v14(0x11000013) < f) {
            self->m_d8->m_64->v17(0x11000013, lbl_27_rodata_7E9C);
        }
    }
}
}
