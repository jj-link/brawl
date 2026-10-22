#pragma force_active on
extern "C" void fn_802DAE14(int* arg0, int unused, int* arg2) {
 int n = arg0[7];
 int count = n * 6;
 arg2[1] = count;
 int t = ((n + 3) & ~3) + count * 8;
 arg2[0] = t + n * 16;
}
