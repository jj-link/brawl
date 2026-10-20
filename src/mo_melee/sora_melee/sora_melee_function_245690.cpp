#pragma force_active on
struct Fn27Obj {
    unsigned char pad0[0x40];
    unsigned char flag40;
    unsigned char pad41[7];
    float val48;
    float val4c;
};

extern "C" {
void fn_27_245690(Fn27Obj* p)
{
    float f0 = p->val48;
    p->flag40 = 1;
    p->val4c = f0;
}
}
