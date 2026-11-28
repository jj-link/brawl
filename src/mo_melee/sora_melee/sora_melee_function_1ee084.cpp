#include <ai/ai_mgr.h>
#include <mt/mt_vector.h>
#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma fp_contract off
#pragma pool_data on
#pragma pool_fp_consts on

// Candidate matches 91.9% of the original instructions; it is not exact.

extern "C" {
extern const float lbl_27_rodata_2B80[];
void* fn_27_21C8D4(void* table, int index, void* manager);
void fn_27_20B0D0(void* entry, void* data, unsigned char* id);
float fn_27_21F244(signed char* fighterId);
float fn_27_21F434(void* parameters, void* state);
float fn_27_21F484(void* parameters, void* state);
}

struct AiTargetEntry {
    char pad00[0x18];
    Vec2f seg0;
    Vec2f seg1;
    char pad28[0x3e - 0x28];
    unsigned char playerMask;
    char pad3f;
    unsigned int flags;
    char pad44[0x4c - 0x44];
};

struct AiTargetList {
    char pad00[0x34c];
    AiTargetEntry* entries;
    unsigned short count;
};

struct AiFighterState {
    char pad00[0x50];
    unsigned int unk50;
    char pad54[0x5c - 0x54];
    Vec2f vector5C;
    char pad64[0x80 - 0x64];
    float unk80;
    char pad84[0xbc - 0x84];
    void* unkBC;
    char padC0[0xc8 - 0xc0];
    int unkC8;
    int unkCC;
    char padD0[0x1ba - 0xd0];
    unsigned char unk1BA;
    char pad1bb[0x1c4 - 0x1bb];
};

struct AiInputSelf {
    char pad00[0x42];
    signed char unk42;
    char pad43[0x90 - 0x43];
    char parameters[0x10];
};

struct AiMgrView {
    char pad00[0xa4];
    unsigned char unkA4;
    char padA5[0xf8 - 0xa5];
    char* unkF8;
    char padFC[0x100 - 0xfc];
    void* unk100;
};

