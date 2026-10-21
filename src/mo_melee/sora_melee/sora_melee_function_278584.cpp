#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Vec3f {
    float x;
    float y;
    float z;
};

struct grMadeinAttack {
    float unk0;
    Vec3f vec;
    char pad[0x1c];
};

class grMadein {
public:
    void setAttack(float, Vec3f*);

    char m_pad0[0x70];
    int m_heapType;
    char m_pad1[0xe8];
    grMadeinAttack* m_attack;
    char m_pad2[0xc];
    unsigned char m_flags;
};

void grMadein::setAttack(float value, Vec3f* vec) {
    if (m_attack == 0) {
        m_attack = (grMadeinAttack*)__nw__FUlQ25Heaps8HeapType(0x2c, m_heapType);
    }
    m_flags |= 0x40;
    grMadeinAttack* attack = m_attack;
    attack->vec.x = vec->x;
    attack->vec.y = vec->y;
    attack->vec.z = vec->z;
    m_attack->unk0 = value;
}
