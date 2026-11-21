#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_400[];
extern "C" void fn_800434D0(float*, float, float, float, float, float, float);
extern "C" void fn_801340C0(void*, float*);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
};

struct Modules {
    char pad[12];
    Object_vptr_0* posture;
};

class soModuleAccesser {
public:
    char pad[0xd8];
    Modules* modules;
};

struct Collision {
    char pad[8];
    union {
        unsigned int flags;
        struct {
            unsigned int : 24;
            unsigned int m_flag : 8;
        };
    };
};

class soGroundShapeImpl {
public:
    void updateRhombus(soModuleAccesser* acc);

    char _0[4];
    Collision* m_collision;
    float m_x;
    float m_y;
    float m_offX;
    float m_offY;
    float m_width;
    float m_height;
    float m_up;
    float m_down;
    float m_halfWidth;
    char _2C[10];
    unsigned short m_flags;
    unsigned int m_state;
};

void soGroundShapeImpl::updateRhombus(soModuleAccesser* acc) {
    const float* rodata = lbl_27_rodata_400;
    Vec3f pos = acc->modules->posture->slot4();
    float lr = acc->modules->posture->slot9();
    float scale = acc->modules->posture->slot22();
    float offY = m_offY;
    float offX = m_offX;
    Vec2f offset;
    offset.m_y = scale * offY;
    offset.m_x = scale * offX;
    unsigned short flags = m_flags;
    Collision* collision = m_collision;
    float up, down, right, left;

    if (!(flags & 0x20)) {
        up = m_up;
        if (!(flags & 2)) {
            up *= scale;
        }
    } else {
        up = rodata[1];
    }

    if (!(flags & 0x40)) {
        down = m_down;
        if (!(flags & 2)) {
            down *= scale;
        }
    } else {
        down = rodata[6];
    }

    if (!(flags & 8)) {
        left = -m_halfWidth;
        if (!(flags & 2)) {
            left *= scale;
        }
    } else {
        left = rodata[6];
    }

    if (!(flags & 0x10)) {
        right = m_halfWidth;
        if (!(flags & 2)) {
            right *= scale;
        }
    } else {
        right = rodata[1];
    }

    float shape[14];
    fn_800434D0(
        shape,
        offset.m_y + (up + pos.m_y),
        offset.m_y + (down + pos.m_y),
        offset.m_x + (left + pos.m_x),
        offset.m_x + (right + pos.m_x),
        pos.m_x + offset.m_x,
        offset.m_y + (pos.m_y + rodata[4] * (up + down))
    );

    if (!((m_state >> 3) & 1)) {
        float oy = m_y;
        float ox = m_x;
        m_state |= 8;
        float old[14];
        fn_800434D0(
            old,
            rodata[11] + oy,
            oy - rodata[11],
            ox - rodata[11],
            rodata[11] + ox,
            ox,
            oy
        );
        fn_801340C0(m_collision, old);
        fn_801340C0(m_collision, shape);
    } else {
        fn_801340C0(m_collision, shape);
    }

    m_x = shape[0];
    m_y = shape[1];
    float h = shape[3] - shape[5];
    float w = shape[8] - shape[6];
    m_height = h;
    m_width = w;

    if (lr > rodata[0]) {
        collision->m_flag = 1;
    } else if (lr < rodata[0]) {
        collision->flags &= ~0xff;
    } else {
        collision->m_flag = 3;
    }
}
