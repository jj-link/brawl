#pragma force_active on
extern "C" {
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, unsigned long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void* getModuleAccesser__23soExternalValueAccesserFP11StageObject(void*);
extern char lbl_27_data_248[], __RTTI__6gfTask[], g_ftCommonDataAccesser[];
extern const float lbl_27_rodata_64CC;
}
struct Vec { float x,y,z; };
class IF {
public:
 virtual void v0(); virtual void v1(); virtual void v2(void*); virtual void v3();
 virtual void* v4(int); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual float v12(int); virtual void v13(int,float); virtual void v14();
 virtual void v15(void*,int); virtual int v16(); virtual void v17(); virtual void v18();
 virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int,void*);
};
struct Base { char pad[8]; };
class Builder : public Base {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual Vec v36(int,int);
};
struct Modules { char p0[4]; Builder* build; char p8[4]; IF* posture; char p10[12]; IF* kinetic; char p20[0x44]; IF* value; char p68[8]; IF* check; };
struct Access { char pad[0xd8]; Modules* mod; };
inline void applyPosition(Access* self, Access* access, const Vec& pos, float adjusted, float external) {
 Vec rot;
 Vec speed;
 IF* selfModule = self->mod->posture;
 access->mod->posture->v9();
 selfModule->v2((void*)&pos);
 speed.z=adjusted; speed.x=lbl_27_rodata_64CC; speed.y=lbl_27_rodata_64CC;
 self->mod->kinetic->v22(0,&speed);
 rot.z=external; rot.x=lbl_27_rodata_64CC; rot.y=lbl_27_rodata_64CC;
 self->mod->posture->v15(&rot,0);
}
extern "C" void fn_27_2F2460(void*, Access* self) {
 unsigned long base = 0x11000000;
 int active = self->mod->check->v16();
 IF* value = self->mod->value;
 if (active) {
  float initial = value->v12(base+1);
  void* common = getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser,3);
  float adjusted = initial + *(float*)(*(char**)((char*)common+0x8c)+0x14);
  value->v13(base+1,adjusted);
  void* id = value->v4(0x10000000);
  void* scheduler = getInstance__15gfTaskSchedulerFv();
  void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(scheduler,10,(unsigned long)id);
  void* casted = __dynamic_cast(task,0x3c,lbl_27_data_248,__RTTI__6gfTask,0);
  if(casted) {
   Access* access = (Access*)getModuleAccesser__23soExternalValueAccesserFP11StageObject(casted);
   float external = access->mod->value->v12(base+0x14);
   applyPosition(self, access, access->mod->build->v36(0x2b,0), adjusted, external);
  }
 }
}