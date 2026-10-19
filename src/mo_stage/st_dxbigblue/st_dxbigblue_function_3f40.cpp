#pragma force_active on
struct Obj { char pad[0xc38]; unsigned char flag; };
extern "C" bool fn_81_3F40(Obj* o) { return o->flag != 0; }
