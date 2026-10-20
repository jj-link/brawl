#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int top : 6;
    unsigned int rest : 26;
} FnFlagsHolder;

extern "C" void fn_27_199260(FnFlagsHolder* p, unsigned int v)
{
    p->top = v;
}
