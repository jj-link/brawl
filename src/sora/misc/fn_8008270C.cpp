#include <gf/gf_slow_manager.h>
#include <gm/gm_global.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}
};

struct Matrix34 {
    float m[3][4];
};

extern "C" void fn_8003E6DC(const Matrix34*, Vec3*);

static inline Vec3 getScale(const Matrix34* m)
{
    Vec3 v;
    fn_8003E6DC(m, &v);
    return v;
}

struct Entry {
    char pad00[0x70];
    Vec3 scale;
    char pad7C[0x34];
    float value;
    char padB4[0x28];
    Matrix34 matrix;
    char pad10C[0xE4];
    int kind;
    char pad1F4[4];
    int state;
    char pad1FC[4];
    int disabled;
};

struct EntryList {
    Entry** entries;
    int count;
    Entry*& at(int i) { return entries[i]; }
};

struct Group {
    unsigned char enabled;
    char pad01[3];
    EntryList* list;
    int id;
};

struct Manager {
    Group* groups;
    int count;
    char pad08[0x18];
    void* buffer20;
    int size24;
    unsigned int flags28;
    void* buffer2C;
    int size30;
    unsigned int flags34;
    unsigned char flag38;
    unsigned char flag39;
    unsigned char flag3A;
    unsigned char flag3B;
    unsigned char slow;
    unsigned char flag3D;
    char pad3E[2];
    int slowMode;
    float frameFraction;
    float rate;
    int divisor;
    unsigned int raw34() const { return flags34; }
    unsigned int raw28() const { return flags28; }
};

extern "C" {
unsigned int fn_8004E96C(void*);
unsigned int fn_8004E958(void*);
void fn_8003E388(const Matrix34*, Matrix34*);
void fn_80089224(Manager*);
void fn_800835B4(Manager*, Entry*, unsigned char, unsigned char);
int fn_800838DC(Manager*, Entry*);
void fn_80084524(Manager*, Entry*);
int fn_80084AD8(Manager*, Entry*, Entry*, int, int, unsigned char, int, int,
                unsigned char, unsigned char, unsigned char);
int fn_800851C8(Manager*, Entry*, Entry*, int, int, unsigned char, int, int,
                unsigned char, unsigned char, unsigned char, unsigned char);
void fn_80082FDC(Manager*, int, int, EntryList*);
void fn_800831AC(Manager*, int, int, EntryList*);
void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
}

extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;
extern const double lbl_805A1BC0;
extern const double lbl_805A1BC8;

static int findGroup(Manager* self, int id)
{
    for (int i = 0; i < self->count; ++i) {
        if (self->groups[i].id == id)
            return i;
    }
    return -1;
}

