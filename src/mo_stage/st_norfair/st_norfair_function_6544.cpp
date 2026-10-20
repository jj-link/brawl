#pragma force_active on
struct Elem { char pad[0xa0]; };
struct Arr { char hdr[0xc]; Elem e[1]; };
extern "C" Elem* fn_54_6544(Arr* a, int i) { return &a->e[i]; }
