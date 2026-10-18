#pragma force_active on
struct SubObj {
    virtual void v0();
    virtual int* get(int index);
    virtual void v4();
    virtual int size();
};

struct Host {
    char pad[0x2c];
    SubObj* m_obj;
};

extern "C" void fn_27_4B788(Host* self) {
    for (int i = 0; i < self->m_obj->size(); i++) {
        *self->m_obj->get(i) = 0;
    }
}
