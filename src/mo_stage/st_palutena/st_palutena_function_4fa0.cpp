#pragma force_active on
struct Packed {
    unsigned : 4;
    int field : 2;
    unsigned : 26;
};

extern "C" int fn_67_4FA0(struct Packed *p)
{
    return p[2].field;
}
