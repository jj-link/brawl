#pragma force_active on
extern "C" {

struct SoraSceneObj {
    void* vtable;
    int field_4;
    int field_8;
};

void fn_1_3CDA0(SoraSceneObj* self) {
    self->field_8 = 0;
}

}
