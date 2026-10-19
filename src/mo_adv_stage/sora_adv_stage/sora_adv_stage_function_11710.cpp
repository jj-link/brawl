#pragma force_active on
struct Obj {
    int m_pad[2];
    int m_val;
    int m_arr[10];
};

extern "C" {
int* fn_40_11710(Obj* self, int idx) {
    int sh = self->m_val >> 27;
    int t = sh + idx;
    if (t >= 10) {
        t = t - 10;
    }
    return &self->m_arr[t];
}
}
