#pragma force_active on
typedef unsigned char u8;

typedef struct Fn803898Obj {
    u8 pad[0x4C];
    u8 sub[0x10];
} Fn803898Obj;

void fn_8038AE04(void* p);
void fn_80387DD8(void* p);
void fn_8038A0D4(void* p);

void fn_803898B0(Fn803898Obj* arg0) {
    fn_8038AE04(&arg0->sub);
    fn_80387DD8(arg0);
    fn_8038A0D4(&arg0->sub);
}
