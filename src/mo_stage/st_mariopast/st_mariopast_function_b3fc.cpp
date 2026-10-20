#pragma force_active on
struct Obj { char pad[8]; int val; };
extern "C" int fn_48_B3FC(Obj* o) { return o->val >> 23; }
