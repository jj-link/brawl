#pragma force_active on
struct ObjField {
    char pad[8];
    unsigned int : 3;
    unsigned int f : 3;
    unsigned int : 26;
};

extern "C" {
void fn_27_19917C(ObjField* self, unsigned int v) {
    self->f = v;
}
}
