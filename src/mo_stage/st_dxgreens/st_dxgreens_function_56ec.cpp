#pragma force_active on
struct Flags {
    int field0;
    int pad4;
    unsigned int bf1 : 5;
    unsigned int bf2 : 7;
    signed int bf3 : 6;
};

extern "C" int fn_79_56EC(struct Flags* f)
{
    return f->bf3;
}
