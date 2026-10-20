#pragma force_active on
extern "C" {
void* fn_27_1F2D0C(char* fighterId);
void* fn_27_1F1F58(char* fighterId);
void* fn_27_1F218C(int param);
}

extern "C" float fn_27_21F1BC(char* fighterId) {
    void* p = fn_27_1F2D0C(fighterId);
    float result;
    if (p) {
        float mult = *(float*)((char*)fn_27_1F1F58(fighterId) + 0x68);
        int id = *(int*)((char*)fn_27_1F1F58(fighterId) + 0xAC);
        float val = *(float*)((char*)fn_27_1F218C(id) + 8);
        result = val * mult;
    } else {
        float mult = *(float*)((char*)fn_27_1F1F58(fighterId) + 0x68);
        float val = *(float*)((char*)fn_27_1F218C(0) + 8);
        result = val * mult;
    }
    return result;
}
