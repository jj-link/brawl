#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_1FC0;
struct V2 { float x, y; };
struct V3 { float x, y, z; };
struct Words { int x, y; };
struct M10 {
 int pad[2];
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
 virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
 virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
 virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
 virtual void v56(); virtual Words v57(int,int);
};
struct Object_vptr_0 {
 virtual void slot0(); virtual void slot1(); virtual unsigned long long slot2();
 virtual int slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual void slot11(); virtual void slot12(); virtual void slot13(unsigned int,float);
};
struct Modules { char pad0[0x10]; M10* m10; Object_vptr_0* m14; char pad1[0x4c]; soWorkManageModule* m64; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Fighter {
 char pad0[0x140]; Object_vptr_0 sub; char pad1[1]; unsigned char flag145;
 char pad2[0x47]; unsigned char flag18d; char pad3[0x1a];
 float f1a8, f1ac; char pad4[0xc]; float f1bc, f1c0, f1c4;
 char pad5[0x11]; unsigned char flag1d9; char pad6[2]; float f1dc, f1e0;
 char pad7[0x14]; float f1f8;
};
extern "C" unsigned long long fn_27_899AC(V2*,V2*);
inline void addTo(V2* out,const V2& a,const Vec2f& b) { V2 r; r.x=a.x+b.m_x; r.y=a.y+b.m_y; *(Words*)out=*(Words*)&r; }
extern "C" void fn_27_89D08(int, Accesser*, int, V2*, V3*);
extern "C" void fn_27_160770(int kind, const V2* speed, Fighter* self, Accesser* acc) {
 switch(kind) {
 case 0:
  if ((self->flag1d9 >> 7) & 1) {
   V2 r;
   r.x = lbl_27_rodata_1FC0; r.y = lbl_27_rodata_1FC0;
   switch (acc->modules->m14->slot3()) {
   default: break;
   case 0: {
   V2 b;
   Words w = acc->modules->m10->v57(8,0);
   unsigned long long result;
   V2 a;
   a.x = speed->x; a.y = lbl_27_rodata_1FC0;
   *(Words*)&b = w;
   result = fn_27_899AC(&a,&b);
   r.x = ((float*)&result)[0]; r.y = ((float*)&result)[1];
   if (lbl_27_rodata_1FC0 != r.x || lbl_27_rodata_1FC0 != r.y) {
    self->f1dc = self->f1dc + r.x;
    self->f1e0 = self->f1e0 + r.y;
    self->f1f8 = self->f1f8 + lbl_27_rodata_1FC0;
    self->flag1d9 |= 0x80;
   }
   break;
   }
   }
  }
  break;
 case 1:
  if ((self->flag18d >> 7) & 1) {
   switch (acc->modules->m14->slot3()) {
   case 0:
    if (lbl_27_rodata_1FC0 != speed->x) {
     V2 p; p.x=speed->x; p.y=lbl_27_rodata_1FC0;
     self->f1bc = self->f1bc + p.x; self->f1c0 = self->f1c0 + p.y;
     self->f1c4 = soValueAccesser::getConstantFloat((soModuleAccesser*)acc,0xc10,0);
     V2 q; q.x=soValueAccesser::getConstantFloat((soModuleAccesser*)acc,0xbbc,0); q.y=lbl_27_rodata_1FC0;
     self->f1a8=q.x; self->f1ac=q.y;
    }
    break;
   case 2: case 3:
    if (lbl_27_rodata_1FC0 != speed->x || lbl_27_rodata_1FC0 != speed->y) {
     Vec2f p(speed->x, speed->y);
     self->f1bc = self->f1bc + p.m_x; self->f1c0 = self->f1c0 + p.m_y;
     self->f1c4 = soValueAccesser::getConstantFloat((soModuleAccesser*)acc,0xc10,0);
     V2 q; q.x=soValueAccesser::getConstantFloat((soModuleAccesser*)acc,0xd1a,0); q.y=lbl_27_rodata_1FC0;
     self->f1a8=q.x; self->f1ac=q.y;
    }
    break;
   }
  }
  break;
 case 2: {
  Object_vptr_0* sub=&self->sub;
  if ((self->flag145 >> 7) & 1) {
   switch (acc->modules->m14->slot3()) {
   case 0:
    if (lbl_27_rodata_1FC0 != speed->x) {
     V2 out;
     V2 ret;
     V3 z; z.x=lbl_27_rodata_1FC0; z.y=lbl_27_rodata_1FC0; z.z=lbl_27_rodata_1FC0;
     Vec2f a(speed->x,lbl_27_rodata_1FC0);
     *(unsigned long long*)&ret=sub->slot2();
     addTo(&out,ret,a);
     fn_27_89D08(4,acc,1,&out,&z);
    }
    break;
   case 2: case 3:
    if (lbl_27_rodata_1FC0 != speed->x || lbl_27_rodata_1FC0 != speed->y) {
     V2 out;
     V2 ret;
     Vec2f a(speed->x,speed->y);
     V3 z; z.x=lbl_27_rodata_1FC0; z.y=lbl_27_rodata_1FC0; z.z=lbl_27_rodata_1FC0;
     *(unsigned long long*)&ret=sub->slot2();
     addTo(&out,ret,a);
     fn_27_89D08(4,acc,2,&out,&z);
    }
    break;
   }
  }
  break;
 }
 case 3:
  acc->modules->m64->setFloat(speed->x,0x1100000f);
  acc->modules->m64->setFloat(speed->y,0x11000010);
  break;
 }
}
