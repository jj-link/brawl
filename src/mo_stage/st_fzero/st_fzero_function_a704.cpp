#pragma force_active on
struct FzeroFlags {
    int w0;
    int w1;
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" {
void fn_61_A704(FzeroFlags *s, unsigned int v);
}

extern "C" void fn_61_A704(FzeroFlags *s, unsigned int v)
{
    s->b = v;
}
