#pragma force_active on
struct fn94Obj {
    int m_dummy;
};

extern "C" {
fn94Obj* fn_94_19FEC(fn94Obj* self, short flag) {
    if (self != 0 && flag > 0) {
        delete self;
    }
    return self;
}
}
