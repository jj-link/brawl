#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const char lbl_27_data_57510[];

class Ground {
public:
    void getNodePosition(Vec3f* pos, unsigned long node, const char* name);
};

class grGimmickSpring : public Ground {
public:
    void getTopNode(Vec3f* pos);
};

void grGimmickSpring::getTopNode(Vec3f* pos) {
    return getNodePosition(pos, 0, lbl_27_data_57510);
}
