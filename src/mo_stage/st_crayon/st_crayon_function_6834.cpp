#pragma force_active on
struct Unk8 {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int x : 8;
    unsigned int y : 4;
    unsigned int z : 20;
};

extern "C" void fn_56_6834(Unk8* p, unsigned int v)
{
    p->y = v;
}
