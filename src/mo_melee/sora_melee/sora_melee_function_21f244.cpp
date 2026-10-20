#pragma force_active on
extern "C" {
void* fn_27_1F2D0C(char* fighterId);
void* fn_27_1F218C(int arg);
void* fn_27_1F1F58(char* fighterId);
}

struct AiState {
    char pad[0x6C];
    float unk6C;
    char pad70[0x3C];
    int unkAC;
};

extern "C" {
float fn_27_21F244(char* fighterId) {
    if (fn_27_1F2D0C(fighterId)) {
        AiState* s = (AiState*)fn_27_1F1F58(fighterId);
        float m = s->unk6C;
        AiState* s2 = (AiState*)fn_27_1F1F58(fighterId);
        float v = *(float*)((char*)fn_27_1F218C(s2->unkAC) + 0xC);
        return v * m;
    } else {
        float m = ((AiState*)fn_27_1F1F58(fighterId))->unk6C;
        float v = *(float*)((char*)fn_27_1F218C(0) + 0xC);
        return v * m;
    }
}
}
