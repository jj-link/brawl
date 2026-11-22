#include <types.h>
#include <gf/gf_pad_system.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

inline s8 absStick(u8 x) {
    s8 v = x;
    return v < 0 ? -v : v;
}
inline u8 maxAnalog(u8 x, u8 y) {
    return y > x ? y : x;
}

void gfPadSystem::merge(gfPadStatus* src, int numPads, u32 mask, gfPadStatus* dest)
{
    u8 count = 0;
    u32 orA = 0, orB = 0, orE = 0, orD = 0, orC = 0;
    u8 bestX = 0, bestY = 0, bestSX = 0, bestSY = 0;
    u8 maxL = 0, maxR = 0, maxA = 0, maxB = 0;
    u32 i;

    for (i = 0; i < (u32)numPads; i++) {
        if (((mask >> i) & 1) && src->m_error == 0) {
            orA |= src->m_buttonsCurrentFrame2.bits;
            orB |= src->m_buttonsPressedThisFrame.bits;
            orE |= src->m_buttonsReleasedThisFrame.bits;
            orD |= src->m_buttonsHeld.bits;
            orC |= src->m_buttonsPressedThisFrame2.bits;
            { u8 v = src->m_stickX; if (absStick(bestX) < absStick(v)) bestX = v; }
            { u8 v = src->m_stickY; if (absStick(bestY) < absStick(v)) bestY = v; }
            { u8 v = src->m_subStickX; if (absStick(bestSX) < absStick(v)) bestSX = v; }
            { u8 v = src->m_subStickY; if (absStick(bestSY) < absStick(v)) bestSY = v; }
            maxL = maxAnalog(src->m_lTriggerAnalog, maxL);
            maxR = maxAnalog(src->m_rTriggerAnalog, maxR);
            maxA = maxAnalog(src->_0x36, maxA);
            maxB = maxAnalog(src->_0x37, maxB);
            count++;
        }
        src++;
    }

    dest->m_buttonsCurrentFrame2.bits = orA;
    dest->m_buttonsCurrentFrame.bits = orA;
    dest->m_buttonsHeld.bits = orD;
    dest->m_buttonsPressedThisFrame.bits = orB;
    dest->m_buttonsReleasedThisFrame.bits = orE;
    dest->m_buttonsPressedThisFrame2.bits = orC;
    dest->m_stickX = bestX;
    dest->m_stickY = bestY;
    dest->m_subStickX = bestSX;
    dest->m_subStickY = bestSY;
    dest->m_lTriggerAnalog = maxL;
    dest->m_rTriggerAnalog = maxR;
    dest->_0x36 = maxA;
    dest->_0x37 = maxB;
    if (count != 0) {
        dest->m_error = (gfPadError::PadError)0;
    } else {
        dest->m_error = (gfPadError::PadError)-2;
    }
}
