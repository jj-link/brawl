#pragma force_active on
#include <gf/gf_task.h>
#include <mu/mu_object.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(float);
};

struct TaskFields {
    char pad0[0x2C];
    u8 flags2C;
    char pad2D[0xF];
    void* f3C;
    HeapType f40;
    int f44;
    int f48;
    nw4r::g3d::ResFile f4C;
    int f50;
    int f54;
    u8 f58;
    u8 f59;
    char pad5A[2];
    int f5C;
    nw4r::g3d::ResFile f60;
    MuObject* f64;
    int f68;
    u8 f6C;
    char pad6D[3];
    int f70;
    int f74;
    int f78;
    char pad7C[0x80];
    void* fFC;
    int f100;
    char pad104[4];
    int f108;
};

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);

extern char lbl_804570C0[];
extern char lbl_80456FE0[];
extern float lbl_805A2300;
}

inline const char* modelName(MuObject* p) {
    char* data = (char*)p->m_resMdl.ptr();
    int off = *(int*)(data + 0x3C);
    return off ? data + off : 0;
}

inline nw4r::g3d::ResFile initializeResource(int& field, nw4r::g3d::ResFile value) {
    field = 0;
    return value;
}

extern "C" void* fn_800C1B3C(
    void* self, int arg1,
    nw4r::g3d::ResFile a, nw4r::g3d::ResFile b,
    int c, int d, int e, HeapType heap,
    int stackInt, u8 g, u8 h, const char* name)
{
    TaskFields* ps = (TaskFields*)self;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        (gfTask*)self, name, gfTask::Category_Menu, 0xF, 8, true);

    ps->f40 = heap;
    ps->f44 = stackInt;
    ps->f4C = initializeResource(ps->f48, b);
    ps->f50 = c;
    ps->f54 = e;
    ps->f58 = g;
    ps->f59 = h;
    ps->f5C = d;
    ps->f3C = lbl_804570C0;
    ps->f60 = a;
    ps->f64 = 0;
    ps->f68 = 0;
    ps->f6C = 0;

    int t = 3;
    if (arg1 == 1) {
        t = 1;
    }

    ps->f70 = t;
    ps->f74 = arg1;
    ps->f78 = 0;
    ps->fFC = ps->pad7C;
    ps->f100 = 0;
    ps->f108 = 0;
    ps->flags2C &= ~2;

    if (!ps->f60.IsValid()) {
        if (ps->f64 != 0) {
            delete ps->f64;
            ps->f64 = 0;
        }
    } else {
        MuObject* made = MuObject::create(
            &ps->f60, lbl_80456FE0, e + 1, 0, ps->f40);

        if (ps->f64 != made) {
            delete ps->f64;
            ps->f64 = made;
        }

        ((Object_vptr_0*)ps->f64->m_modelAnim->m_anmObjChrRes)
            ->slot8(lbl_805A2300);

        ps->f64->changeNodeAnimN(modelName(ps->f64));
        ps->f64->changeTexSrtAnimN(modelName(ps->f64));
    }

    return self;
}
