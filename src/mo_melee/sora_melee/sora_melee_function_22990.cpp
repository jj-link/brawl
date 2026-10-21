#pragma force_active on

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

struct Entry {
    void* object;
};

class Manager {
public:
    virtual void f0();
    virtual Entry* get(int index);
    virtual void f2();
    virtual int size();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void clear();
};

struct Owner {
    void* reserved;
    Manager* manager;
};

extern "C" void fn_27_22990(Owner* self) {
    for (int index = self->manager->size() - 1; index >= 0; --index) {
        void* object = self->manager->get(index)->object;
        if (object != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(object);
        }
    }
    self->manager->clear();
}
