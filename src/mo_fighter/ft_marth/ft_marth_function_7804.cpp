#pragma force_active on
extern "C" int fn_27_135468(char*, int);
struct Obj {
 virtual void v2(); virtual void v3(); virtual void v4();
 virtual void f5(unsigned int, char*);
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual int f18(); virtual int f19(unsigned int); virtual void v20(); virtual void f21(unsigned int);
};
extern "C" int fn_106_7804(char* self, int arg1) {
 Obj* obj;
 obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
 if (obj->f18() == 0x11E) {
  obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
  if (obj->f19(0x22000011) != 0) {
   char* q = *(char**)(self + 0x60);
   Obj* o2 = *(Obj**)(*(char**)(q + 0xd8) + 0x70);
   o2->f5(0x120, q);
   return 1;
  }
 }
 obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
 if (obj->f18() == 0x120) {
  obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
  if (obj->f19(0x22000012) != 0) {
   obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
   obj->f21(0x22000012);
  }
 }
 return fn_27_135468(self, arg1);
}