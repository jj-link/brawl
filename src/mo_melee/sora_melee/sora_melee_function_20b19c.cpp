#include <so/so_external_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

struct Line {
    char pad[0x14];
    float slope;
    char pad2[0x10];
    float height;
    char pad3[0x14];
    unsigned flags;
};

struct Self {
    char pad[0x50];
    unsigned flags;
    char pad2[8];
    Vec3f pos;
    char pad3[0x18];
    float a;
    float b;
    char pad4[0x18];
    float scale;
    char pad5[0x18];
    Line* line;
    unsigned char type;
};

struct Manager {
    char pad[0xac];
    Line fallback;
    char pad2[0x370 - 0xac - sizeof(Line)];
    int mode;
};

extern Manager* g_aiMgr;
extern const float lbl_27_rodata_2F68[];

extern "C" int fn_27_1ED8A4(
    Manager*, Vec3f*, Line**, Line**, int, float, float, float
);
extern "C" unsigned* fn_27_14D418(StageObject*, int);
extern "C" Line* fn_27_1EE8F4(Manager*, unsigned, unsigned, unsigned);

static inline void initPos(Vec3f* pos, float x, float y, float z) {
    pos->m_x = x;
    pos->m_y = y;
    pos->m_z = z;
}

extern "C" void fn_27_20B19C(Self* self, StageObject* obj) {
    const float* k = lbl_27_rodata_2F68;
    Manager* const mgr = g_aiMgr;
    float limit;
    Vec3f pos;
    Vec3f finalPos;

    switch (mgr->mode) {
    case 13:
    case 30:
        limit = k[24];
        break;
    case 8:
        limit = k[25];
        break;
    default:
        limit = k[26];
        break;
    }

    self->line = 0;
    if (obj) {
        soGroundModule* ground =
            soExternalValueAccesser::getModuleAccesser(obj)
                ->m_enumerationStart->m_groundModule;

        if (ground->isStCliff(0) || ground->isTouch(8, 0)) {
            initPos(&pos, self->pos.m_x, k[1] + self->pos.m_y, self->pos.m_z);

            if (ground->isStCliff(0)) {
                grCollStatus* status = ground->getCollStatus(0);
                Vec2f xy;
                if (status) {
                    Vec2f::copy(xy, *(Vec2f*)((char*)status + 0x34));
                    const Vec3f p(
                        xy.m_x + k[2] * self->scale,
                        k[27] + xy.m_y,
                        k[0]
                    );
                    pos = p;
                    fn_27_1ED8A4(
                        mgr, &pos, &self->line, 0, -1, k[26], k[0], k[0]
                    );
                }
            } else {
                unsigned* ids = fn_27_14D418(obj, 3);
                self->line = fn_27_1EE8F4(mgr, ids[2], ids[1], ids[0]);
            }

            if (!self->line || !(self->line->flags & 2)) {
                Line* first = 0;
                Line* second = 0;
                fn_27_1ED8A4(
                    mgr, &pos, &first, &second, -1, limit, self->a, self->b
                );
                self->line = second;
                self->type = 2;
            } else {
                self->type = 0;
            }

            if (self->line->flags & 0x400) {
                Line* first = 0;
                if (fn_27_1ED8A4(
                        mgr, &pos, &first, 0, -1, limit, self->a, self->b
                    )) {
                    self->line = first;
                }
            }
        } else {
            self->flags |= 1;
        }
    }

    if (!self->line) {
        Line* first = 0;
        Line* second = 0;
        if (!fn_27_1ED8A4(
                mgr, &self->pos, &first, &second, -1, limit, self->a, self->b
            )) {
            self->line = second;
            self->type = 2;
            self->flags |= 2;
        } else {
            self->line = first;
            self->type = 1;
        }

        if (!self->line) {
            self->line = &g_aiMgr->fallback;
        }
    }

    if (self->type != 2 && (self->line->flags & 0x20000) &&
        self->line->slope < k[28]) {
        __memcpy(&finalPos, &self->pos, sizeof(Vec3f));
        finalPos.m_y = self->line->height - k[1];
        if (!fn_27_1ED8A4(
                mgr, &finalPos, 0, 0, -1, limit, self->a, self->b
            )) {
            self->flags |= 2;
        }
    }
}
