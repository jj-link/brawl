#pragma force_active on
extern "C" {
extern const char lbl_41_data_B460[];

void Report__14wnemCommonProcFPCce(const char*, ...);
void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
void setProcFnc_LifeZero__10wnemSimpleFl(void*, long);
void* getInstance__9itManagerFv();
int isCompItemKindArchive__9itManagerF6itKindUlb(void*, int, unsigned long, bool);
void preloadItemKindArchive__9itManagerF6itKindUlQ29itArchive4Typeb(
    void*, int, unsigned long, int, bool);
}

struct Enemy {
    char pad[0x2214];
    bool entering;
    char pad2215[0x1F];
    int* parameters;
};

extern "C" void fn_41_3DEF8(Enemy* enemy) {
    bool entering = enemy->entering;
    enemy->entering = false;
    if (entering) {
        Report__14wnemCommonProcFPCce(lbl_41_data_B460);
        setProcFnc_TouchGround__10wnemSimpleFl(enemy, 10);
        setProcFnc_LifeZero__10wnemSimpleFl(enemy, 50);

        int* parameters = 0;
        if (enemy->parameters) {
            parameters = enemy->parameters;
        }
        if (parameters) {
            int kind = parameters[0];
            if (kind != -1) {
                if (!isCompItemKindArchive__9itManagerF6itKindUlb(
                        getInstance__9itManagerFv(), kind, 0, true)) {
                    preloadItemKindArchive__9itManagerF6itKindUlQ29itArchive4Typeb(
                        getInstance__9itManagerFv(), kind, 0, 0, true);
                }
            }
        }
    }
}
