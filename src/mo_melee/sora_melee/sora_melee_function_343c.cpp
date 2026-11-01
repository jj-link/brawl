#pragma force_active on

extern const float lbl_27_rodata_64;
extern const float lbl_27_rodata_68;

extern "C" void fn_27_343C(void* arg0, float* bounds) {
    float* values = (float*)arg0;

    if (((unsigned char*)arg0)[0x25] == 1) {
        bounds[2] = lbl_27_rodata_64;
        bounds[1] = lbl_27_rodata_64;
        bounds[0] = lbl_27_rodata_64;
        bounds[5] = lbl_27_rodata_68;
        bounds[4] = lbl_27_rodata_68;
        bounds[3] = lbl_27_rodata_68;
    } else {
        struct {
            float maxX;
            float maxY;
            float maxZ;
            float minX;
            float minY;
            float minZ;
        } tmp;

        if (values[0] > values[13]) {
            tmp.maxX = values[0] + values[3];
            tmp.minX = values[13] - values[3];
        } else {
            tmp.maxX = values[13] + values[3];
            tmp.minX = values[0] - values[3];
        }

        if (values[1] > values[14]) {
            tmp.maxY = values[1] + values[3];
            tmp.minY = values[14] - values[3];
        } else {
            tmp.maxY = values[14] + values[3];
            tmp.minY = values[1] - values[3];
        }

        if (values[2] > values[15]) {
            tmp.maxZ = values[2] + values[3];
            tmp.minZ = values[15] - values[3];
        } else {
            tmp.maxZ = values[15] + values[3];
            tmp.minZ = values[2] - values[3];
        }

        if (tmp.minX < bounds[0]) bounds[0] = tmp.minX;
        if (tmp.minX > bounds[3]) bounds[3] = tmp.minX;
        if (tmp.minY < bounds[1]) bounds[1] = tmp.minY;
        if (tmp.minY > bounds[4]) bounds[4] = tmp.minY;
        if (tmp.minZ < bounds[2]) bounds[2] = tmp.minZ;
        if (tmp.minZ > bounds[5]) bounds[5] = tmp.minZ;

        if (tmp.maxX < bounds[0]) bounds[0] = tmp.maxX;
        if (tmp.maxX > bounds[3]) bounds[3] = tmp.maxX;
        if (tmp.maxY < bounds[1]) bounds[1] = tmp.maxY;
        if (tmp.maxY > bounds[4]) bounds[4] = tmp.maxY;
        if (tmp.maxZ < bounds[2]) bounds[2] = tmp.maxZ;
        if (tmp.maxZ > bounds[5]) bounds[5] = tmp.maxZ;
    }
}
