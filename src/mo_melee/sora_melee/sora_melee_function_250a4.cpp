#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct IVecProvider {
    virtual void v0();
    virtual Vec3f* v3(void* p);
};

struct Owner {
    char pad[0x5c];
    IVecProvider* m_provider;
};

extern "C" {
void fn_27_250A4(Owner* self, Vec3f* src, void* p) {
    Vec3f* dst = self->m_provider->v3(p);
    float x = src->x;
    float y = src->y;
    dst->x = x;
    float z = src->z;
    dst->y = y;
    dst->z = z;
}
}
