#pragma force_active on
extern float lbl_805A3D80;
extern float lbl_805A3D84;

void fn_802871F4(float *s, float *d) {
    float one, m, l, k, j, i, h, g, f, e, z, c, b, a;
    z = lbl_805A3D80;
    a = s[0]; b = s[1]; c = s[2];
    e = s[4]; f = s[5]; g = s[6];
    h = s[8]; i = s[9]; j = s[10];
    k = s[12]; l = s[13]; m = s[14];
    d[15] = z;
    one = lbl_805A3D84;
    d[0] = a; d[1] = b; d[2] = c; d[3] = z;
    d[4] = e; d[5] = f; d[6] = g; d[7] = z;
    d[8] = h; d[9] = i; d[10] = j; d[11] = z;
    d[12] = k; d[13] = l; d[14] = m;
    d[15] = one;
}
