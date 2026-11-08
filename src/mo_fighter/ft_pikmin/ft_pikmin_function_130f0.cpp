#pragma force_active on
#include <so/so_value_accesser.h>
struct Vec2 { float x,y; };
inline Vec2 operator+(const Vec2& a, const Vec2& b) { Vec2 v; v.x = a.x+b.x; v.y = a.y+b.y; return v; }
struct Ret { float x,y; Ret(const Ret&); };
struct ObjVtable { char pad[0x30]; void (*append)(); };
struct Obj { ObjVtable* vt; void* vt2; unsigned int flags; Vec2 items[1]; };
struct ObjInterface { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void append(const Vec2*); };
struct Wrapper { int pad; Obj obj; };
struct Class_6CDC_base { char pad[0x34]; };
class Class_6CDC : public Class_6CDC_base {
public:
 virtual void fn_113_12414(); virtual void fn_113_11EBC();
 virtual void fn_113_11ECC(); virtual void fn_113_11E74();
 virtual void fn_113_12484(); virtual void fn_113_11C04();
 virtual void fn_113_11FD0(); virtual void fn_113_12084();
 virtual void fn_113_123CC(); virtual void fn_113_11EDC();
 virtual void fn_113_11C60(const Vec2*);
};
struct Base { char pad[8]; };
struct Module : Base {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual Ret get(int, bool);
};
struct Posture {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual float facing(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual float getScale();
};
struct Modules { char pad[4]; Module* module; char pad2[4]; Posture* posture; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Self { char pad[4]; void* manager; };
extern "C" int fn_113_243CC(void*);
extern "C" void fn_113_24B10(void*, Obj*);
extern "C" void* fn_113_11D54(void*, short);
extern "C" char lbl_113_data_6CD4[];
extern "C" float lbl_113_rodata_40;
extern "C" void fn_113_130F0(Self* self, Accesser* arg) {
 if (fn_113_243CC(self->manager) > 0) {
  Ret cur = arg->modules->module->get(0,0);
  Vec2 position; position.x=cur.x; position.y=cur.y;
  float y = soValueAccesser::getConstantFloat((soModuleAccesser*)arg,0xfa7,0);
  Vec2 off;
  off.x = soValueAccesser::getConstantFloat((soModuleAccesser*)arg,0xfa6,0);
  off.y = y;
  float scale = arg->modules->posture->getScale();
  off.x *= scale; off.y *= scale;
  if (arg->modules->posture->facing() < lbl_113_rodata_40) off.x = -off.x;
  Wrapper wrapper;
  wrapper.obj.vt = (ObjVtable*)lbl_113_data_6CD4;
  wrapper.obj.vt2 = lbl_113_data_6CD4 + 0x48;
  wrapper.obj.flags &= 0x1ffffff;
  Vec2* p = wrapper.obj.items;
  do { ++p; } while (p < wrapper.obj.items + 1);
  Vec2 v = position + off;
  ((ObjInterface*)&wrapper.obj)->append(&v);
  fn_113_24B10(self->manager,&wrapper.obj);
  fn_113_11D54(&wrapper.obj,0);
 }
}