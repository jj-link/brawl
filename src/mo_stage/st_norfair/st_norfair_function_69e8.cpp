#pragma force_active on
struct Fn54Entry {
    char pad[12];
};

extern "C" {
Fn54Entry* fn_54_69E8(char* base, int index)
{
    int v = *(int*)(base + 8);
    int i = (v >> 28) + index;
    if (i >= 6) {
        i -= 6;
    }
    return (Fn54Entry*)(base + i * 8 + 12);
}
}
