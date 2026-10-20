#pragma force_active on
struct Fn63Elem {
    unsigned char pad[0x0c];
    unsigned char body[0x68 - 0x0c];
};

extern "C" void* fn_63_11F84(Fn63Elem* base, int index)
{
    return &base[index].pad[0x0c];
}
