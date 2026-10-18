#include <mt/mt_vector.h>
#pragma force_active on

class CameraThing {
public:
    virtual void pad0() = 0;
    virtual void pad1() = 0;
    virtual void pad2() = 0;
    virtual void pad3() = 0;
    virtual Vec3f getPair() = 0;
    virtual void setPair(Vec3f*) = 0;
};

class CameraController {
    char _[0x158];

public:
    float unk158;
    float unk15C;
    float unk160;
    float unk164;

    static CameraController* getInstance();
};

struct CameraHolder {
    char _[0xC];
    CameraThing* camera;
};

struct FighterArg {
    char _[0xD8];
    CameraHolder* holder;
};

extern "C" void fn_95_14168(void*, FighterArg* fighter) {
    CameraController* controller = CameraController::getInstance();
    Vec3f pair = fighter->holder->camera->getPair();

    if (pair.m_x < controller->unk158) {
        pair.m_x = controller->unk158;
    } else if (pair.m_x > controller->unk15C) {
        pair.m_x = controller->unk15C;
    }

    if (pair.m_y < controller->unk164) {
        pair.m_y = controller->unk164;
    } else if (pair.m_y > controller->unk160) {
        pair.m_y = controller->unk160;
    }

    fighter->holder->camera->setPair(&pair);
}
