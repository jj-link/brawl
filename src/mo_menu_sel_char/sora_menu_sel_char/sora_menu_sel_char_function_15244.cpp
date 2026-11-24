#include <gm/gm_global.h>
#include <stdio.h>

#pragma force_active on

extern "C" {
int fn_10_12010(void*, int);
int fn_10_12E58(void*);
int fn_10_19D68(void*);
int fn_10_99B8(void*);
void fn_800B68F0(void*, float*, char*, char*);

extern char lbl_10_data_7C8[];
extern unsigned char lbl_10_rodata_6AC[];
extern unsigned char lbl_10_rodata_700[];
}

struct SelCharSub {
    char pad0[0x5cc];
    int m_5cc;
    unsigned char m_5d0;
    char pad1[0x640 - 0x5d1];
    unsigned char m_640;
};

struct VisibilityEntry {
    unsigned char bit : 1;
    char pad[11];
};

struct SelCharPlayer {
    int m_0;
    char pad0[0xb0 - 4];
    void* m_b0[42];
    VisibilityEntry entries[7];
    void* m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    char pad2[0x1dc - 0x1bc];
    int m_1dc;
    char pad3[0x1f4 - 0x1e0];
    SelCharSub* m_1f4;
    char pad4[0x200 - 0x1f8];
    int m_200;
    char pad5[0x370 - 0x204];
    int m_370;
};

#define SELECT_ALLOWED()                                      \
    enabled = 0;                                              \
    if (self->m_0 == 0) {                                    \
        if (port == self->m_1b0) {                           \
            if (self->m_1b4 != 0) enabled = 1;               \
        } else if (self->m_1b4 == 2) {                       \
            enabled = 1;                                     \
        }                                                     \
    }

#define CLASSIFY_STATE()                                      \
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4]; \
    int result;                                               \
    if (state >= 0 && state < 4) result = 1; else result = 0; \
    if (result != 0) {                                        \
        result = 0;                                           \
    } else {                                                  \
        if (state >= 4 && state < 0xc) result = 1; else result = 0; \
        if (result != 0) {                                    \
            result = 1;                                       \
        } else {                                              \
            int range;                                        \
            if (state >= 0xc && state < 0x10) range = 1; else range = 0; \
            result = 3;                                       \
            if (range != 0) result = 2;                       \
        }                                                     \
    }

struct LeftBound {
    float value;
};

struct Bounds {
    LeftBound left;
    float right, top, bottom;
};

