#pragma force_active on
extern "C" const float lbl_27_rodata_45F0[];

#pragma push
#pragma opt_propagation off
#pragma peephole off

extern "C" float fn_27_27D2C0(float value) {
    const float* data = lbl_27_rodata_45F0;
    float minimum = data[0];
    float maximum = data[1];
    float scale = data[2];

    if (value >= minimum && value <= maximum) {
        return scale * ((value - minimum) / (maximum - minimum));
    }

    if (value < minimum) {
        return data[3];
    }

    return data[4];
}

#pragma pop
