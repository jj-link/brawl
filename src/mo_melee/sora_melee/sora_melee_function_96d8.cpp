#pragma force_active on
typedef struct {
    unsigned int w[12];
} Block48;

extern "C" {
void fn_27_96D8(char* src, Block48* dst)
{
    *dst = *(Block48*)(src + 0x54);
}
}