extern "C" int fn_8008270C(
    Manager* self, int id, int* index, int arg3, int arg4, unsigned char arg5,
    int arg6, int arg7, unsigned char arg8, unsigned char arg9,
    unsigned char arg10, unsigned char arg11, unsigned char otherGroup,
    int otherId, unsigned char arg14, unsigned char arg15)
{
    int groupIndex = findGroup(self, id);

    if (otherGroup && otherId != -1)
        otherId = findGroup(self, otherId);

    if (gfSlowManager::getSlowRate() != 1) {
        self->slow = 1;
        self->slowMode = 1;

        if (fn_8004E96C(g_GameGlobal) == 1)
            self->slowMode = 1;
        else if (fn_8004E958(g_GameGlobal) == 1)
            self->slowMode = 0;
        else
            self->slowMode = 2;

        self->rate = lbl_805A1BBC / (float)gfSlowManager::getSlowRate();
        float frame = g_GameGlobal->getGameFrame();
        self->frameFraction = frame - (float)(int)frame;
    } else {
        self->frameFraction = lbl_805A1BB8;
        self->rate = lbl_805A1BBC;
        self->slow = 0;
        self->flag3D = 0;
    }

    if (self->divisor > 1)
        self->rate /= (float)self->divisor;

    int result = 0;
    if (groupIndex != -1 && self->groups[groupIndex].enabled) {
        fn_80089224(self);

        Group* group = self->groups + groupIndex;
        EntryList* list = group->list;
        EntryList* other;
        if (otherGroup)
            other = self->groups[otherId].list;

        for (int i = list->count - 1; i >= 0; --i) {
            if (list->at(i)->disabled == 0 &&
                (lbl_805A1BB8 != list->at(i)->value || list->at(i)->state != 0) &&
                (arg6 != 0 || *index != -1 || !arg11 || self->flag39)) {
                fn_800835B4(self, list->at(i), arg11, arg14);
            }
        }

        for (int i = 0; i < list->count; ++i) {
            if (lbl_805A1BB8 == list->at(i)->value && list->at(i)->state == 0) {
                int kind = list->at(i)->kind;
                if (kind == 0 || kind % 2 != 0) {
                    if (arg6 != 0) {
                        result = fn_80084AD8(
                            self, list->at(i), 0, arg3, arg4, arg5,
                            arg6, arg7, arg8, arg9, arg10);
                    } else if (*index == -1) {
                        if (!arg11) {
                            result = fn_800851C8(
                                self, list->at(i), 0, arg3, arg4, arg5,
                                arg6, arg7, arg8, arg9, arg10, arg15);
                        } else {
                            if (kind == 101) {
                                self->flag3A = 1;
                                self->flag3B = arg5;
                            } else {
                                self->flag3A = 0;
                            }

                            self->flag38 = 1;
                            result = fn_800838DC(self, list->at(i));
                            fn_80084524(self, list->at(i));
                            self->flag39 = 1;
                        }
                    } else if (!otherGroup) {
                        Matrix34 matrix;
                        Vec3 scale;

                        fn_8003E388(&list->at(*index)->matrix, &matrix);
                        scale = getScale(&matrix);
                        int idx = *index;
                        list->at(idx)->scale = scale;

                        result = fn_800851C8(
                            self, list->at(i), list->at(idx),
                            arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,
                            arg15);
                    } else {
                        Matrix34 matrix;
                        Vec3 scale;

                        fn_8003E388(&other->at(0)->matrix, &matrix);
                        scale = getScale(&matrix);
                        other->at(0)->scale = scale;

                        result = fn_800851C8(
                            self, list->at(i), other->at(0), arg3,
                            arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg15);
                    }
                }
            }
        }

        for (int i = 0; i < list->count; ++i) {
            int kind = list->entries[i]->kind;

            if (kind == 1) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 2) {
                        fn_80082FDC(self, i, j, list);
                        break;
                    }
                }
            } else if (kind == 3) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 4) {
                        fn_80082FDC(self, i, j, list);
                        break;
                    }
                }
            } else if (kind == 5) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 6) {
                        fn_80082FDC(self, i, j, list);
                        break;
                    }
                }
            } else if (kind == 7) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 8) {
                        fn_80082FDC(self, i, j, list);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < list->count; ++i) {
            int kind = list->entries[i]->kind;

            if (kind == 9) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 10) {
                        fn_800831AC(self, i, j, list);
                        break;
                    }
                }
            } else if (kind == 11) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 12) {
                        fn_800831AC(self, i, j, list);
                        break;
                    }
                }
            } else if (kind == 13) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 14) {
                        fn_800831AC(self, i, j, list);
                        break;
                    }
                }
            } else if (kind == 15) {
                for (int j = 0; j < list->count; ++j) {
                    if (list->entries[j]->kind == 16) {
                        fn_800831AC(self, i, j, list);
                        break;
                    }
                }
            }
        }
    }

    if (!(self->flags34 & 0x80000000))
        fn_8027EABC(lbl_805A0EC8, self->buffer2C, self->raw34() * 4, 0x15);

    self->buffer2C = 0;
    self->size30 = 0;
    self->flags34 = (self->flags34 & 0x40000000) | 0x80000000;

    if (!(self->flags28 & 0x80000000))
        fn_8027EABC(lbl_805A0EC8, self->buffer20, self->raw28() * 4, 0x15);

    self->buffer20 = 0;
    self->size24 = 0;
    self->flags28 = (self->flags28 & 0x40000000) | 0x80000000;

    return result;
}
