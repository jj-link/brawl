#pragma force_active on

#include <types.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>
#include <gr/collision/gr_collision_line.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_vector.h>
#include <mt/mt_common.h>
#include <nw4r/ut/ut_algorithm.h>

extern const float lbl_805A2928;
extern const float lbl_805A292C;
extern const float lbl_805A2930;

extern "C" grCollisionJoint* getJoint__11grCollisionFUs(grCollision*, u32);
extern "C" grCollisionLine* getLine__16grCollisionJointFUs(grCollisionJoint*, u32);

static inline float vectorLengthSq(const Vec2f& a, const Vec2f& b) {
    return (a - b).lengthSq();
}

extern "C" void fn_801127D0(void* self) {
    grCollisionJoint* joint;
    grCollision* coll;
    u8* base = (u8*)self;
    float minY = lbl_805A2928;
    float maxY = lbl_805A2928;
    float minX = lbl_805A2928;
    float maxX = lbl_805A2928;
    bool first = true;

    nw4r::ut::LinkList<u8, 48>& list =
        *(nw4r::ut::LinkList<u8, 48>*)&g_grCollisionList;
    nw4r::ut::LinkList<u8, 48>::Iterator it = list.GetBeginIter();

    for (; it != list.GetEndIter(); ++it) {
        u8* obj = &*it;
        u8 flags = obj[0x2C];

        if ((flags >> 7 & 1) && ((u32)(flags >> 1 & 1) != 1) &&
            (obj[0x2D] >> 6 & 1)) {
            coll = (grCollision*)obj;
            u16 jointLen = *(u16*)(obj + 0x06);

            for (u32 j = 0; j < jointLen; j++) {
                joint = getJoint__11grCollisionFUs(coll, j);

                if (joint->m_0x54_6) {
                    u16 lineLen = *(u16*)((u8*)joint + 0x02);

                    for (u32 k = 0; k < lineLen; k++) {
                        grCollisionLine* line = getLine__16grCollisionJointFUs(joint, k);

                        if (*((u8*)line + 0x0F) & 1) {
                            clSegment2D seg;
                            coll->getSegment(&seg, line);

                            float lengthSquared =
                                vectorLengthSq(seg.m_p1Pos, seg.m_p0Pos);
                            float length =
                                (float)(double)nw4r::ut::Abs(lengthSquared) <=
                                        lbl_805A292C
                                    ? lbl_805A2928
                                    : lengthSquared * rsqrtf(lengthSquared);

                            if (length > lbl_805A2930) {
                                register float y0, y1, a, b, x0, x1, c, d;
                                y1 = seg.m_p1Pos.m_y;
                                y0 = seg.m_p0Pos.m_y;
                                x1 = seg.m_p1Pos.m_x;
                                x0 = seg.m_p0Pos.m_x;

                                asm { ps_sub a, y0, y1 }
                                asm { ps_sub b, y0, y1 }
                                asm { ps_sub c, x0, x1 }
                                asm { ps_sub d, x0, x1 }
                                asm { ps_sel a, a, y1, y0 }
                                asm { ps_sel b, b, y0, y1 }
                                asm { ps_sel c, c, x1, x0 }
                                asm { ps_sel d, d, x0, x1 }

                                if (first) {
                                    minY = a;
                                    minX = c;
                                    maxY = b;
                                    maxX = d;
                                    first = false;
                                } else {
                                    register float e, f, g, h;
                                    register float my = minY;
                                    register float mx = minX;
                                    register float My = maxY;
                                    register float Mx = maxX;

                                    asm { ps_sub e, my, a }
                                    asm { ps_sub f, mx, c }
                                    asm { ps_sub g, My, b }
                                    asm { ps_sub h, Mx, d }
                                    asm { ps_sel e, e, a, my }
                                    asm { ps_sel f, f, c, mx }
                                    asm { ps_sel g, g, My, b }
                                    asm { ps_sel h, h, Mx, d }

                                    minY = e;
                                    minX = f;
                                    maxY = g;
                                    maxX = h;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    *(float*)(base + 0x58) = minX;
    *(float*)(base + 0x5C) = maxX;
    *(float*)(base + 0x64) = minY;
    *(float*)(base + 0x60) = maxY;
}
