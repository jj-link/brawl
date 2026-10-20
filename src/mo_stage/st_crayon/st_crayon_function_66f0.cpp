#pragma force_active on
struct Elem { int a; int b; };
struct Obj { char pad[0xc]; Elem arr[1]; };
extern "C" Elem* fn_56_66F0(Obj* o, int i) { return &o->arr[i]; }
