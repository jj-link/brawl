#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Sub {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
};

struct Owner {
    u8 pad[0x30];
    Sub* m_sub;
};

extern "C" void fn_27_38994(void* a, void* b);

extern "C" void fn_27_3A718(Owner* self, void* unused, void* arg) {
    void* r = self->m_sub->v1();
    fn_27_38994(r, arg);
}
