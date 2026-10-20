#pragma force_active on
typedef unsigned int u32;

struct Field {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_11B9DC(void* p, u32 v)
{
    Field* f = (Field*)((char*)p + 8);
    f->hi = v;
}
