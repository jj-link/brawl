#pragma force_active on
extern "C" {

struct S {
    char pad[0xA4];
    float field;
};

void fn_27_210FD0(S* s, float val) {
    s->field += val;
}

}
