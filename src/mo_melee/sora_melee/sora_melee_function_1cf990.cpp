#pragma force_active on
extern "C" {
struct S8 {
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
};
void fn_27_1CF990(unsigned char* self, unsigned int v)
{
    S8* s = (S8*)(self + 8);
    s->f = v;
}
}
