#pragma force_active on
struct fn_27_Obj {
    int unk0;
};

void operator delete(void* p);

extern "C" {
fn_27_Obj* fn_27_31270(fn_27_Obj* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
