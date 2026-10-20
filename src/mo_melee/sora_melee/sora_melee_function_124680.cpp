#pragma force_active on
struct Inner {
    char pad[0x58];
    int idx;
};

struct Outer {
    int pad;
    Inner* inner;
};

struct AiMgr {
    char pad[0x84];
    unsigned char table[0xE];
};

extern AiMgr* g_aiMgr;

extern "C" {
int fn_27_124680(Outer* self)
{
    Inner* in = self->inner;
    int i = in->idx;
    AiMgr* mgr = g_aiMgr;
    if (i < 0 || (unsigned int)i >= 0xE) {
        return -1;
    }
    return *(unsigned char*)((char*)mgr + i + 0x84);
}
}
