#pragma force_active on
struct Flags {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_67_5168(struct Flags *obj, unsigned int v)
{
    obj->b = v;
}
