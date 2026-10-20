#pragma force_active on
struct Sub {
    int pad0;
    int pad4;
    int field8;
    int arr[3];
};

extern "C" int* fn_27_1AFA6C(Sub* p, int idx)
{
    int i = (p->field8 >> 29) + idx;
    if (i < 3) {
    } else {
        i -= 3;
    }
    return &p->arr[i];
}
