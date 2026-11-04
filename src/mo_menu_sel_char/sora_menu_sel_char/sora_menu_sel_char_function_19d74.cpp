#pragma force_active on
class Class_148 {
public:
    virtual void fn_10_3F4();
    virtual void fn_10_BD70();
    virtual void fn_10_BD50();
    virtual void fn_10_BD30();
    virtual void fn_10_BD10();
    virtual void fn_10_BCF0(float);
};
struct Inner { char pad[0x1b0]; int val; };
struct Menu { char pad[0x48]; Class_148* obj; char pad2[0x9c-0x4c]; Inner* inner; };

extern "C" void fn_10_19D74(Menu* m) {
    m->obj->fn_10_BCF0((float)(m->inner->val + 1));
}
