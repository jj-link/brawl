#pragma force_active on
extern "C" {

struct S {
    int pad[7];
    int field_1C;
};

int fn_802CD1D0(struct S* self, int, int);

int fn_802CD248(struct S* self, struct S* a, struct S* b) {
    return fn_802CD1D0(self, a->field_1C, b->field_1C);
}

}
