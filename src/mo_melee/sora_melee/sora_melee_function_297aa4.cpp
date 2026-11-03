#pragma force_active on
#pragma fp_contract off
#include <gf/gf_task.h>
#include <so/so_external_value_accesser.h>
#include <ft/ft_external_value_accesser.h>
#include <math.h>

class Class_1250 {
public:
 virtual void fn_27_13C90();
 virtual void fn_27_14068();
 virtual void fn_27_140C0();
 virtual void fn_27_1412C();
 virtual void fn_27_14134();
 virtual void fn_27_14370();
 virtual void fn_27_14A28();
 virtual void fn_27_14A30();
 virtual void fn_27_14A38();
 virtual void fn_27_14A48();
 virtual void fn_27_14A68();
 virtual void fn_27_14AD8();
 virtual void fn_27_14A60();
 virtual void fn_27_14D08();
 virtual void fn_27_14EDC();
 virtual void fn_27_14D00();
 virtual int fn_27_14B80();
 virtual void fn_27_14B88();
 virtual void fn_27_16A70();
};
class Class_5860 {
public:
 virtual void fn_27_565F0();
 virtual void fn_27_56888();
 virtual void fn_27_5680C();
 virtual void fn_27_567F8();
 virtual void fn_27_568AC();
 virtual void fn_27_568B4(int, unsigned int);
 virtual void fn_27_569A4();
 virtual void fn_27_56A4C();
 virtual void fn_27_56AC8();
 virtual void fn_27_56BAC();
 virtual void fn_27_57528();
 virtual void fn_27_576A4();
 virtual void fn_27_57590();
 virtual void fn_27_56BEC();
 virtual void fn_27_56B88();
 virtual void fn_27_56B94();
 virtual void fn_27_57B98();
 virtual void fn_27_56BA0();
 virtual void fn_27_57B90(unsigned int);
};
struct WorkModules { char pad[0x64]; Class_5860* work; };
struct Access { char pad[0xd8]; WorkModules* modules; };
struct Status { char pad[0x70]; Class_1250* status; };
struct BaseItem { char pad[0x60]; Access* access; char pad64[0x140]; Status* status; };
struct Constants { float one, half, rad, pi, neg, zero; };
extern "C" {
extern const Constants lbl_27_rodata_46C8;
extern const char lbl_27_data_69C0[], lbl_27_data_248[], __RTTI__6gfTask[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getParamFloat__8BaseItemFUl(BaseItem*, unsigned long);
int fn_27_28CCF0(BaseItem*, int);
void fn_27_28E48C(BaseItem*, float*, float);
}
extern "C" void fn_27_297AA4(void*, BaseItem* item, int id) {
 const Constants* k = &lbl_27_rodata_46C8;
 if ((unsigned int)id + 0x10000 == 0xffff) return;
 if (item->status->status->fn_27_14B80() != 4) return;
 gfTask* task = gfTask::getTask(id);
 if (!task) return;
 float lr = k->one;
 float weight = k->half;
 if (task->m_taskCategory == 10) {
  Fighter* fighter = (Fighter*)__dynamic_cast(task, 0x3c, lbl_27_data_69C0, __RTTI__6gfTask, 0);
  if (!fighter) return;
  lr = soExternalValueAccesser::getLr((StageObject*)fighter);
  weight = ftExternalValueAccesser::getWeight(fighter);
 } else if (task->m_taskCategory == 2) {
  StageObject* object = (StageObject*)__dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
  if (!object) return;
  lr = soExternalValueAccesser::getLr(object);
 }
 float angle = k->rad * getParamFloat__8BaseItemFUl(item, 0x1004);
 if (k->neg == lr) angle = k->pi - angle;
 weight *= getParamFloat__8BaseItemFUl(item, 0x1006);
 float speed = getParamFloat__8BaseItemFUl(item, 0x1005);
 speed += weight;
 weight = speed * (float)sin(angle);
 float x = speed * (float)cos(angle);
 float vec[3];
 vec[1] = weight;
 vec[2] = k->zero;
 vec[0] = x;
 k = (const Constants*)item->access->modules->work;
 ((Class_5860*)k)->fn_27_57B90(0x12000000);
 ((Class_5860*)k)->fn_27_568B4(fn_27_28CCF0(item, 0x5e24), 0x1000000b);
 fn_27_28E48C(item, vec, lr);
}