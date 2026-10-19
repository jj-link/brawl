#pragma force_active on
class Rect2D;

class stPositions {
public:
    void getDeadRange(Rect2D* rect);
};

class CameraController {
public:
    static CameraController* getInstance();
};

extern "C" void fn_8009CF04(CameraController* cam, Rect2D* rect);

class Stage {
public:
    void processFixCamera();

private:
    unsigned char m_pad0[0x58];
    unsigned char m_rect[0x38];
    unsigned char m_pad1[0x90 - 0x58 - 0x38];
    stPositions* m_positions;
};

void Stage::processFixCamera() {
    if (m_positions != 0) {
        m_positions->getDeadRange((Rect2D*)m_rect);
        fn_8009CF04(CameraController::getInstance(), (Rect2D*)m_rect);
    }
}
