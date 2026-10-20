#pragma force_active on
struct Fn19BF2CObj {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" {
void fn_27_19BF2C(void* p, unsigned int v)
{
    ((Fn19BF2CObj*)((char*)p + 8))->b = v;
}
}
