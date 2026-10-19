#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class Stage {
public:
    void updateStagePositions();
    void getFighterReStartPos(Vec3f* out, int arg);
    char pad[0x52c];
    int m_state;
};

extern "C" void fn_40_7D44(Stage* self) {
    self->updateStagePositions();
    switch (self->m_state) {
    case 0:
    case 1:
        break;
    case 2:
        self->getFighterReStartPos((Vec3f*)((char*)self + 0x56c), 0);
        break;
    }
}
