#pragma force_active on
struct Flags {
    unsigned int hi : 4;
    unsigned int dir : 2;
};

struct Owner {
    unsigned int pad[2];
    Flags unk8;
};

extern "C" void fn_66_A324(Owner *o, unsigned int dir)
{
    o->unk8.dir = dir;
}
