#pragma force_active on
typedef struct Arg0 {
    char pad[0x14];
    char* base;
} Arg0;

typedef struct Arg1 {
    char pad[4];
    short index;
} Arg1;

extern "C" {
void* fn_80111B94(Arg0* arg0, Arg1* arg1) {
    char* result = 0;
    if (arg1->index >= 0) {
        result = arg0->base + arg1->index * 0x12;
    }
    return result;
}
}
