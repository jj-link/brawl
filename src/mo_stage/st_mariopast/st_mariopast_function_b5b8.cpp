#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int a : 9;
    unsigned int b : 9;
    unsigned int c : 14;
} S;

extern "C" void fn_48_B5B8(S *obj, unsigned int val) {
    obj->b = val;
}
