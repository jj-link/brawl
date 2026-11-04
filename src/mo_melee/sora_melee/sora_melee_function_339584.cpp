#include <types.h>
#pragma force_active on

struct TaskBase { char pad[0x3c]; };
class Task : public TaskBase {
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
 virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual int v40();
};
class Work {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual int v17(int); virtual void v18(); virtual void v19(int);
};
class Model {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(int,int,int);
};
struct Modules { char pad[0x28]; Model* model; char pad2[0x38]; Work* work; };
struct Object { char pad[8]; Task* task; char pad2[0xcc]; Modules* modules; };
extern "C" void fn_27_339584(void*, Object* obj) {
 Work* work = obj->modules->work;
 int id = 0;
 switch (obj->task->v40()) {
 case 13: id = 0; break;
 case 5: id = 0; break;
 }
 if (work->v17(0x22000011)) {
  obj->modules->model->v13(id, 1, 2);
  work->v19(0x22000011);
 }
 if (work->v17(0x22000012)) {
  obj->modules->model->v13(id, 0, 2);
  work->v19(0x22000012);
 }
}