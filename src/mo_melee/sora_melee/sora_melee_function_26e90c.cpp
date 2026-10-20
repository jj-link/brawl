#pragma force_active on
class grGimmick {
public:
    void update(float frame);
};

class grGimmickMotionPath : public grGimmick {
public:
    void update(float deltaFrame);
};

void grGimmickMotionPath::update(float deltaFrame) {
    grGimmick::update(*(float*)((char*)this + 0x15c));
    switch (*(signed char*)((char*)this + 0x14c)) {
    case 1:
        *(float*)((char*)this + 0x158) = *(float*)((char*)this + 0x158) * *(float*)((char*)this + 0x168);
        break;
    }
}
