#pragma force_active on
typedef unsigned int u32;

struct Data {
    u32 a, b, c, d, e;
};

struct Obj {
    unsigned char pad[0x60];
    void* m_60;
};

extern "C" {
void fn_80108548(void* obj, Data* data);

void fn_801077D8(Obj* self, const Data* arg) {
    if (self->m_60 != 0) {
        Data local = *arg;
        fn_80108548(self->m_60, &local);
    }
}
}
