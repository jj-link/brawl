#pragma force_active on
extern "C" {
double fn_80400D94(double);
double fn_80400B34(double);
double cos(double);
double atan2(double, double);
extern const float lbl_805A2D60;
extern const float lbl_805A2D6C;
void fn_8016F564(const float (*m)[4], float* out) {
    float x = (float)fn_80400D94(m[2][0]*m[2][0] + (m[0][0]*m[0][0] + m[1][0]*m[1][0]));
    if (!(x < lbl_805A2D6C)) {
        float y = (float)fn_80400D94(m[2][1]*m[2][1] + (m[0][1]*m[0][1] + m[1][1]*m[1][1]));
        if (!(y < lbl_805A2D6C)) {
            float z = (float)fn_80400D94(m[2][2]*m[2][2] + (m[0][2]*m[0][2] + m[1][2]*m[1][2]));
            if (!(z < lbl_805A2D6C)) {
                float angle = (float)fn_80400B34(-m[2][0] / x);
                out[1] = angle;
                if ((float)cos(angle) >= lbl_805A2D6C) {
                    float b = m[2][2] / z;
                    float a = m[2][1] / y;
                    out[0] = (float)atan2(a, b);
                    float d = m[0][0];
                    float c = m[1][0];
                    out[2] = (float)atan2(c, d);
                } else {
                    float b = m[1][1];
                    float c = m[0][1];
                    float a = (float)atan2(c, b);
                    out[2] = lbl_805A2D60;
                    out[0] = a;
                }
                return;
            }
        }
    }
    out[0] = lbl_805A2D60;
    out[1] = lbl_805A2D60;
    out[2] = lbl_805A2D60;
}
}