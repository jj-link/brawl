#pragma force_active on

struct Outer;

struct Sub {
    virtual void v0();
    virtual void v1(int, Outer*);
};

struct Flags {
    char pad[0x9c];
    unsigned short flags;
};

struct Word20 {
    char pad[0x20];
    unsigned int word;
};

struct Outer {
    char pad0[0x20];
    Word20* m_20;
    Flags* m_24;
    char pad1[4];
    Sub* m_2c;
};

extern "C" void fn_8016DE08(Outer* p, int arg) {
    if ((p->m_24->flags & 0x400) || (p->m_20->word & 2))
        return;

    p->m_2c->v1(arg, p);
}
