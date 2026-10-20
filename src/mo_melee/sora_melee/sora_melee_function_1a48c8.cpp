#pragma force_active on
typedef unsigned int u32;

struct Field {
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" {
void fn_27_1A48C8(void* p, u32 v);
}

void fn_27_1A48C8(void* p, u32 v)
{
    Field* f = (Field*)((char*)p + 8);
    f->hi = v;
}
