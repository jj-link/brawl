#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
class soModuleAccesser;
class soValueAccesser {
public:
 static float getValueFloat(soModuleAccesser*, unsigned long, unsigned long);
};
class emAreaModuleImpl {
public:
 static Vec3f getTargetPos(soModuleAccesser*, u32, bool);
};
struct acCmdArgConv;
template<class T> class ArrayBase {
public:
 virtual void v0();
 virtual T& at(int);
 virtual const T& at(int) const;
 virtual void v3();
 virtual void v4();
 virtual ~ArrayBase();
};
template<class T> class soArrayContractibleTable : public ArrayBase<T> {
public:
 virtual ~soArrayContractibleTable();
 char data[12];
};
class Cmd {
public:
 virtual void v0();
 virtual signed char getGroup();
 virtual signed char getType();
 virtual int getArgNum();
 virtual void v4();
 virtual soArrayContractibleTable<const acCmdArgConv> getArgList();
};
class Object_vptr_0 {
public:
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
 virtual void slot13(unsigned long, float);
};
struct Arg {
 const acCmdArgConv* p;
 unsigned char null;
 Arg(const acCmdArgConv* q) : p(q), null(0) {}
};
#pragma inline_depth(8)
#pragma inline_max_size(1000)
struct Point2 {
 float x; float y;
 Point2() {}
 Point2(const Vec3f& v) : x(v.m_x), y(v.m_y) {}
};
inline Arg getArg(const ArrayBase<const acCmdArgConv>& list, int index) {
 Arg arg(&list.at(index));
 return arg;
}
extern const float lbl_41_rodata_D50[];
extern "C" int fn_27_A4F60(void*, Cmd*, soModuleAccesser*, int);
extern "C" int fn_41_A184(const Arg&);
extern "C" int fn_41_A1C4(const Arg&);
extern "C" unsigned long fn_41_A1E4(const Arg&);
extern "C" float fn_41_A204(Arg);
extern "C" unsigned long fn_41_A27C(Arg);
extern "C" void fn_41_5AC4(Vec3f*, float, float, float);
extern "C" void fn_41_26430(soModuleAccesser*, int);
extern "C" float fn_41_25C60(soModuleAccesser*, int, Point2, unsigned long);
extern "C" float fn_41_25DF0(soModuleAccesser*, int, Point2, unsigned long);
extern "C" float fn_41_255FC(soModuleAccesser*, int, Point2, Point2, float, float, unsigned long);
extern "C" float fn_41_24144(soModuleAccesser*, int, Point2, Point2, float, float, unsigned long);
extern "C" float fn_41_244DC(soModuleAccesser*, const Vec3f&);
extern "C" Vec3f fn_41_25524(soModuleAccesser*, unsigned long, int);
extern "C" int fn_41_26510(void* self, Cmd* cmd, soModuleAccesser* accesser, int arg3) {
 const float* constants = lbl_41_rodata_D50;
 if (cmd->getGroup() != 0x69)
  return fn_27_A4F60(self, cmd, accesser, arg3);
 signed char type = cmd->getType();
 int count = cmd->getArgNum();
 if (!(type > -1 && type < 11)) return 0;
 switch(type) {
 case 0: {
  if (count < 1 || count > 1) return true;
  soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
  Arg arg = getArg(list, 0);
  int value;
  if (fn_41_A1C4(arg) == 5)
   value = (int)soValueAccesser::getValueFloat(accesser, fn_41_A1E4(arg), 0);
  else value = fn_41_A184(arg);
  fn_41_26430(accesser, value);
  return true;
 }
case 1: case 2: {
 if (count < 5 || count > 5) return true;
 soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
int value;
 if (fn_41_A1C4(getArg(list, 0)) == 5)
  value = (int)soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 0)), 0);
 else value = fn_41_A184(getArg(list, 0));
Vec3f point;
 fn_41_5AC4(&point, constants[2], constants[2], constants[2]);
if (fn_41_A1C4(getArg(list, 1)) == 5)
 point.m_x = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 1)), 0);
 else point.m_x = fn_41_A204(getArg(list, 1));
if (fn_41_A1C4(getArg(list, 2)) == 5)
 point.m_y = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 2)), 0);
 else point.m_y = fn_41_A204(getArg(list, 2));

 if (fn_41_A1C4(getArg(list, 3)) != 5) return true;
 unsigned long valueIndex = fn_41_A1E4(getArg(list, 3));
 unsigned long extra = fn_41_A27C(getArg(list, 4));
 float result = constants[2];
 if (type == 1) {
  result = fn_41_25C60(accesser, value, point, extra);
 } else if (type == 2) {
  result = fn_41_25DF0(accesser, value, point, extra);
 }
