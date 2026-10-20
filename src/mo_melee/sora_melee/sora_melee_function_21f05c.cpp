#pragma force_active on
extern "C" {
void* fn_27_1F2D0C(char* fighterId);
void* fn_27_1F218C(int arg);
void* fn_27_1F1F58(char* fighterId);
}

struct AiState {
    char pad[0xAC];
    int unkAC;
};

extern "C" {
float fn_27_21F05C(char* fighterId) {
    void* p = fn_27_1F2D0C(fighterId);
    float result;
    if (p) {
        AiState* state = (AiState*)fn_27_1F1F58(fighterId);
        result = *(float*)fn_27_1F218C(state->unkAC);
    } else {
        result = *(float*)fn_27_1F218C(0);
    }
    return result;
}
}
