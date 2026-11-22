#include <types.h>
#include <em/em_area_module_impl.h>
#include <mt/mt_prng.h>
#include <so/so_array.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

struct Selection {
    int entry;
    int target;

    int targetExists(soModuleAccesser* acc) const {
        return (unsigned int)emAreaModuleImpl::isExistTarget(acc, target);
    }
};

typedef soArrayFixed<Selection> Object_vptr_0;

struct EnemyWork {
    char pad0[0x18];
    soModuleAccesser* acc;
    char* table;
    char pad20[0x4];
    int count;
    int p28;
    char pad2C[0x8];
    u8 state;
    char pad35[0x3];
    int target38;
    Object_vptr_0* list;
    char pad40[0x1C];
    Selection current;
};

extern "C" {
int fn_41_23314(int x);
int fn_41_2A4F8(void* p);
int fn_41_2A6DC(void* p);
int fn_41_2A6E8(void* p);
int fn_41_2A70C(void* p, int n);
int fn_41_2A718(void* p);
void fn_41_2A630(void* p, soModuleAccesser* acc, int p28);
int fn_41_2A500(void* p, soModuleAccesser* acc, int p28, int n);
int fn_41_28DC8(void* self, int n);
int fn_41_23164(int n);
void fn_41_26430(soModuleAccesser* acc, int n);
void fn_41_29794(Object_vptr_0** list, Selection* pair);
}

inline void notifyTarget(soModuleAccesser* acc, const Selection* pair) {
    fn_41_26430(acc, pair->target);
}

struct Scratch {
    Selection state;
    int pick[8];
    int slot[8];
};

inline float minimum(EnemyWork* self, int* slots) {
    float result = 3.4028234663852886e+38f;
    for (int i = 0; i < 8; i++) {
        int entry = slots[i];
        if (fn_41_28DC8(self, entry) != 1U) {
            float t = (float)fn_41_2A6DC(self->table + entry * 8);
            if (t < result) {
                result = t;
            }
        }
    }
    return result;
}

inline int collect(EnemyWork* self, int* slots, int* picks, float best) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        picks[i] = -1;
    }
    for (int i = 0; i < 8; i++) {
        int entry = slots[i];
        if (fn_41_28DC8(self, entry) != 1U) {
            if ((float)fn_41_2A6DC(self->table + entry * 8) <= best) {
                picks[count] = i;
                count++;
            }
        }
    }
    return count;
}

inline int totalWeight(int* picks, int count, float* weights) {
    int target;
    int i;
    int total;
    total = 0;
    for (i = 0; i < count; i++) {
        target = picks[i];
        if (fn_41_23164(target) != 1U) {
            total = (int)((float)total + weights[target]);
        }
    }
    return total;
}

inline void selectWeight(int* picks, int count, float* weights, int random, int& selected) {
    int target;
    int i;
    int total;
    total = 0;
    for (i = 0; i < count; i++) {
        target = picks[i];
        if (fn_41_23164(target) != 1U) {
            total = (int)((float)total + weights[target]);
            if (random < total) {
                selected = target;
                break;
            }
        }
    }
}

inline char* entryAddress(EnemyWork* self, int index) {
    return self->table + index * 8;
}

inline bool invalidCurrent(soModuleAccesser* acc, const Selection* pair) {
    if (pair->entry == -2) {
        return true;
    }
    if (pair->target == -1) {
        return true;
    }
    return !emAreaModuleImpl::isExistTarget(acc, pair->target);
}

inline void saveCurrent(EnemyWork* self, const Selection* pair) {
    self->current = *pair;
}

inline int selectedSpecial(EnemyWork* self, const Selection* pair) {
    return fn_41_2A718(self->table + pair->entry * 8);
}

inline int selectionStatus(const Selection* pair) {
    return fn_41_23164(pair->target);
}

inline bool pairEqual(const Selection* a, const Selection* p) {
    if (a->entry != p->entry) {
        return false;
    }
    return a->target == p->target;
}

