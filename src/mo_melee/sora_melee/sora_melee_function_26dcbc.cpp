#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct grGimmickInner {
    char pad[0x20];
    float sx;
    float sy;
    float sz;
};

class grGimmick {
public:
    void setScale(Vec3f* scale);

    char pad[0xd4];
    grGimmickInner* m_inner;
};

void grGimmick::setScale(Vec3f* scale) {
    grGimmickInner* inner = m_inner;
    if (inner == 0) {
        return;
    }
    float x = scale->x;
    float y = scale->y;
    inner->sx = x;
    float z = scale->z;
    inner->sy = y;
    inner->sz = z;
}
