#pragma force_active on
extern "C" {
extern const float lbl_11_rodata_0[];
void fn_11_1B70(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
void setFrameMatCol__8MuObjectFf(void*, float);
}

class Animation {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setRate(float);
};

class Group {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void insert(int, void*);
    virtual void remove(int);
    char pad[0xe0];
    int count;
};

struct Animations {
    char pad0[8];
    Animation* visible;
    char pad1[0xc];
    Animation* matCol;
};

struct Object {
    char pad0[0x10];
    void* model;
    Animations* animations;
};

struct Menu {
    char pad0[0x50];
    Group* group;
    char pad1[0x170];
    Object* model;
    Object* objects[7];
    Object* matCol1;
    Object* matCol2;
    char pad2[4];
    Object* visible;
    char pad3[0x24];
    Group* children;
};

inline void resetVisible(Object* object) {
    setFrameVisible__8MuObjectFf(object, lbl_11_rodata_0[0]);
    object->animations->visible->setRate(lbl_11_rodata_0[0]);
}

inline void resetMatCol(Object* object) {
    setFrameMatCol__8MuObjectFf(object, lbl_11_rodata_0[0]);
    object->animations->matCol->setRate(lbl_11_rodata_0[0]);
}

extern "C" void fn_11_19FC(Menu* self, float delta) {
    Group* group = self->children;
    while (group->count != 0) {
        if (group->count != 0) {
            group->remove(group->count - 1);
        }
    }
    fn_11_1B70(self, delta);
    self->group->insert(self->group->count, self->model->model);
    for (int i = 0; i < 7; ++i) {
        resetVisible(self->objects[i]);
    }
    resetMatCol(self->matCol1);
    resetMatCol(self->matCol2);
    resetVisible(self->visible);
}
