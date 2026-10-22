#pragma force_active on
#include <mt/mt_vector.h>
struct Base { char pad[0x3C]; };
struct Self : Base {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void vf(Vec3f* p, int flag, int value);
    char pad1[0x88];
    unsigned char flag;
    char pad2[0x9B];
    Vec3f* elems;
    char pad3[4];
    Vec3f* off;
    char pad4[4];
    unsigned char idx;
    char pad5[0xB];
    int a;
    int b;
};
extern "C" void processAnim__6GroundFv(void* self);
extern "C" void fn_81_4814(Self* self) {
    processAnim__6GroundFv(self);
    if (self->flag && self->elems) {
        self->vf(self->elems + self->idx * 2, 0, self->a);
        self->vf(self->elems + (self->idx * 2 + 1), 0, self->b);
        Vec3f t;
        Vec3f* p = self->elems + self->idx * 2;
        Vec3fSub(&t, p, self->off);
        *p = t;
        Vec3f u;
        Vec3f* q = self->elems + (self->idx * 2 + 1);
        Vec3fSub(&u, q, self->off);
        *q = u;
    }
}
