#pragma force_active on
extern "C" const unsigned char lbl_80407AAC[];
struct muMenu {
    static float getStageFrameNo(int, int, int);
};
float muMenu::getStageFrameNo(int index, int, int) {
    const unsigned char* p = lbl_80407AAC;
    return (float)*(p + index * 4 + 2);
}
