#pragma force_active on
struct fn_27_1D0A18_obj {
    unsigned int hi : 8;
    unsigned int mid : 4;
    unsigned int lo : 20;
};

extern "C" void fn_27_1D0A18(void* obj, unsigned int v) {
    fn_27_1D0A18_obj* p = (fn_27_1D0A18_obj*)((char*)obj + 8);
    p->mid = v;
}
