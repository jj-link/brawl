#pragma force_active on
typedef unsigned char u8;

extern "C" {
u8* fn_76_3F00(u8* self, int index)
{
    int flag = *(int*)(self + 8);
    int sum = (flag >> 27) + index;
    if (sum >= 9) {
        sum -= 9;
    }
    return self + sum * 0x78 + 0xc;
}
}
