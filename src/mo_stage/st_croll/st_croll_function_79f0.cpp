#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_90_79F0(int value, int count, const int* list) {
    if (count <= 0 || list == 0) {
        return 1;
    }
    for (int i = 0; i < count; i++) {
        if (value == list[i]) {
            return 0;
        }
    }
    return 1;
}
}
