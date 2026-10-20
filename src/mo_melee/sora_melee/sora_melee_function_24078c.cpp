#pragma force_active on
struct Fn27Info {
    char pad[0x1a];
    unsigned short m_1a;
    unsigned char m_1c;
};

struct Fn27Sub {
    char pad[0x620];
    unsigned int m_620;
};

struct Fn27Obj {
    char pad0[0x40];
    Fn27Info* m_40;
    char pad1[0x47 - 0x44];
    unsigned char m_47;
    char pad2[0x8c - 0x48];
    unsigned int m_8c;
    unsigned int m_90;
    char pad3[0xcc - 0x94];
    unsigned int m_cc;
    Fn27Sub* m_d0;
};

extern "C" int fn_27_24078C(Fn27Obj* self) {
    if (self->m_47 == 1) {
        goto fail;
    }
    if (self->m_8c != self->m_40->m_1a) {
        goto fail;
    }
    if (self->m_90 != self->m_40->m_1c) {
        goto fail;
    }
    if (self->m_cc == self->m_d0->m_620) {
        goto zero;
    }
fail:
    return 1;
zero:
    return 0;
}
