#pragma force_active on
class Manager {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C(void*);
};

struct Obj {
    char pad[0x10];
    void* m_sceneModel;
};

struct Self {
    char pad[0x28];
    Obj* arr[0x32];
    Manager* owner;
};

extern Manager* lbl_805A02E0;

static inline void notify(Manager* m, Obj* obj) {
    m->v3C(obj->m_sceneModel);
}

extern "C" void fn_800E411C(int idx, Self* self) {
    Obj* obj;
    Self* original = self;
    self = (Self*)((char*)self + ((idx + 0x19) * 4));
    obj = self->arr[0];
    notify(lbl_805A02E0, obj);
    notify(original->owner, obj);
}
