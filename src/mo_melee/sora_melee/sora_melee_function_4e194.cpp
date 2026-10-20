#pragma force_active on
extern "C" void fn_27_4D950(int* p);

class SoraList {
public:
    virtual void v0();
    virtual int* get(int index);
    virtual void v1();
    virtual int count();
};

struct StObj {
    char pad0[0x2c];
    SoraList* list;
    float f30;
    char pad1[0xc4 - 0x34];
    int v_c4;
    char pad2[0xf8 - 0xc8];
    int vf8;
    int vfc;
    int v100;
};

extern "C" void fn_27_4E194(StObj* self, int a, float f) {
    self->v_c4 = a;
    self->f30 = f;
    self->v100 = self->vfc;
    for (int i = 0; i < self->list->count(); i++) {
        fn_27_4D950(self->list->get(i));
    }
    self->vf8 = 0;
}
