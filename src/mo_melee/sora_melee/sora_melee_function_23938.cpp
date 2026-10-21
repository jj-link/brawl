#pragma force_active on
struct Entry {
    float x, y, z;
    float pad[3];
    float px, py, pz;
};

class Obj {
public:
    virtual void slot0() = 0;
    virtual Entry* getEntry(int index) = 0;
    virtual void slot2() = 0;
    virtual int size() = 0;
};

struct Owner {
    char pad[0x5c];
    Obj* m_obj;
};

extern "C" void fn_27_25454(Owner* self);

extern "C" void fn_27_23938(Owner* self) {
    fn_27_25454(self);
    int n = self->m_obj->size();
    for (int i = 0; i < n; i++) {
        Entry* e = self->m_obj->getEntry(i);
        e->x = e->px;
        e->y = e->py;
        e->z = e->pz;
    }
}
