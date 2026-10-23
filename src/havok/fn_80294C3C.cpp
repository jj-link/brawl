#pragma force_active on
#pragma fp_contract on

extern "C" {

float fn_80294C3C(float* v) {
    float t = v[1] * v[1];
    return v[0] * v[0] + t + v[2] * v[2];
}

}
