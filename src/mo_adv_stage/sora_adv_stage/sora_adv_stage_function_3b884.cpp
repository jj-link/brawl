#pragma force_active on
extern "C" {
void fn_40_251D4(void* self);
extern float lbl_40_bss_2898;
}

class gfModelAnimation {
public:
    void setFrame(double frame);
};

class VirtualThing {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(double f);
};

struct Sub {
    void* a;
    void* b;
    void* c;
    VirtualThing* vt;
};

struct AnimWrapper {
    gfModelAnimation* anim;
    Sub* sub;
};

extern "C" void fn_40_3B884(void* self) {
    fn_40_251D4(self);
    float val = lbl_40_bss_2898;
    (*(AnimWrapper**)((char*)self + 0x48))->anim->setFrame(val);
    (*(AnimWrapper**)((char*)self + 0x48))->sub->vt->v5(val);
}
