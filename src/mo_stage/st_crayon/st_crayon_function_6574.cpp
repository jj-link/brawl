#pragma force_active on
struct Entry { char pad[0xc]; char data[0x84]; };
extern "C" void* fn_56_6574(Entry* e, int i) { return e[i].data; }
