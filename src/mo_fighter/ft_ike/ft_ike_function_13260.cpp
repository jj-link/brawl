#pragma force_active on
struct FtIkeFlags {
    unsigned char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 6;
};

extern "C" bool fn_119_13260(FtIkeFlags *p)
{
    return p->b;
}
