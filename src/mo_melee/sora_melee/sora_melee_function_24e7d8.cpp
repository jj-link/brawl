#pragma force_active on

struct cmAIController {
    unsigned char pad[0x94];
    unsigned char flags;
};

extern cmAIController* g_cmAIController;

struct lbl_27_data_4F588_t {
    unsigned char pad[0xB0];
};

extern lbl_27_data_4F588_t lbl_27_data_4F588;

extern "C" {
void __dl__FPv(void*);
void* fn_27_24DFF4(void*, int);

struct Class24E7D8 {
    unsigned char pad[0x3C];
    void* field_3C;
};

void* fn_27_24E7D8(void* a, int b) {
    if (a != 0) {
        ((Class24E7D8*)a)->field_3C = &lbl_27_data_4F588;
        if (g_cmAIController) {
            g_cmAIController->flags |= 0x10;
        }
        fn_27_24DFF4(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
}
