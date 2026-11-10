#include <ft/ft_manager.h>
#pragma force_active on
extern "C" char lbl_27_data_1F88[];
extern "C" int fn_27_735C8(void*, int);
struct Result27 { void* a; void* b; int c; int d; };
class Input27 {
public:
 virtual void isNull();
 virtual void fn_27_2A0BEC();
 virtual signed char fn_27_281B1C();
 virtual int fn_27_2839BC();
 virtual void fn_27_284EA0();
 virtual Result27 fn_27_289454();
};
struct Args27 {
 void* vtable; void* a; int b, c; int arg; bool error;
 Args27(const Result27& res, int value) { a = res.b; vtable = lbl_27_data_1F88; b = res.c; c = res.d; if (!b) c = 0; arg = value; error = false; }
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual Object_vptr_0* slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
};
struct Modules27 { char pad[0x18]; Object_vptr_0* object; };
struct Fighter27 { char pad[0xd8]; Modules27* modules; };
struct Owner27 { char pad[0x60]; Fighter27* fighter; };
inline int action27(Owner27* owner, Input27* input, int arg) {
 switch (input->fn_27_281B1C()) {
 case 0x19: {
  if (input->fn_27_2839BC() == 2) {
   Args27 args(input->fn_27_289454(), arg);
   int duration;
   int slow = fn_27_735C8(&args, 0);
   duration = fn_27_735C8(&args, 1);
   if (!args.error) {
    ftManager* manager = g_ftManager;
    int player = (int)owner->fighter->modules->object->slot2()->slot2();
    manager->setSlow(player, true, slow, duration);
    return 1;
   }
  }
 } break;
 }
 return 0;
}
extern "C" int fn_27_29FBA4(void*, Owner27* owner, Input27* input, int arg) { return action27(owner, input, arg); }
