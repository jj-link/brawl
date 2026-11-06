#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on

class Scene {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f13(void*, void*);
    char pad[0xe0];
    void* fieldE4;
};
struct Stage {
    char pad0[0x40];
    int mode;
    char pad44[0xc];
    Scene* scene;
    MuObject* objects[116];
    char pad224[0x6074 - 0x224];
    void* field6074;
    void* field6078;
    int field607c;
    char pad6080[0x6150 - 0x6080];
    u8 field6150;
};
extern "C" {
struct Rodata { float zero; char pad[0x110 - 4]; u8 indices[4]; float one; float two; };
extern const Rodata lbl_11_rodata_0;
extern char lbl_11_data_280[];
void* fn_800DA15C(int, void*, void*, void*, int, int, int);
void fn_800DA6EC(void*, int, int);
}

extern "C" void fn_11_1294(Stage* self) {
    MuObject* obj;
    const u8* indices = lbl_11_rodata_0.indices;
    const Rodata* rodata = &lbl_11_rodata_0;
    for (int i = 0; i < 3; ++i) {
        self->scene->f13(self->scene->fieldE4, self->objects[*indices]->m_sceneModel);
        ++indices;
    }
    self->scene->f13(self->scene->fieldE4, self->objects[115]);
    obj = self->objects[2];
    obj->m_modelAnim->setUpdateRate(rodata->zero);
    float frame;
    if (self->field6150) {
        int flag = 0;
        unsigned int n = self->mode - 1;
        if (n <= 5 && ((1 << n) & 0x29)) flag = 1;
        if (flag) frame = rodata->one;
        else frame = rodata->zero;
    } else {
        frame = rodata->two;
    }
    obj->setFrameVisible(frame);
    int flag = 0;
    unsigned int n = self->mode - 1;
    if (n <= 5 && ((1 << n) & 0x29)) flag = 1;
    if (flag) {
        obj = self->objects[109];
        obj->setFrameVisible(rodata->zero);
        obj->m_modelAnim->m_anmObjVisRes->SetUpdateRate(rodata->zero);
        self->scene->f13(self->scene->fieldE4, obj->m_sceneModel);
        self->field6078 = fn_800DA15C(2, self->field6074, self->objects[115], lbl_11_data_280, 0x22, 0x2a, 0x2a);
        if (self->field607c >= 0) {
            fn_800DA6EC(self->field6078, self->field607c, 0);
        }
    }
    self->objects[106]->m_modelAnim->setUpdateRate(rodata->zero);
}