#pragma force_active on
extern "C" int fn_8005227C(int arg0, int arg1, int bit) {
    int arr[2];
    arr[1] = arg1;
    arr[0] = arg0;
    return (arr[bit / 32] & (1 << (bit % 32))) != 0;
}