extern "C" AiTargetEntry* fn_27_1EE084(
    AiTargetList* list, AiInputSelf* self, AiFighterState* state)
{
    float float0 = -99999.9f;
    float float1 = 99999.9f;
    float float2 = 0.0f;
    float float3 = -40.0f;
    float float4 = 5.0f;
    double conversionBias = 4503601774854144.0;
    float float8 = 50.0f;
    float float9 = 0.01f;
    float float10 = 12.0f;
    float float11 = 45.0f;
    float float12 = 55.0f;
    float float13 = 30.0f;
    float float14 = 10.0f;
    float float15 = 2.0f;
    float float16 = 80.0f;
    float float17 = -100.0f;
    float float18 = 38.0f;
    float float19 = 40.0f;
    float float20 = 0.0001f;
    float float21 = 1.0f;
    float float22 = 20.0f;
    float float23 = 28.5f;
    float float24 = 8.5f;
    float float25 = 11.0f;
    float float26 = -0.1f;
    float float27 = 0.1f;
    float float28 = 0.000000000000000000000000000000000000011754944f;
    float float29 = 75.0f;
    float float30 = 120.0f;
    float float31 = 60.0f;
    float float32 = 15.0f;
    float float33 = 0.5f;
    float float34 = -55.0f;
    float float35 = -14.0f;
    float float36 = 14.0f;
    float float37 = -70.0f;
    float float38 = 70.0f;
    float float39 = -50.0f;
    float float40 = 22.0f;
    float float41 = 35.0f;
    float float42 = -39.0f;
    float float43 = 39.0f;
    float float44 = -54.0f;
    float float45 = 54.0f;
    float float46 = -1.0f;
    float float47 = 200.0f;
    float float48 = 400.0f;
    float float49 = 150.0f;
    float float50 = 160.0f;
    float float51 = 1.5f;
    float float52 = -88.0f;
    float float53 = -90.0f;
    float float54 = 44.0f;
    float float55 = 46.0f;
    float float56 = 10000.0f;
    float float57 = -74.0f;
    float float58 = -76.0f;
    float float59 = 85.0f;
    float float60 = -85.0f;
    float float61 = 0.0000001f;
    float float62 = 0.3f;
    float float63 = -0.3f;
    float float64 = 9999980000.0f;
    float float65 = 0.00001f;
    float float66 = -999999.9f;
    float float67 = 1.2f;
    float float68 = -0.5f;
    float float69 = 100.0f;
    float float70 = 2.5f;
    float float71 = 225.0f;
    float float72 = 25.0f;
    float float73 = 36.0f;
    float float74 = -0.8f;
    float float75 = 1000000.0f;
    float float76 = -10000000.0f;
    float float77 = 0.8f;
    float float78 = -30.0f;
    float float79 = -300.0f;
    float float80 = -600.0f;
    float float81 = -400.0f;
    AiFighterState* f;
    int j;
    AiTargetEntry* best = 0;
    int i;
    float sq;
    float bestScore = -10000000.0f;
    float ratio;
    float score;
    AiTargetEntry* entry = list->entries;
    float dist = fn_27_21F434(&self->parameters, state);
    ratio = fn_27_21F484(&self->parameters, state) / dist;

    for (i = 0; i < list->count; ++i, ++entry) {
        score = 0.0f;
        if ((entry->flags & 0x2) && !(entry->flags & 0x10000)) {
            Vec2f seg;
            if (state->vector5C.m_x < entry->seg0.m_x) {
                seg = entry->seg0;
            } else if (state->vector5C.m_x > entry->seg1.m_x) {
                seg = entry->seg1;
            } else {
                const Vec2f* p;
                if (state->unk80 < 0.0f)
                    p = &entry->seg0;
                else
                    p = &entry->seg1;
                seg.m_x = p->m_x;
                seg.m_y = p->m_y;
            }
            if (state->vector5C.m_y < seg.m_y)
                continue;

            Vec2f diff(seg.m_x - state->vector5C.m_x,
                       seg.m_y - state->vector5C.m_y);
            if ((state->vector5C.m_x < entry->seg0.m_x ||
                 state->vector5C.m_x > entry->seg1.m_x) &&
                nw4r::ut::Abs(diff.m_x) >
                    ratio * nw4r::ut::Abs(diff.m_y))
                continue;

            sq = diff.m_x * diff.m_x + diff.m_y * diff.m_y;
            float len;
            if (static_cast<float>(
                    static_cast<double>(nw4r::ut::Abs(sq))) <=
                0.000000000000000000000000000000000000011754944f)
                len = 0.0f;
            else
                len = sq * rsqrtf(sq);

            if (len < 200.0f)
                score += 0.5f * (200.0f - len);
            if (diff.m_x * state->unk80 > 0.0f)
                score += 30.0f;

            int count = 0;
            for (j = 0; j < 7; ++j) {
                int idSlot;
                *reinterpret_cast<unsigned char*>(&idSlot) = j;
                signed char c = *reinterpret_cast<signed char*>(&idSlot);
                if (c >= 0) {
                    bool fighter = false;
                    if (c >= 0 && c < 14) {
                        fighter = true;
                    }
                    if (fighter) {
                        f = reinterpret_cast<AiFighterState*>(
                            reinterpret_cast<AiMgrView*>(g_aiMgr)->unkF8 + *reinterpret_cast<signed char*>(&idSlot) * 0x1c4);
                    } else {
                        void* table = reinterpret_cast<AiMgrView*>(g_aiMgr)->unk100;
                        void* data = fn_27_21C8D4(table, *reinterpret_cast<signed char*>(&idSlot) - 14, g_aiMgr);
                        f = reinterpret_cast<AiFighterState*>(
                            reinterpret_cast<AiMgrView*>(g_aiMgr)->unkF8 + 0x18B8);
                        if ((signed char)reinterpret_cast<AiMgrView*>(g_aiMgr)->unkA4 !=
                                 *reinterpret_cast<signed char*>(&idSlot) - 14 && data != 0) {
                            fn_27_20B0D0(f, data, reinterpret_cast<unsigned char*>(&idSlot));
                            reinterpret_cast<AiMgrView*>(g_aiMgr)->unkA4 = (*reinterpret_cast<unsigned char*>(&idSlot)) - 14;
                        }
                    }
                } else {
                    f = reinterpret_cast<AiFighterState*>(
                        reinterpret_cast<AiMgrView*>(g_aiMgr)->unkF8 + 0x18B8);
                }
                if (j != self->unk42 &&
                    !(f->unk50 & 0x8000) && f->unk1BA != 0xF &&
                    f->unkCC != state->unkCC) {
                    ++count;
                }
            }

            if (count > 0) {
                for (int j = 0; j < 7; ++j) {
                    int idSlot;
                    *reinterpret_cast<unsigned char*>(&idSlot) = j;
                    signed char c = *reinterpret_cast<signed char*>(&idSlot);
                    AiFighterState* f;
                    if (c >= 0) {
                        bool fighter = false;
                        if (c >= 0 && c < 14) {
                            fighter = true;
                        }
                        if (fighter) {
                            f = reinterpret_cast<AiFighterState*>(
                                reinterpret_cast<AiMgrView*>(g_aiMgr)->unkF8 + *reinterpret_cast<signed char*>(&idSlot) * 0x1c4);
                        } else {
                            void* table = reinterpret_cast<AiMgrView*>(g_aiMgr)->unk100;
                            void* data = fn_27_21C8D4(table, *reinterpret_cast<signed char*>(&idSlot) - 14, g_aiMgr);
                            f = reinterpret_cast<AiFighterState*>(
                                reinterpret_cast<AiMgrView*>(g_aiMgr)->unkF8 + 0x18B8);
                            if ((signed char)reinterpret_cast<AiMgrView*>(g_aiMgr)->unkA4 !=
                                     *reinterpret_cast<signed char*>(&idSlot) - 14 && data != 0) {
                                fn_27_20B0D0(f, data, reinterpret_cast<unsigned char*>(&idSlot));
                                reinterpret_cast<AiMgrView*>(g_aiMgr)->unkA4 = (*reinterpret_cast<unsigned char*>(&idSlot)) - 14;
                            }
                        }
                    } else {
                        f = reinterpret_cast<AiFighterState*>(
                            reinterpret_cast<AiMgrView*>(g_aiMgr)->unkF8 + 0x18B8);
                    }
                    if (j == self->unk42 || (f->unk50 & 0x8000) ||
                        f->unk1BA == 0xF || f->unkCC == state->unkCC)
                        continue;

                    Vec2f cand;
                    float speed;
                    float f4;
                    if (f->vector5C.m_x < entry->seg0.m_x) {
                        cand = entry->seg1;
                    } else if (f->vector5C.m_x > entry->seg1.m_x) {
                        cand = entry->seg0;
                    } else {
                        f4 = 0.5f * (entry->seg0.m_x + entry->seg1.m_x);
                        f4 -= f->vector5C.m_x;
                        const Vec2f* p;
                        if (nw4r::ut::Abs(f->unk80) < 0.8f ||
                            nw4r::ut::Abs(f4) > 40.0f) {
                            if (f4 < 0.0f)
                                p = &entry->seg0;
                            else
                                p = &entry->seg1;
                            cand.m_x = p->m_x;
                            if (f4 < 0.0f)
                                p = &entry->seg0;
                            else
                                p = &entry->seg1;
                            cand.m_y = p->m_y;
                        } else {
                            if (f->unk80 > 0.0f)
                                p = &entry->seg0;
                            else
                                p = &entry->seg1;
                            cand.m_x = p->m_x;
                            cand.m_y = p->m_y;
                        }
                    }

                    Vec2f d;
                    d.m_x = cand.m_x - f->vector5C.m_x;
                    d.m_y = cand.m_y - f->vector5C.m_y;
                    float sq1 = d.m_x * d.m_x + d.m_y * d.m_y;
                    float L;
                    if (static_cast<float>(
                            static_cast<double>(nw4r::ut::Abs(sq1))) <=
                        0.000000000000000000000000000000000000011754944f)
                        L = 0.0f;
                    else
                        L = sq1 * rsqrtf(sq1);

                    float t = 0.0f;
                    t += L < 200.0f ? L : 200.0f;
                    float u;
                    if (nw4r::ut::Abs(d.m_x) < 200.0f)
                        u = 0.5f * nw4r::ut::Abs(d.m_x);
                    else
                        u = 100.0f;
                    t = t + u;
                    score += 1.5f * t;
                    if (d.m_x * f->unk80 > 0.0f)
                        score += -30.0f;
                    if (entry == f->unkBC)
                        score += -100.0f;

                    float dxa = cand.m_x - state->vector5C.m_x;
                    if (d.m_x * dxa > 0.0f &&
                        nw4r::ut::Abs(dxa) > nw4r::ut::Abs(d.m_x)) {
                        signed char sp8 = j;
                        float F = fn_27_21F244(&sp8);
                        Vec2f e1(
                            f->vector5C.m_x - state->vector5C.m_x,
                            (f->vector5C.m_y + F) - state->vector5C.m_y);
                        if (d.m_x > ratio * nw4r::ut::Abs(d.m_y))
                            score += -300.0f;
                    }

                    Vec2f e(cand.m_x - state->vector5C.m_x,
                            cand.m_y - state->vector5C.m_y);
                    d.m_x = e.m_x;
                    d.m_y = e.m_y;
                    float sq2 = d.m_x * d.m_x + d.m_y * d.m_y;
                    float L2;
                    if (static_cast<float>(
                            static_cast<double>(nw4r::ut::Abs(sq2))) <=
                        0.000000000000000000000000000000000000011754944f)
                        L2 = 0.0f;
                    else
                        L2 = sq2 * rsqrtf(sq2);
                    if (L2 < 200.0f)
                        score += 0.5f * (200.0f - L2);
                    if (d.m_x * state->unk80 > 0.0f)
                        score += 30.0f;
                }
            }

            const unsigned int flags = entry->flags;
            if (flags & 0x1000) {
                score += -600.0f * (float)(count + 1);
            } else {
                int c8 = state->unkC8;
                bool applies;
                if ((flags & 0x800) &&
                    (c8 < 0 || c8 >= 8 ||
                     (entry->playerMask & (1 << c8))))
                    applies = true;
                else
                    applies = false;
                if (applies)
                    score += -400.0f * (float)(count + 1);
            }
            if (bestScore < score) {
                bestScore = score;
                best = entry;
            }
        }
    }
    return best;
}
