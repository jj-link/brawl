#pragma force_active on
typedef unsigned int u32;
extern "C" int __cntlzw(unsigned int);
#pragma fp_contract on

struct Vtx { float x, y, z, w; };
struct Shape { char pad[0x40]; Vtx* verts; int count; };
struct Seg { float s[3]; float pad0; float e[3]; float pad1; };
struct TimerEntry { const char* name; u32 time; u32 unused; };
struct Timer { u32 unused0; TimerEntry* current; u32 unused8; TimerEntry* end; u32 unused10[2]; };
struct Out { float x, y, z, w; float t; float unk14; int arr[8]; int n; };

extern Timer lbl_80532448;
extern char lbl_80410618[];
extern const float lbl_805A40B8;
extern const float lbl_805A40C0;

inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    TimerEntry* end = timer->end;
    TimerEntry* entry = timer->current;
    signed char r = (signed char)(((unsigned int)end << __cntlzw((unsigned int)end ^ (unsigned int)entry)) >> 31);
    if (((unsigned int)(-r | r) >> 31) != 0) {
        entry->name = lbl_80410618 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}

extern "C" int fn_802D211C(Shape* shape, Seg* seg, Out* out) {
    __declspec(align(16)) Vtx hit;
    float vw, vz, vx, vy;
    float maxEnter;
    float minExit;
    record(0);
    maxEnter = lbl_805A40C0;
    minExit = out->t;

    for (int i = shape->count - 1; i >= 0; i--) {
        Vtx* v = &shape->verts[i];
        vx = v->x; vy = v->y; vz = v->z;
        float pA = vz * seg->s[2] + (vx * seg->s[0] + vy * seg->s[1]);
        float pB = vz * seg->e[2] + (vx * seg->e[0] + vy * seg->e[1]);
        vw = v->w;
        float dA = vw + pA;
        float dB = vw + pB;
        if (dA >= lbl_805A40B8) {
            if (dB >= lbl_805A40B8) {
                record(0xF);
                return 0;
            }
            float t = dA / (dA - dB);
            if (maxEnter <= t) {
                maxEnter = t;
                hit.x = vx;
                hit.y = vy;
                hit.z = vz;
                hit.w = vw;
            }
        } else {
            if (!(dB >= lbl_805A40B8)) continue;
            float t = dA / (dA - dB);
            minExit = (minExit < t) ? minExit : t;
        }
        if (minExit < maxEnter) {
            record(0xF);
            return 0;
        }
    }

    if (maxEnter < lbl_805A40B8) {
        record(0xF);
        return 0;
    }
    out->x = hit.x;
    out->y = hit.y;
    out->z = hit.z;
    out->w = hit.w;
    out->t = maxEnter;
    out->arr[out->n] = -1;
    record(0xF);
    return 0x01000000;
}
