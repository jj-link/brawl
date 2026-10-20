#pragma force_active on
extern "C" int* fn_27_2AE138(int* self, int index) {
    int shifted = (self[2] >> 30) + index;
    int adjusted = shifted;
    if (shifted >= 1)
        adjusted = shifted - 1;
    return self + adjusted + 3;
}
