#include <st/st_melee.h>
#pragma force_active on
class MetalGround : public Ground {
public:
 virtual void setStageData(void*);
 virtual void disableCalcCollision();
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot40();
 virtual void slot117(void*);
 virtual void slot118(void*);
 virtual void slot119(void*);
 virtual void slot120(void*);
 virtual void slot121(int);
};
extern "C" char lbl_71_data_0[];
extern "C" MetalGround* fn_71_E4D0(int, const char*, const char*);
extern "C" void fn_71_D34(stMelee* stage, int kind) {
 char* data = lbl_71_data_0;
 MetalGround* ground;
 void* area;
 void* flag;
 void* state;
 int mode;
 stCollisionWork* work;
 switch (kind) {
 case 9:
  ground = fn_71_E4D0(0x5a, data + 0x1e8, data + 0x1f4);
  area = (char*)stage + 0x264;
  flag = (char*)stage + 0x2b4;
  state = (char*)stage + 0x2b0;
  work = (stCollisionWork*)((char*)stage + 0x2bc);
  mode = 7;
  break;
 case 10:
  ground = fn_71_E4D0(0x5a, data + 0x1e8, data + 0x20c);
  area = (char*)stage + 0x270;
  flag = (char*)stage + 0x2b8;
  state = (char*)stage + 0x2b2;
  work = (stCollisionWork*)((char*)stage + 0x2cc);
  mode = 8;
  break;
 default:
  ground = 0;
 }
 if (ground) {
  stage->addGround(ground);
  ground->startup(*(gfArchive**)((char*)stage + 0x1a0), 0, (gfSceneRoot::LayerType)0);
  ground->setStageData(*(void**)((char*)stage + 0x9c));
  ground->slot117(area);
  ground->slot118((char*)stage + 0x27c);
  ground->slot119(flag);
  ground->slot120(state);
  ground->slot121(mode);
  stage->createCollisionSelf(work, ground, data + 0x1e8, data + 0x1e8, 0x8400);
  ground->disableCalcCollision();
 }
}
