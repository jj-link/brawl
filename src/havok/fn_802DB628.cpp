#pragma force_active on
extern "C" { extern const float lbl_805A426C; }
struct V4 { float x, y, z, w; };
#pragma fp_contract on
extern "C" void fn_802DB628(V4* out, const V4* a, const V4* b) {
    float temp_f0, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, temp_f9, temp_f10, temp_f11, temp_f12, temp_f13;
    __declspec(align(16)) float arg_sp[4];
    temp_f10 = a->z;
    temp_f9 = b->y;
    temp_f8 = a->y;
    temp_f2 = b->x;
    temp_f7 = b->z;
    temp_f6 = a->x;
    temp_f5 = temp_f10 * temp_f9;
    temp_f0 = temp_f8 * temp_f9;
    temp_f1 = temp_f8 * temp_f2;
    temp_f12 = temp_f8 * temp_f7 - temp_f5;
    temp_f3 = temp_f6 * temp_f7;
    temp_f4 = lbl_805A426C;
    temp_f1 = temp_f6 * temp_f9 - temp_f1;
    temp_f13 = a->w;
    temp_f5 = b->w;
    temp_f11 = temp_f10 * temp_f2 - temp_f3;
    temp_f3 = temp_f13 * temp_f2 + temp_f12;
    temp_f0 = temp_f6 * temp_f2 + temp_f0;
    temp_f1 = temp_f13 * temp_f7 + temp_f1;
    temp_f3 = temp_f5 * temp_f6 + temp_f3;
    temp_f2 = temp_f13 * temp_f9 + temp_f11;
    temp_f1 = temp_f5 * temp_f10 + temp_f1;
    temp_f4 = temp_f13 * temp_f5 + temp_f4;
    out->x = temp_f3;
    temp_f2 = temp_f5 * temp_f8 + temp_f2;
    temp_f7 = temp_f10 * temp_f7 + temp_f0;
    temp_f0 = temp_f5 * temp_f13 + temp_f4;
    out->z = temp_f1;
    temp_f4 = temp_f13 * temp_f5 - temp_f7;
    out->y = temp_f2;
    out->w = temp_f4;
    arg_sp[0] = temp_f3;
    arg_sp[1] = temp_f2;
    arg_sp[2] = temp_f1;
    arg_sp[3] = temp_f0;
}