#pragma force_active on
typedef struct Elem {
    char pad[0x38];
} Elem;

extern "C" {
char* fn_40_24A00(char* base, int index)
{
    return (char*)(base + index * sizeof(Elem) + 0xc);
}
}
