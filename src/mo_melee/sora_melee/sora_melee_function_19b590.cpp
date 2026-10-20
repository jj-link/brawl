#pragma force_active on
extern "C" {

struct fn_27_obj {
    int m_a;
    int m_b;
    unsigned : 18;
    unsigned m_c : 1;
};

int fn_27_19B590(fn_27_obj* self) {
    return self->m_c;
}

}
