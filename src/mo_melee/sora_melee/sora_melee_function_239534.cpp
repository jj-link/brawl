#pragma force_active on

struct cmAIController {
    unsigned char pad[0x94];
    unsigned char flags;
    unsigned char pad2[0xF3];
    float limit[4];
};

extern cmAIController* g_cmAIController;
extern const float lbl_27_rodata_3950;
extern const float lbl_27_rodata_3954;

class stMelee {
public:
    void resetCameraLimitRange();
};

void stMelee::resetCameraLimitRange() {
    cmAIController* ai = g_cmAIController;
    if (ai == 0)
        return;

    unsigned int flags = ai->flags;
    flags = flags & 0xFFFFFFFD;
    ai->flags = (unsigned char)flags;
    ai->limit[0] = lbl_27_rodata_3950;
    ai->limit[1] = lbl_27_rodata_3954;
    ai->limit[2] = lbl_27_rodata_3954;
    ai->limit[3] = lbl_27_rodata_3950;
}
