#pragma force_active on
struct Elem { char data[0x38]; };
struct Holder { char pad[0xc]; Elem arr[1]; };
extern "C" Elem* fn_56_6430(Holder* h, int i) { return &h->arr[i]; }
