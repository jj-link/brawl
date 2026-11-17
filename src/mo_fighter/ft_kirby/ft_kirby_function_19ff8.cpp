#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on
#pragma optimization_level 2
#pragma fp_contract on
struct TaskBase { char pad[0x3c]; };
#define V(n) virtual void v##n();
#define V8(p) V(p##0) V(p##1) V(p##2) V(p##3) V(p##4) V(p##5) V(p##6) V(p##7)
#define V32(p) V8(p##a) V8(p##b) V8(p##c) V8(p##d)
class Model { public: V32(a) V(a32) V(a33) V(a34) V(a35) virtual Vec3f position(int,bool,bool); };
class Work { public: V8(a) V(a8) virtual void setInt(int,unsigned int); V(b10) V(b11) V(b12) V(b13) V(b14) V(b15) V(b16) virtual bool getFlag(unsigned int); };
struct Modules { char pad[0x54]; Model* model; char pad2[0xc]; Work* work; };
struct Access { char pad[0xd8]; Modules* modules; };
class Task: public TaskBase { public:
V32(a) V32(b) V32(c) V32(d) V8(e) V(f0) V(f1) V(f2) V(f3) V(f4) V(f5) V(f6)
virtual void setPosition(const Vec3f*);
virtual int test();
virtual int active();
virtual Vec3f getPosition();
virtual void step();
virtual void finish();
virtual const Vec3f* start();
virtual int frame();
};
extern "C" {
void* getInstance__15gfTaskSchedulerFv();
TaskBase* getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*,int,u32);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*,unsigned int,unsigned int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(Access*,unsigned int,unsigned int);
void* __dynamic_cast(void*,long,const void*,const void*,short);
extern char lbl_96_data_5DA8[],lbl_96_data_69D8[];
extern const float lbl_96_rodata_A8,lbl_96_rodata_BC;
Vec3f* fn_96_BC54(Vec3f*,float,float,float);
void fn_96_14960(Vec3f*,const Vec3f*);
Vec3f fn_96_1A404(const Vec3f*,const Vec3f*);
Vec3f fn_96_1BE38(const Vec3f*,const Vec3f*,float,int);
Vec3f fn_96_1BAE0(void*,const Vec3f*,const Vec3f*,const Vec3f*,float);
Vec3f fn_96_1BCD8(void*,const Vec3f*,const Vec3f*,float);
}
static inline const Vec3f* temp(const Vec3f& v) { return &v; }
extern "C" void fn_96_19FF8(void* self,Access* a) {
Work* work;
struct Frame { Vec3f offset,other,position,destination,control,start; } frame;
int i=0;
Task* task=static_cast<Task*>(getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(),12,i));
int flag;
float speed=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a,0xfc1,0);
float duration=getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(a,0x5dc8,0);
float limit=lbl_96_rodata_BC+duration;
fn_96_BC54(&frame.offset,lbl_96_rodata_A8,getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a,0xfc3,0),getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a,0xfc2,0));
fn_96_14960(&frame.destination,temp(fn_96_1A404(temp(a->modules->model->position(6,i,i)),&frame.offset)));
flag=0;
if(a->modules->work->getFlag(0x2200001f)) flag=a->modules->work->getFlag(0x2200001e);
while(task) {
Task* object=static_cast<Task*>(__dynamic_cast(task,0x3c,lbl_96_data_5DA8,lbl_96_data_69D8,0));
if(object) {
if(object->test()) {
if(object->active()) {
fn_96_14960(&frame.start,object->start());
fn_96_14960(&frame.control,temp(fn_96_1BE38(&frame.start,&frame.destination,speed,1)));
object->step();
float t=object->frame()/duration;
if(t>lbl_96_rodata_BC) t=lbl_96_rodata_BC;
fn_96_14960(&frame.position,temp(fn_96_1BAE0(self,&frame.start,&frame.control,&frame.destination,t)));
fn_96_14960(&frame.other,temp(fn_96_1BCD8(self,&frame.start,&frame.destination,t)));
frame.position.m_z=frame.other.m_z;
object->setPosition(&frame.position);
} else if(flag) {
fn_96_14960(&frame.position,temp(object->getPosition()));
flag=0;
}
}
if(object->frame()>=limit) {
work = a->modules->work;
work->setInt(getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(a,0x5dca,0),0x2000000a);
object->finish();
} else ++i;
} else ++i;
task=static_cast<Task*>(getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(),12,i));
}
}