extern "C" int fn_41_29008(EnemyWork* self, int lo, int hi) {
    Scratch scratch;
    int cnt;
    int i;
    int j;
    int ret;
    int best;
    int m;
    int v;
    int sum;
    int found;
    int anyB;
    int anyOk;
    int e;
    float f31;
    float* w;
    if (self->state == 1) {
        return 0;
    }
    scratch.state.entry = -2;
    scratch.state.target = -1;
    w = (float*)soValueAccesser::getConstantIndefinite(self->acc, 0xA818, 0);
    ret = 0;
    for (m = 0; m < 8; m++) {
        scratch.slot[m] = -2;
    }
    best = -1;
    sum = 0;
    f31 = soValueAccesser::getValueFloat(self->acc, 0xBFD, 0);
    for (i = 0; i < 8; i++) {
        if (fn_41_23314(i) != 0 && emAreaModuleImpl::isExistTarget(self->acc, i)) {
            float wt = w[i];
            if (self->target38 == i) {
                wt = wt * f31;
                if (wt < 0.0f) {
                    wt = 1.0f;
                }
            }
            sum = (int)((float)sum + wt);
        }
    }
    if (sum > 0) {
        sum = randi(sum);
        i = 0;
        for (v = 0; v < 8; v++) {
            if (fn_41_23314(v) != 0 && emAreaModuleImpl::isExistTarget(self->acc, v)) {
                float wt = w[v];
                if (self->target38 == v) {
                    wt = wt * f31;
                    if (wt < 0.0f) {
                        wt = 1.0f;
                    }
                }
                i = (int)((float)i + wt);
                if (sum < i) {
                    best = v;
                    break;
                }
            }
        }
    }
    self->target38 = -1;
    found = 0;
    anyB = 0;
    anyOk = 0;
    for (e = 0; e < self->count; e++) {
        char* ent = self->table + e * 8;
        if (fn_41_2A4F8(ent) != 0) {
            v = fn_41_2A6DC(ent);
            if (lo <= v && hi >= v) {
                {
                    int cur;
                    for (cur = 0; cur < 8; cur++) {
                        int flag = 0;
                        if (fn_41_2A70C(ent, 8) == 0 && best != -1 && fn_41_23314(cur) == 1U) {
                            if (best != cur) {
                                continue;
                            }
                            flag = 1;
                        }
                        j = scratch.slot[cur];
                        if (fn_41_28DC8(self, j) != 0 || v < fn_41_2A6DC(self->table + j * 8)) {
                            if (fn_41_2A70C(ent, cur) == 0) {
                                if (fn_41_2A70C(ent, 8) == 0) {
                                    continue;
                                }
                                if (cur != self->current.target) {
                                    continue;
                                }
                            } else if (!emAreaModuleImpl::isExistTarget(self->acc, cur)) {
                                continue;
                            }
                            if (flag == 1U) {
                                found = 1;
                            }
                            if (fn_41_2A500(ent, self->acc, self->p28, cur) != 0) {
                                scratch.slot[cur] = e;
                                anyOk = 1;
                                if (flag == 1U) {
                                    anyB = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (best != -1 && found == 1U && anyB == 0) {
        self->target38 = best;
    }
    if (anyOk == 0) {
        return 0;
    }
    f31 = minimum(self, scratch.slot);
    cnt = collect(self, scratch.slot, scratch.pick, f31);
    if (cnt == 0) {
        return 0;
    }
    if (cnt == 1) {
        scratch.state.target = scratch.pick[0];
    } else {
        int tot = totalWeight(scratch.pick, cnt, w);
        tot = randi(tot);
        selectWeight(scratch.pick, cnt, w, tot, scratch.state.target);
    }
    if (selectionStatus(&scratch.state) == 1U) {
        return 0;
    }
    scratch.state.entry = scratch.slot[scratch.state.target];
    if (fn_41_28DC8(self, scratch.state.entry) == 1U || scratch.state.entry == -1) {
        return 0;
    }
    if (!invalidCurrent(self->acc, &self->current)) {
        if (self->list->size() <= 0) {
            fn_41_29794(&self->list, &self->current);
        } else {
            Selection* p = &self->list->at(0);
            if (!pairEqual(&self->current, p)) {
                fn_41_29794(&self->list, &self->current);
            }
        }
    }
    if (selectedSpecial(self, &scratch.state) == 1U) {
        saveCurrent(self, &scratch.state);
        if (emAreaModuleImpl::isExistTarget(self->acc, scratch.state.target) == 1U) {
            notifyTarget(self->acc, &scratch.state);
        }
    }
    fn_41_2A630(self->table + static_cast<unsigned int>(scratch.state.entry) * 8U, self->acc, self->p28);
    if (fn_41_2A6E8(entryAddress(self, scratch.state.entry)) != -1) {
        soStatusModule* status;
        soModuleAccesser* acc = self->acc;
        status = acc->m_enumerationStart->m_statusModule;
        status->changeStatusRequest(fn_41_2A6E8(self->table + static_cast<long>(scratch.state.entry) * 8L), acc);
        ret = 1;
    }
    return ret;
}