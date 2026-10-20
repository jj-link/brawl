#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_33D8;
extern void* g_cmAIController;
void fn_800A22EC(void* controller);
void fn_800A22FC(void* controller, void* vec);
}

class Stage {
public:
    char pad_0000[0xEC];
    float m_ec;
    float m_f0;
    void setDevilScrool(float a, float b);
};

struct Vec2 {
    float x;
    float y;
};

void Stage::setDevilScrool(float a, float b) {
    if (lbl_27_rodata_33D8 == a && lbl_27_rodata_33D8 == b) {
        m_ec = lbl_27_rodata_33D8;
        m_f0 = lbl_27_rodata_33D8;
        fn_800A22EC(g_cmAIController);
    } else {
        m_ec = m_ec + a;
        m_f0 = m_f0 + b;
        Vec2 v;
        v.x = a;
        v.y = b;
        fn_800A22FC(g_cmAIController, &v);
    }
}
