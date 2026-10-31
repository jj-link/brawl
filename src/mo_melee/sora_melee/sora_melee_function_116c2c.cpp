#pragma force_active on
class Fighter {
public:
    void setSuperStar(bool a, int b, bool c);
};

struct FighterOwner {
    unsigned char pad0[0xa];
    unsigned char idx;
    unsigned char pad1[0x4];
    unsigned char state;
};

extern "C" void fn_27_116C2C(FighterOwner* self)
{
    if (self->state != 6) {
        return;
    }
    Fighter* f = *(Fighter**)((char*)self + self->idx * 8 + 0x34);
    f->setSuperStar(true, -1, true);
}
