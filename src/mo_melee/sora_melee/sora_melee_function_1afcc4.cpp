#pragma force_active on
struct S {
    int a;
    int b;
    int c : 10;
    int d : 22;
    int arr[0x131];
};

extern "C" int* fn_27_1AFCC4(S* s, int i) {
    int j = s->c + i;
    if (j >= 0x131) j -= 0x131;
    return &s->arr[j];
}
