#pragma force_active on

struct B;
struct Ret {
    char pad[4];
    B* b;
};

extern const float lbl_27_rodata_3C0;
extern "C" void fn_801345E0(B* b, int flag, float value);

class Obj {
public:
    virtual void v0();
    virtual Ret* v1(int index);
};

struct Self {
    char pad[0x28];
    Obj* o;
};

extern "C" void fn_27_27810(Self* self, int index, float f, float value) {
    int flag;
    {
        int* pf = &flag;
        if (lbl_27_rodata_3C0 == f) {
            *pf = 1;
        } else {
            *pf = 0;
        }
    }
    Ret* r = self->o->v1(index);
    fn_801345E0(r->b, flag, value);
}