void* modules = *(void**)((char*)accesser + 0xD8);
 void* obj = *(void**)((char*)modules + 0x64);
 ((Object_vptr_0*)obj)->slot13(valueIndex, result);
 return true;
 }
case 3: case 4: {
 if (count < 9 || count > 9) return true;
 soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
int value;
 if (fn_41_A1C4(getArg(list, 0)) == 5)
  value = (int)soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 0)), 0);
 else value = fn_41_A184(getArg(list, 0));
Vec3f p1;
 fn_41_5AC4(&p1, constants[2], constants[2], constants[2]);
if (fn_41_A1C4(getArg(list, 1)) == 5)
 p1.m_x = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 1)), 0);
 else p1.m_x = fn_41_A204(getArg(list, 1));
if (fn_41_A1C4(getArg(list, 2)) == 5)
 p1.m_y = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 2)), 0);
 else p1.m_y = fn_41_A204(getArg(list, 2));
Point2 p2;
 p2.x = constants[2]; p2.y = constants[2];
if (fn_41_A1C4(getArg(list, 3)) == 5)
 p2.x = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 3)), 0);
 else p2.x = fn_41_A204(getArg(list, 3));
if (fn_41_A1C4(getArg(list, 4)) == 5)
 p2.y = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 4)), 0);
 else p2.y = fn_41_A204(getArg(list, 4));
float c;
if (fn_41_A1C4(getArg(list, 5)) == 5)
 c = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 5)), 0);
 else c = fn_41_A204(getArg(list, 5));
float d;
if (fn_41_A1C4(getArg(list, 6)) == 5)
 d = soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 6)), 0);
 else d = fn_41_A204(getArg(list, 6));

 if (fn_41_A1C4(getArg(list, 7)) != 5) return true;
 unsigned long target = fn_41_A1E4(getArg(list, 7));
 unsigned long extra = fn_41_A27C(getArg(list, 8));
 float result = constants[2];
 if (type == 3) {
  result = fn_41_255FC(accesser, value, p1, p2, c, d, extra);
 } else if (type == 4) {
  result = fn_41_24144(accesser, value, p1, p2, c, d, extra);
 }
void* modules = *(void**)((char*)accesser + 0xD8);
 void* obj = *(void**)((char*)modules + 0x64);
 ((Object_vptr_0*)obj)->slot13(target, result);
 return true;
 }
case 5: case 6:  {
 if (count < 2 || count > 2) return true;
 soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
int target;
 if (fn_41_A1C4(getArg(list, 0)) == 5)
  target = (int)soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 0)), 0);
 else target = fn_41_A184(getArg(list, 0));

 if (fn_41_A1C4(getArg(list, 1)) != 5) return true;
 unsigned long index = fn_41_A1E4(getArg(list, 1));
 float result = constants[10];
if (type == 5) {
 result = fn_41_244DC(accesser, emAreaModuleImpl::getTargetPos(accesser, target, true));
 }else if (type == 6) {
 result = fn_41_244DC(accesser, fn_41_25524(accesser, target, 1));
 }void* modules = *(void**)((char*)accesser + 0xD8);
 void* obj = *(void**)((char*)modules + 0x64);
 ((Object_vptr_0*)obj)->slot13(index, result);
 return true;
 }
case 7: case 8: case 9: case 10: {
 if (count < 2 || count > 2) return true;
 soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
int target;
 if (fn_41_A1C4(getArg(list, 0)) == 5)
  target = (int)soValueAccesser::getValueFloat(accesser, fn_41_A1E4(getArg(list, 0)), 0);
 else target = fn_41_A184(getArg(list, 0));

 if (fn_41_A1C4(getArg(list, 1)) != 5) return true;
 unsigned long index = fn_41_A1E4(getArg(list, 1));
 float result = constants[10];
if (type == 7) {
 Vec3f position = emAreaModuleImpl::getTargetPos(accesser, target, true);
 result = position.m_x;
 }else if (type == 8) {
 Vec3f position = fn_41_25524(accesser, target, 1);
 result = position.m_x;
 }else if (type == 9) {
 Vec3f position = emAreaModuleImpl::getTargetPos(accesser, target, true);
 result = position.m_y;
 }else if (type == 10) {
 Vec3f position = fn_41_25524(accesser, target, 1);
 result = position.m_y;
 }void* modules = *(void**)((char*)accesser + 0xD8);
 void* obj = *(void**)((char*)modules + 0x64);
 ((Object_vptr_0*)obj)->slot13(index, result);
 return true;
 }
default: return false;
 }
}
