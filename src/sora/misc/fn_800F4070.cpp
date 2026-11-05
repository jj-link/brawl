#pragma force_active on
#include <mu/mu_object.h>

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, nw4r::g3d::ScnMdl*);

    char padding[0xE0];
    void* fieldE4;
};

struct S {
    char padding0[0x40];
    Class_8042B6D0* field40;
    char padding44[8];
    MuObject* field4C;
    char padding50[0x14];
    unsigned char field64;
    char padding65[3];
    int field68;
};

extern "C" float fn_800F238C(S*, int);
extern float lbl_805A25C0;

extern "C" void fn_800F4070(S* self) {
    fn_800F238C(self, self->field68 == 0 ? 7 : 2);
    Class_8042B6D0* target = self->field40;
    MuObject* object = self->field4C;
    target->fn_801B2EEC(target->fieldE4, object->m_sceneModel);
    float frame = 0.0f;
    self->field64 = 1;
    object->setFrameNode(frame);
}
