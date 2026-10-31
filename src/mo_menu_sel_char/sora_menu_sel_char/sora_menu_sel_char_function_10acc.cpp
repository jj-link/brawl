#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_18_1030(void* p, u8 v);
void fn_10_10ACC(u8* self, u8 flag);
}

void fn_10_10ACC(u8* self, u8 flag)
{
    void* p = *(void**)(self + 0x62c);
    self[0x634] = flag;
    if (p == 0) {
        return;
    }
    fn_18_1030(p, (flag != 0) ? 0xFF : 0);
}
