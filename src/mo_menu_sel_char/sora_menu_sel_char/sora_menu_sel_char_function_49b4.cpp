#pragma force_active on
class muSelCharTask {
public:
    void dispHighScore(int a, int b, int c);
};

class GameGlobal;
extern GameGlobal* g_GameGlobal;

extern "C" {
int fn_10_C48C(void* a, int b);
void fn_10_FD00(void* a, int b);
int fn_10_B398(void* a, int b, int c, int d, int e);
extern const unsigned char lbl_10_rodata_128[];
}

extern "C" void fn_10_49B4(muSelCharTask* self) {
    void* scd = *(void**)((char*)g_GameGlobal + 0x10);
    unsigned char val = *(unsigned char*)((char*)scd + 4);
    const unsigned char* ptr;
    int idx = fn_10_C48C(self, val) * 6;
    ptr = lbl_10_rodata_128;
    fn_10_FD00(self, 6);
    int i;
    int total;
    total = 0;
    i = 0;
    while (i < 0x23) {
        int x = *(int*)((char*)self + 0x5e0);
        total += fn_10_B398(self, i, x, 0, 0);
        i++;
    }
    self->dispHighScore(3, total, ptr[idx]);
}
