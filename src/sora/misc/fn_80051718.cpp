#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" void fn_80056518(void*, u8);
extern "C" int lbl_80406D88[];

struct Tbl { int v[5][5]; };

extern "C" void fn_80051718(void* arg0, u8 arg1) {
    Tbl t = *(Tbl*)lbl_80406D88;
    int sum = t.v[0][arg1] + t.v[1][arg1];
    sum += t.v[2][arg1];
    sum += t.v[3][arg1];
    sum += t.v[4][arg1];
    int r = randi(sum);
    int* p = &t.v[0][arg1];
    int var = 0;
    int acc = 0;
#pragma unroll 5
    for (int i = 0; i < 5; ++i) {
        acc += p[i * 5];
        if (r < acc) {
            var = i;
            break;
        }
    }
    fn_80056518(arg0, (u8)(var + 1));
}