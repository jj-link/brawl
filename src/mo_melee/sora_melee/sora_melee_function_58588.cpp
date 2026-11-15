#pragma force_active on
#pragma fp_contract on

struct ClatterData {
    float f0;
    float f1;
    float f2;
    unsigned char b_c;
    unsigned char b_d;
    unsigned char b_e;
    unsigned char b_f;
    unsigned char b_10;
};

class ClatterContainer {
public:
    virtual void method0();
    virtual ClatterData* get(unsigned long index);
};

struct Self {
    char pad[0x10];
    ClatterContainer* m_container;
};

extern "C" void startClatter__22soControllerModuleImplFfffUcUcUlb(
    Self* self,
    float f0, float f1, float f2,
    unsigned char a3, unsigned char a4,
    unsigned long index, bool flag)
{
    if (flag == 1 || (signed char)a4 == -1)
        goto reset;
    {
        unsigned char stored = self->m_container->get(index)->b_10;
        if ((signed char)a4 == (signed char)stored)
            goto add;
    }
reset:
    self->m_container->get(index)->f0 = f0;
    goto done;
add:
    self->m_container->get(index)->f0 += f0;
done:;

    self->m_container->get(index)->f1 = f1;
    self->m_container->get(index)->f2 = f2;

    ClatterData* p1 = self->m_container->get(index);
    ClatterData* p2 = self->m_container->get(index);
    p1->b_d = 0;
    p2->b_d = 0;

    self->m_container->get(index)->b_f = a3;
    self->m_container->get(index)->b_e = 0;
    self->m_container->get(index)->b_10 = a4;
}
