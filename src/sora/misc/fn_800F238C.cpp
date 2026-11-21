#include <mu/mu_object.h>
#pragma force_active on
struct Entry { float frame; unsigned char flag; int rangeIndex; };
extern "C" {
int fn_80153D50(void*);
extern float lbl_805A25C0;
extern float lbl_805A25D4;
extern const Entry lbl_80408D00[];
}
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
struct AnimRes { char pad[0xc]; Object_vptr_0* listener; };
struct Range { int type; unsigned int count; };
struct Self {
    char pad0[0x48];
    MuObject* object;
    char pad1[0x24];
    int selected;
    Range ranges[5];
};
inline bool testRange(Range* r, unsigned int n) {
    bool result = false;
    if (r->type == 1 && r->count >= n) result = true;
    return result;
}
extern "C" void fn_800F238C(Self* self, int index) {
    MuObject* object = self->object;
    float frame = lbl_80408D00[index].frame;
    float converted = (float)lbl_80408D00[index].flag;
    unsigned int rangeIndex = lbl_80408D00[index].rangeIndex;
    self->selected = index;
    object->setFrameNode(frame);
    Object_vptr_0* listener = ((AnimRes*)object->m_modelAnim)->listener;
    float rate = lbl_805A25C0;
    if (converted != rate) rate = lbl_805A25D4;
    listener->slot8(rate);
    unsigned int n = ((unsigned int)fn_80153D50((char*)self + 0x9c) + 0x1ffff) >> 17;
    bool result = testRange(&self->ranges[rangeIndex], n);
    float res;
    if (result) res = lbl_805A25C0;
    else res = lbl_805A25D4;
    self->object->setFrameMatCol(res);
}