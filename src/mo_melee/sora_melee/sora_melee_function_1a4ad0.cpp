#pragma force_active on
struct FieldHi
{
    unsigned int hi : 7;
    unsigned int rest : 25;
};

extern "C" void fn_27_1A4AD0(void* self, unsigned int v)
{
    FieldHi* w = (FieldHi*)((char*)self + 8);
    w->hi = v;
}
