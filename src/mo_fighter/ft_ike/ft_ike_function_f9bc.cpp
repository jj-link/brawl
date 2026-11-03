#pragma force_active on
struct Event { int kind; bool flag; Event() : kind(0x2b), flag(false) {} };
class Class_6528 {
public:
 virtual void fn_119_58E4();
 virtual void fn_119_1164C();
 virtual void fn_119_13428();
 virtual void fn_119_13424();
 virtual void fn_119_13420();
 virtual void fn_119_1341C();
 virtual void fn_119_13414();
 virtual void fn_119_1345C();
 virtual void fn_119_13454();
 virtual void fn_119_1344C();
 virtual void fn_119_13444();
 virtual void fn_119_1343C();
 virtual void fn_119_133D4();
 virtual void fn_119_13408();
 virtual void fn_119_133FC();
 virtual void fn_119_133F4();
 virtual void fn_119_133E8(int, int);
};
class Class_6700 {
public:
 virtual void fn_119_58E4();
 virtual void fn_119_11708();
 virtual void fn_119_13614();
 virtual void fn_119_1360C();
 virtual void fn_119_13604();
 virtual void fn_119_135FC();
 virtual void fn_119_135F4();
 virtual void fn_119_135EC();
 virtual void fn_119_135E4();
 virtual void fn_119_135DC();
 virtual bool fn_119_135D4(int);
 virtual void fn_119_135CC();
 virtual void fn_119_135C4();
 virtual void fn_119_135BC();
 virtual void fn_119_1356C();
 virtual void fn_119_135B4();
 virtual void fn_119_135A4(int, Event&, unsigned int);
};
struct Modules {
 char pad[0x54]; Class_6700* link;
 char pad58[0x2c]; Class_6528* module84;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" void fn_119_F9BC(void*, Accesser* accesser, int status) {
 switch (status) {
 case 0x122:
 case 0x123:
 case 0x125:
 case 0x126:
  break;
 case 0x124:
  accesser->modules->module84->fn_119_133E8(0, 0);
  break;
 default:
  accesser->modules->module84->fn_119_133E8(0, 0);
  if (accesser->modules->link->fn_119_135D4(4)) {
   Event event;
   accesser->modules->link->fn_119_135A4(4, event, 0);
  }
  break;
 }
}