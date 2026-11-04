#pragma force_active on
class Animation { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void setFrame(float); };
struct ModelAnimation { char pad[0xC]; Animation* animation; };
struct MuObject { char pad[0x14]; ModelAnimation* modelAnimation; };
struct Sub { char pad[0x10]; int field18; char pad1[0xC]; MuObject* objects[6]; };
struct State { char pad0[0x8]; Sub sub; char pad2[0xEC]; float field12C; int field130; int field134; };
extern float lbl_805A23B0;
extern "C" void setFrameNode__8MuObjectFf(MuObject*, float);
extern "C" int fn_800B5854(MuObject*, int, int, int, int);
extern "C" void fn_800E1588(State*, int, int, int);
extern "C" void fn_800E3820(State* self, int mode) {
    self->field130 = 0;
    if (mode != 1) { float frame = lbl_805A23B0; self->field134 = 0; self->field12C = frame; }
    MuObject** p;
    int i;
    i = 2;
    p = (MuObject**)((char*)self + 8);
    while (i < 6) { MuObject* obj = *(MuObject**)((char*)p + 40); obj->modelAnimation->animation->setFrame(lbl_805A23B0); p++; i++; }
    i = 2;
    p = self->sub.objects - 8;
    while (i < 6) { MuObject* obj = p[10]; setFrameNode__8MuObjectFf(obj, lbl_805A23B0); p++; i++; }
    i = 2;
    p = self->sub.objects - 8;
    while (i < 6) { MuObject* obj = p[10]; fn_800B5854(obj, 1, 0x10, 1, 1); p++; i++; }
    fn_800E1588(self, self->sub.field18, 0, 0);
}