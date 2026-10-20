#pragma force_active on
typedef unsigned int u32;

struct Data {
    u32 a, b, c, d, e;
};

struct Input {
    Data data;
    unsigned char enabled;
};

extern "C" {
extern void* g_IfAdvMngr;
void fn_801077D8(void*, Data*);

void fn_40_15BB4(void*, const Input* input) {
    if (g_IfAdvMngr != 0 && input->enabled != 0) {
        Data data = input->data;
        fn_801077D8(g_IfAdvMngr, &data);
    }
}
}
