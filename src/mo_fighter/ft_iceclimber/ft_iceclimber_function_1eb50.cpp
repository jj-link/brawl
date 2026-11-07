#pragma force_active on
struct Vec { float x, y, z; };
extern "C" Vec* fn_105_C1C0(Vec*, float, float, float);
extern float lbl_105_rodata_120;
extern float lbl_105_rodata_124;
class Object_vptr_0 {
public:
 virtual void fn_105_8130();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual int slot16();
};
struct Base { char pad[8]; };
struct Model : Base {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void set(int); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void mode(int);
 virtual void vectors(Vec*, Vec*);
};
struct Inner { char pad[0x70]; Object_vptr_0* obj; char pad2[0x28]; Model* model; };
struct Holder { char pad[0xd8]; Inner* inner; };
extern "C" void fn_105_1EB50(void*, Holder* h) {
 h->inner->model->set(1);
 if (h->inner->obj->slot16() == 1) {
  h->inner->model->mode(0);
  Model* m = h->inner->model;
  Vec b, a;
  m->vectors(fn_105_C1C0(&b, lbl_105_rodata_120, lbl_105_rodata_120, lbl_105_rodata_120), fn_105_C1C0(&a, lbl_105_rodata_124, lbl_105_rodata_120, lbl_105_rodata_120));
 } else if (h->inner->obj->slot16() == 2) {
  h->inner->model->mode(1);
 } else if (h->inner->obj->slot16() == 3) {
  h->inner->model->mode(2);
 }
}