#include <gm/gm_global.h>
#include <mu/selchar/mu_selchar.h>
#include <new>

#pragma force_active on

extern "C" {
int fn_10_C48C(void*, int);
void fn_10_FD00(void*, int);
int fn_10_B398(void*, int, int, int, int);
int fn_10_B678(void*, int);
int fn_10_B79C(void*, int, int*, int*, unsigned char*);
int fn_10_BA4C(void*, int*, int*, unsigned char*);
void fn_10_10398(void*, int);
void fn_10_1046C(void*, int, int, unsigned char);
void fn_10_105A0(void*, int);
void fn_10_B2A4(void*, int, int, int);
extern const unsigned char lbl_10_rodata_128[];
}

struct Info {
    unsigned char flag;
    int a;
    unsigned char b;
    int c;
    unsigned char d;
};

struct BoolWrap {
    bool b;
    BoolWrap(int n) { b = n != 0; }
};

extern "C" void fn_10_4374(muSelCharTask* self) {
    int b, a, d, c;
    Info out1, out2;
    int idx = fn_10_C48C(self, ((unsigned char*)g_GameGlobal->m_selCharData)[4]);
    unsigned char storage[sizeof(BoolWrap)];
    BoolWrap* valid = new (storage) BoolWrap(idx);
    const unsigned char* entry = lbl_10_rodata_128 + idx * 6;
    int totalFlag = 0;
    unsigned char scoreType;
    int usePlayers = 1;
    int useScore = 1;

    if (valid->b) {
        int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        int category;

        if (state >= 0 && state < 4)
            category = 1;
        else
            category = 0;

        if (category != 0) {
            category = 0;
        } else {
            if (state >= 4 && state < 12)
                category = 1;
            else
                category = 0;

            if (category != 0) {
                category = 1;
            } else {
                int result;
                if (state >= 12 && state < 16)
                    result = 1;
                else
                    result = 0;
                category = 3;
                if (result != 0)
                    category = 2;
            }
        }

        switch (category) {
        case 1:
            if (entry[4] && *((unsigned char*)self + 0x5fc)) {
                int special;
                if (state == 8 || state == 14)
                    special = 1;
                else
                    special = 0;

                if (special && *(int*)((char*)self + 0x600) == 1) {
                    const unsigned char* table;
                    int index = fn_10_C48C(self, state) * 6;
                    table = lbl_10_rodata_128;
                    fn_10_FD00(self, 6);
                    int total = 0;
                    int i = 0;
                    do {
                        total += fn_10_B398(
                            self, i, *(int*)((char*)self + 0x5e0), 0, 0);
                        i++;
                    } while (i < 0x23);
                    self->dispHighScore(3, total, table[index]);
                } else {
                    fn_10_FD00(self, 3);
                    int result = fn_10_B79C(
                        self, *(int*)((char*)self + 0x5e0),
                        &a, &b, &out1.flag);
                    self->dispHighScore(4, result, a);
                    if (out1.flag) {
                        fn_10_1046C(self, 0, out1.a, out1.b);
                        fn_10_1046C(self, 1, out1.c, out1.d);
                    } else {
                        fn_10_105A0(self, 0);
                        fn_10_105A0(self, 1);
                    }
                    if ((int)((unsigned char*)g_GameGlobal->m_selCharData)[4] != 7)
                        fn_10_10398(self, b);
                    usePlayers = 0;
                }
                useScore = 0;
            }
            break;

        case 2:
        case 3:
            if (entry[5] &&
                (state != 14 || *(int*)((char*)self + 0x600) != 1)) {
                fn_10_FD00(self, 3);
                int result = fn_10_BA4C(self, &c, &d, &out2.flag);
                self->dispHighScore(4, result, c);
                fn_10_10398(self, d);
                if (out2.flag) {
                    fn_10_1046C(self, 0, out2.a, out2.b);
                    fn_10_1046C(self, 1, out2.c, out2.d);
                } else {
                    fn_10_105A0(self, 0);
                    fn_10_105A0(self, 1);
                }
                usePlayers = 0;
                useScore = 0;
            }
            break;
        }

        if ((int)((unsigned char*)g_GameGlobal->m_selCharData)[4] == 7)
            fn_10_10398(self, *(int*)((char*)self + 0x5e0));

        if (usePlayers) {
            fn_10_B2A4(
                self, 0,
                *(int*)((char*)self->m_selCharPlayerAreas[0] + 0x1b8),
                *(int*)((char*)self + 0x5e0));

            if ((int)((unsigned char*)g_GameGlobal->m_selCharData)[4] == 8 &&
                *(int*)((char*)self + 0x600) == 1) {
                fn_10_B2A4(
                    self, 1,
                    *(int*)((char*)self->m_selCharPlayerAreas[1] + 0x1b8),
                    *(int*)((char*)self + 0x5e0));
            }

            if (useScore) {
                if (entry[3]) {
                    if (entry[1] == 7) {
                        scoreType = entry[0];
                        totalFlag = 1;
                    } else {
                        int i = 0;
                        do {
                            if (fn_10_B678(self, i) == 0)
                                break;
                            i++;
                        } while (i < 0x23);
                        if (i >= 0x23)
                            totalFlag = 1;
                        scoreType = entry[1];
                    }
                } else {
                    totalFlag = 0;
                }

                int mode;
                if ((int)((unsigned char*)g_GameGlobal->m_selCharData)[4] == 10) {
                    mode = 4;
                } else {
                    mode = 1;
                    if (totalFlag)
                        mode = 2;
                }
                fn_10_FD00(self, mode);

                if (totalFlag) {
                    int i;
                    int total;
                    total = 0;
                    i = 0;
                    do {
                        total += fn_10_B398(
                            self, i, *(int*)((char*)self + 0x5e0), 0, 0);
                        i++;
                    } while (i < 0x23);
                    self->dispHighScore(3, total, scoreType);
                }
            }
        }
    }
}
