#pragma force_active on
class Object {
public:
    virtual void slot0();
};

struct Self {
    int pad;
    Object* m_obj;
};

extern "C" {
void fn_8027917C(Self* self) {
    Object* obj = self->m_obj;
    if (obj) {
        obj->slot0();
    }
}
}