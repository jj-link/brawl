#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern "C" void* getInstance__6emInfoFv();
extern "C" s32 getNodeNum__6emInfoF6emKind(void*, int);
extern "C" void fn_41_637C(void*, u32);

struct Enemy {
    char pad[0xac];
    int kind;
};

extern "C" void fn_41_6570(Enemy* enemy) {
    s32 num = getNodeNum__6emInfoF6emKind(getInstance__6emInfoFv(),
                                          enemy->kind);
    int i = 0;
    while (i < num) {
        fn_41_637C(enemy, i);
        i++;
    }
}
