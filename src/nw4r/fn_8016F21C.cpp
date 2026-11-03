#pragma force_active on
extern "C" {
double sin(double);
double cos(double);
}

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void* fn_8016F21C(const Vec3* arg0, Vec3* arg1) {
    float temp_f31;
    float temp_f30;
    float temp_f29;
    float temp_f28;
    float temp_f27;
    float temp_f4;
    float temp_f1;

    {
        float x = arg0->x;
        temp_f31 = (float)sin(x);
    }
    Vec3* out = arg1;
    {
        float x = arg0->x;
        temp_f30 = (float)cos(x);
    }
    {
        float y = arg0->y;
        temp_f29 = (float)sin(y);
    }
    {
        float y = arg0->y;
        temp_f28 = (float)cos(y);
    }
    {
        float z = arg0->z;
        temp_f27 = (float)sin(z);
    }
    {
        float z = arg0->z;
        temp_f4 = (float)cos(z);
    }
    temp_f1 = temp_f31 * temp_f29;
    out->z = temp_f31 * temp_f28;
    out->x = (temp_f4 * temp_f1) - (temp_f30 * temp_f27);
    out->y = (temp_f27 * temp_f1) + (temp_f30 * temp_f4);
    return out;
}
