#pragma force_active on
struct Fn27Tbl {
    int pad[4];
    int base;
    int pad2;
    float *rows[1];
};

extern "C" {
float fn_27_2FAE94(Fn27Tbl *self, int unused, int i, int j)
{
    return self->rows[i - self->base][j];
}
}
