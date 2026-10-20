#pragma force_active on
struct FnStruct76 {
    int pad[2];
    unsigned int hi : 10;
    unsigned int f : 5;
    unsigned int lo : 17;
};

extern "C" {
void fn_76_3FC0(FnStruct76 *s, unsigned int v)
{
    s->f = v;
}
}
