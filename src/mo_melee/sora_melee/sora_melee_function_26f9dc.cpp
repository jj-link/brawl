#pragma force_active on
class grGimmick {
public:
    void update(float deltaFrame);
    void updateCallback(unsigned long arg);
};

class grGimmickLadder : public grGimmick {
public:
    void update(float deltaFrame);
};

void grGimmickLadder::update(float deltaFrame) {
    grGimmick::update(deltaFrame);
    updateCallback(0);
}
