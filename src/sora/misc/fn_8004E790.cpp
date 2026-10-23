#pragma force_active on
struct S {
    char pad[0x24];
    char* p;
};
extern "C" int fn_8004E790(S* arg0, int arg1) {
    return (int)(arg0->p + arg1 + 0x2E6);
}
