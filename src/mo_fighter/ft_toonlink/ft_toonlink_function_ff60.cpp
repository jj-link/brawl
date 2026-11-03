#include <gf/gf_task_scheduler.h>
#include <so/so_external_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" { extern const char lbl_121_data_3CF0[], lbl_121_data_3DF0[]; void* __dynamic_cast(void*, long, const void*, const void*, short); }
class Work {public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual unsigned long get(int);};
class Notify {public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void send(unsigned long, int, int);};
inline Notify& getCapture(const soModuleEnumeration* m) {return *(Notify*)m->m_captureModule;}
inline soStatusModule& getStatus(const soModuleEnumeration* m) {return *m->m_statusModule;}
inline unsigned long getOwnerId(char* owner) {return *(unsigned long*)(owner+0x28);}
extern "C" void fn_121_FF60(char* self) {
unsigned long id=(*(Work**)(*(char**)(self+0xd8)+0x64))->get(0x20000003);
if(id != 0xffffffff) { gfTask* task=gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)10,id);
if(task) { StageObject* object=(StageObject*)__dynamic_cast(task,0x3c,lbl_121_data_3CF0,lbl_121_data_3DF0,1);
soModuleAccesser* access=soExternalValueAccesser::getModuleAccesser(object);
const soModuleEnumeration* modules=access->m_enumerationStart;
soStatusModule& link=getStatus(modules);
Notify& notify=getCapture(modules);
link.changeStatusRequest(0xed,access);
notify.send(getOwnerId(*(char**)(self+8)),0xed,0);
}}}