#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int hi : 8;
    unsigned int mid : 4;
    unsigned int lo : 20;
};

extern "C" void fn_40_28A08(Obj* obj, unsigned int val) {
    obj->mid = val;
}
