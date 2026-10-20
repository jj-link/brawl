#pragma force_active on
struct FooSub {
    char pad[8];
    unsigned int a : 12;
    unsigned int f : 6;
    unsigned int b : 14;
};

extern "C" {
void fn_27_CE8A8(FooSub* obj, unsigned int val) {
    obj->f = val;
}
}
