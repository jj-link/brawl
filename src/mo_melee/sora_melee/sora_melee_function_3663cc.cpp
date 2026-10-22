#pragma force_active on

extern "C" void fn_27_1DB0F0(void*, void*, void*, void*, void*);

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void call(int, void*);
};

struct Inner {
    unsigned char padding[0x70];
    Object* m_object;
};

struct Mid {
    unsigned char padding[0xd8];
    Inner* m_inner;
};

struct Self {
    unsigned char padding[0x60];
    Mid* m_mid;
};

extern "C" void fn_27_3663CC(Self* self, int* event, void* a, void* b, void* c) {
    switch (*event) {
    case 0x838:
        self->m_mid->m_inner->m_object->call(1, self->m_mid);
        break;
    case 0x839:
        self->m_mid->m_inner->m_object->call(2, self->m_mid);
        break;
    }
    fn_27_1DB0F0(self, event, a, b, c);
}