extern "C" unsigned char fn_10_15244(
    SelCharPlayer* self, void* out, float* point, int port)
{
    char* base = lbl_10_data_7C8;

    if (self->m_200 != 0 || self->m_370 != 0)
        return 0;

    void* object = 0;
    unsigned char* entry = lbl_10_rodata_700;
    int i = 0;
    int enabled = 1;
    int index = 0;

    for (; i < 12; ++i, entry += 4) {
        index = entry[1];
        object = self->m_b0[index];
        if (object == 0)
            continue;

        enabled = 1;
        switch (entry[3]) {
        case 1: {
            enabled = 0;
            int allowed = 0;
            if (self->m_0 == 0) {
                CLASSIFY_STATE()
                if (result == 0) {
                    if (state != 1)
                        allowed = 1;
                } else if (state == 0xc &&
                           ((self->m_1b0 != 0 && port == self->m_1b0) ||
                            self->m_1b4 == 2)) {
                    allowed = 1;
                }
            }
            if (allowed != 0) {
                if (self->m_1dc < 0)
                    enabled = 1;
                void* player = *(void**)((char*)self->m_1ac + 0x10);
                if (player == 0) {
                    enabled = 1;
                } else {
                    int current = self->m_1b0;
                    int found = fn_10_19D68(player);
                    if (found == current)
                        enabled = 1;
                }
            }
            break;
        }
        case 2:
            if (((int)((unsigned char*)g_GameGlobal->m_selCharData)[4]) == 0x11) {
                enabled = 0;
            } else {
                SELECT_ALLOWED()
            }
            break;
        case 3:
            if (self->m_0 == 0) {
                CLASSIFY_STATE()
                int mode;
                if (result == 1) {
                    mode = 0;
                } else {
                    SelCharSub* sub = self->m_1f4;
                    if (sub->m_5d0 != 0)
                        mode = 2;
                    else
                        mode = sub->m_5cc == 2;
                }
                if (mode == 0 || self->m_1b4 == 0)
                    goto disable3;
            } else {
disable3:
                enabled = 0;
            }
            if (self->m_1b4 == 1 && port != self->m_1b0)
                enabled = 0;
            break;
        case 4:
            if (self->m_0 != 0 || self->m_1b4 != 1)
                enabled = 0;
            break;
        case 6:
            if (((int)((unsigned char*)g_GameGlobal->m_selCharData)[4]) == 1)
                enabled = 0;
            if (self->m_0 != 0 || self->m_1b4 != 1)
                enabled = 0;
            if (port != self->m_1b0)
                enabled = 0;
            break;
        case 5:
            if (self->m_0 != 0 || self->m_1b4 != 2)
                enabled = 0;
            break;
        case 7:
            if (self->m_0 != 0 || fn_10_12010(self, self->m_1b8) != 0xe) {
                enabled = 0;
            } else {
                SELECT_ALLOWED()
            }
            break;
        case 8:
            if (self->m_0 != 0 || fn_10_12010(self, self->m_1b8) != 0xf) {
                enabled = 0;
            } else {
                SELECT_ALLOWED()
            }
            break;
        case 9:
            enabled = 0;
            if (self->m_0 == 0 && self->m_1b8 == 0x1b &&
                fn_10_12010(self, self->m_1b8) != 0x1b) {
                SELECT_ALLOWED()
            }
            break;
        case 10:
            enabled = 0;
            if (self->m_0 == 0 && self->m_1b8 == 0x1b &&
                fn_10_12010(self, self->m_1b8) != 0x1c) {
                SELECT_ALLOWED()
            }
            break;
        case 11:
            enabled = 0;
            if (self->m_0 == 0 && self->m_1b8 == 0x1b &&
                fn_10_12010(self, self->m_1b8) != 0x1d) {
                SELECT_ALLOWED()
            }
            break;
        case 12:
            enabled = 0;
            if (self->m_0 == 0 && self->m_1b8 == 0x1b &&
                fn_10_12010(self, self->m_1b8) != 0x1e) {
                SELECT_ALLOWED()
            }
            break;
        case 13: {
            enabled = 0;
            if (((int)((unsigned char*)g_GameGlobal->m_selCharData)[4]) == 0xc &&
                self->m_0 == 1 && self->m_1f4->m_640 == 0) {
                int state = fn_10_12E58(self);
                if (state == 3 || state == 7 ||
                    (state == 0 && fn_10_99B8(self->m_1f4) != 0))
                    enabled = 1;
            }
            break;
        }
        }

        if (enabled != 0) {
            char firstBuffer[8];
            char secondBuffer[8];
            char* first;
            char* second;
            int number = entry[2];
            if (number > 0) {
                sprintf(firstBuffer, base + 0x388, number);
                first = firstBuffer;
                sprintf(secondBuffer, base + 0x390, number);
                second = secondBuffer;
            } else {
                first = base + 0x398;
                second = base + 0x3a0;
            }

            int j;
            unsigned char* table = lbl_10_rodata_6AC;
            for (j = 0; j < 7; ++table, ++j) {
                int value;
                if (j >= 0 && j < 7)
                    value = *table;
                else
                    value = 0x28;
                if (index == value)
                    break;
            }

            int visible;
            if (j == 7) {
                visible = 2;
            } else {
                visible = self->entries[j].bit != 0;
            }

            if (visible == 1) {
                Bounds bounds;
                fn_800B68F0(object, (float*)&bounds, first, second);
                if (bounds.left.value <= point[0] && bounds.right >= point[0] &&
                    bounds.bottom <= point[1] && bounds.top >= point[1]) {
                    Bounds* output = (Bounds*)out;
                    output->left = bounds.left;
                    unsigned char result = ((unsigned char (*)[4])lbl_10_rodata_700)[i][0];
                    output->right = bounds.right;
                    output->top = bounds.top;
                    output->bottom = bounds.bottom;
                    return result;
                }
            }
        }
    }
    return 0;
}
