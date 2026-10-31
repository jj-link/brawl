#include <gf/gf_model.h>

#pragma force_active on

class Controller {
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
    virtual void v11(void*, void*);
    virtual void v12();
    virtual void v13(void*);

    char pad[0xE4 - 4];
    void* fieldE4;
};

struct Self {
    char pad0[0x08];
    Controller* controller;
    char pad1[0x60 - 0x0C];
    void* model;
};

extern "C" void fn_800B753C(void*, float);
extern const float lbl_805A2368;
extern const float lbl_805A2374;

extern "C" void fn_800DEF4C(Self* self) {
    int i;
    void* model = self->model;
    char* entry;

    ((gfModelAnimation*)*(void**)((char*)model + 0x14))->setUpdateRate(lbl_805A2368);
    fn_800B753C(model, lbl_805A2374);

    entry = (char*)self + 0x34;
    i = 0xD;
    do {
        void* item = *(void**)(entry + 0x10);
        if (item != 0) {
            self->controller->v13(*(void**)((char*)item + 0x10));
        }
        ++i;
        entry += 4;
    } while (i < 0x18);

    self->controller->v11(self->controller->fieldE4, *(void**)((char*)model + 0x10));
}
