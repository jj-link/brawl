#pragma force_active on
class grGimmick {
public:
    void setPos(float x, float y, float z);

private:
    char m_pad[0xd4];
    float* m_data;
};

void grGimmick::setPos(float x, float y, float z) {
    float* p = m_data;
    if (p == 0) {
        return;
    }
    p[2] = x;
    p[3] = y;
    p[4] = z;
}
