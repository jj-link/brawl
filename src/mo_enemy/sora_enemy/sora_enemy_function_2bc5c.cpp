#pragma force_active on
#include <types.h>
struct acCmdArgConv { s32 argType; s32 data; };
template <class T> class ArrayBase {
public:
 virtual void v0();
 virtual T& at(int);
 virtual const T& at(int) const;
 virtual void v3();
 virtual void v4();
 virtual ~ArrayBase();
};
template <class T> class soArrayContractibleTable : public ArrayBase<T> {
public:
 virtual ~soArrayContractibleTable();
 char data[12];
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual signed char slot1();
 virtual signed char slot2();
 virtual int slot3();
 virtual void slot4();
 virtual soArrayContractibleTable<const acCmdArgConv> slot5();
};
struct Arg {
 const acCmdArgConv* p;
 unsigned char null;
 Arg(const acCmdArgConv* q) : p(q), null(0) {}
 void* getAddressData() { if (null == 1) return 0; return (void*)p->data; }
};
#pragma inline_depth(8)
#pragma inline_max_size(1000)
inline Arg getArg(const ArrayBase<const acCmdArgConv>& list, int index) {
 Arg arg(&list.at(index));
 return arg;
}
extern "C" bool fn_27_459C4(void*, Object_vptr_0*, void*, int);
extern "C" void fn_41_2BA44(void*, void*);
extern "C" bool fn_41_2BC5C(void* self, Object_vptr_0* command, void* accesser, int kind) {
 if (command->slot1() != 0x6d)
  return fn_27_459C4(self, command, accesser, kind);
 signed char type = command->slot2();
 int count = command->slot3();
 if (type <= -1 || type >= 1)
  return false;
 switch (type) {
 case 0:
  if (count < 1 || count > 1)
   return true;
  {
   const soArrayContractibleTable<const acCmdArgConv> table = command->slot5();
   Arg arg = getArg(table, 0);
   fn_41_2BA44(self, arg.getAddressData());
  }
  return true;
 }
 return false;
}