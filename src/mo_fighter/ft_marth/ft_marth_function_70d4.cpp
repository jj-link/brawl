#pragma force_active on
#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <so/so_value_accesser.h>
#define GETP(p, off) (*(void**)((u8*)(p) + (off)))
struct S70 {
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual int v18();
};
struct S64 {
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(f32, u32);
 virtual void v16(); virtual void v17(); virtual void v18();
 virtual void* v19(u32); virtual void v20(u32);
};
struct S64b {
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(u32);
};
struct SArg {
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
 virtual void v42(); virtual void v43(); virtual s32 v44(u8, u8);
};
struct Pad { int a,b; };
struct B38 : Pad {
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(f32, f32, void*, s32, u8, u8);
};
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void* fn_27_8CE04(void*);
extern "C" void fn_27_135848(void*, void*, f32, void*, s32, f32, f32, s32);
extern const char lbl_106_data_17F0[];
extern const char lbl_106_data_18F0[];
extern "C" void fn_106_70D4(void* self, void* arg1, f32 f1, void* arg2, s32 arg3, f32 f2, f32 f3, s32 arg4) {
 S70* o70 = (S70*)GETP(GETP(GETP(self, 0x60), 0xD8), 0x70);
 if (o70->v18() == 0x115 && arg3 == 1) {
  S64* a = (S64*)GETP(GETP(GETP(self, 0x60), 0xD8), 0x64);
  if (a->v19(0x22000013) == 0) {
   a = (S64*)GETP(GETP(GETP(self, 0x60), 0xD8), 0x64);
   a->v20(0x22000013);
   a = (S64*)GETP(GETP(GETP(self, 0x60), 0xD8), 0x64);
   a->v15(f1, 0x21000004);
   s32 x = ((SArg*)arg1)->v44(*((u8*)arg2 + 0x24), *((u8*)arg2 + 0x27));
   B38* b = (B38*)GETP(GETP(GETP(self, 0x60), 0xD8), 0x38);
   b->v15(f2, f3, arg1, x, *((u8*)arg2 + 0x24), *((u8*)arg2 + 0x27));
   a = (S64*)GETP(GETP(GETP(self, 0x60), 0xD8), 0x64);
   ((S64b*)a)->v15(0x21000005);
  }
  void* t = gfTaskScheduler::getInstance()->getTask(*(u32*)((u8*)arg2 + 0xC));
  void* d = __dynamic_cast(t, 0x3C, lbl_106_data_17F0, lbl_106_data_18F0, 1);
  void* p = fn_27_8CE04(d);
  s32 y = soValueAccesser::getConstantInt((soModuleAccesser*)GETP(self, 0x60), 0x5DC3, 0);
  ((S64*)p)->v19(y);
 }
 fn_27_135848(self, arg1, f1, arg2, arg3, f2, f3, arg4);
}