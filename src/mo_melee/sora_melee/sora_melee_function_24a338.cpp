#include <mu/wifi/mu_wifi_interface.h>

#pragma force_active on

struct Entry {
    char pad0[0x25];
    unsigned char state;
    char pad26[4];
    unsigned char team;
    char pad2b[3];
    signed char value;
    char pad2f[0x27d];
};

struct Rules {
    char pad0[8];
    unsigned char mode;
    char pad9[0xa];
    unsigned char teams;
    unsigned char special;
};

struct Context {
    char pad0[0x44];
    Rules* rules;
    char pad48[0x84];
    Entry* entries;
    char padD0[1];
    unsigned char active;
    char padD2[6];
    unsigned char d8;
    unsigned char d9;
    unsigned char da;
    char padDB[0x25];
    int result;
    int count;
    char pad108[0x11d];
    unsigned char b225;
    unsigned char b226;
};

inline int getValue(Entry* e) {
    int n = 1;
    if (e->value >= 0)
        n = e->value;
    return n;
}

inline int getTeamBit(Entry* e) {
    return 1 << e->team;
}

inline int countActive(Context* self) {
    int total;
    int offset;
    total = 0;
    offset = 0;
    for (int i = 0; i < self->count; ++i, offset += 0x2ac) {
        Entry* e = (Entry*)((char*)self->entries + offset);
        if (e->state != 3 && e->value != 0)
            ++total;
    }
    return total;
}

extern "C" void fn_27_24D39C(Context*, int*, int*, int*);

extern "C" int fn_27_24A338(Context* self) {
    if (!self->active)
        return 0;

    Rules* rules = self->rules;
    if (!rules->special) {
        unsigned int mode = (rules->mode >> 2) & 0x3f;
        if (mode == 7) {
            int count = self->count;
            int total = 0;
            int zeros = 0;

            for (int i = 0; i < count; ++i) {
                Entry* e = &self->entries[i];
                if (e->state == 0) {
                    total += getValue(e);
                    if (e->value == 0)
                        ++zeros;
                }
            }

            if (total == 0) {
                self->result = 3;
                return 1;
            }

            if (!rules->teams) {
                if (!self->d8) {
                    int total2 = 0;
                    for (int i = 0; i < count; ++i) {
                        Entry* e = &self->entries[i];
                        if (e->state == 1)
                            total2 += getValue(e);
                    }
                    if (total2 <= 0) {
                        self->result = 4;
                        return 1;
                    }
                }
            } else {
                if (self->da && zeros) {
                    self->result = 3;
                    return 1;
                }

                int a, b[3], c[3];
                fn_27_24D39C(self, &a, b, c);
                if (b[0] == 0 || (self->d9 && b[0] < c[0])) {
                    self->result = 3;
                    return 1;
                }
                if (!self->d8 && b[1] <= 0 && b[2] <= 0) {
                    self->result = 4;
                    return 1;
                }
            }
            return 0;
        }

        if (mode == 2) {
            int total = 0;
            for (int i = 0; i < self->count; ++i) {
                Entry* e = &self->entries[i];
                if (e->state == 0)
                    total += getValue(e);
            }
            if (total == 0)
                return 1;
        }

        if (self->b226 && !self->b225) {
            if (!rules->teams) {
                if (g_muWifiInterfaceTask &&
                    (int)*((unsigned char*)g_muWifiInterfaceTask + 0xfd5) <= 1)
                    return 0;
            } else {
                int i;
                int mask;
                int offset;
                int total;
                total = 0;
                mask = 0;
                offset = 0;
                for (i = 0; i < self->count; ++i, offset += 0x2ac) {
                    Entry* e = (Entry*)((char*)self->entries + offset);
                    if (e->state != 3) {
                        int bit = getTeamBit(e);
                        if (!(mask & bit)) {
                            mask |= bit;
                            ++total;
                        }
                    }
                }
                if (total <= 1)
                    return 0;
            }
        }

        if (!rules->teams)
            return countActive(self) <= 1;

        int a, b[3], c[3];
        fn_27_24D39C(self, &a, b, c);
        return a <= 1;
    }

    int players = 0;
    int total = 0;
    for (int i = 0; i < self->count; ++i) {
        Entry* e = &self->entries[i];
        if (e->state == 0) {
            ++players;
            total += getValue(e);
        }
    }

    if ((unsigned int)((rules->mode >> 2) & 0x3f) == 7) {
        if (total == 0) {
            self->result = 3;
            return 1;
        }
    } else {
        return total < players;
    }
    return 0;
}
