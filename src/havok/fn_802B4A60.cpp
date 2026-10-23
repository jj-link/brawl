#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned int);
    virtual void v5();
    virtual void v6();
};

class Outer {
public:
    virtual void v0(int);
    virtual void v1();
    virtual void v2();
    char pad[4];
    Inner* m_inner;
    unsigned short* m_table;
    int m_count;
};

extern "C" void fn_802B4A60(Outer* self) {
    if (self->m_inner != 0) {
        int off;
        int i;
        i = 0;
        off = 0;
        while (i < self->m_count) {
            unsigned int id = *(unsigned short*)((char*)self->m_table + off);
            if (id != 0xFFFF) {
                self->m_inner->v4(id);
            }
            off += 2;
            i++;
        }
    }
    if (self != 0) {
        self->v0(1);
    }
}
