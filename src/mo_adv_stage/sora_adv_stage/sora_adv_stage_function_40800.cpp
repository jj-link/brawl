#pragma force_active on
extern "C" int fn_800BA3D8(void*);
struct Entry { char pad[0xa8]; int values[40]; int count; int pad2; };
struct Object { char pad[0x970]; Entry entries[2]; };
inline int findEntry(char* base, int target) {
    int i;
    Entry* e = (Entry*)(base + 0x970);
    char* p;
    p = (char*)e;
    for (i = 0; i < 2; i++, p += 0x150, e++) {
        if ((((unsigned int)fn_800BA3D8(p) >> 31) ^ 1) != 0) {
            for (int j = 0; j < e->count; j++) {
                if (target == e->values[j]) return j;
            }
        }
    }
    return -1;
}
inline int available(char* obj, int index, int value) {
    if (findEntry(obj, value) >= 0) return 0;
    for (int i = index - 1; i >= 0; i--) {
        if (value == ((Object*)obj)->entries[i].pad2) return 0;
    }
    return 1;
}
inline int findEntry2(char* base, int target) {
    char* p;
    int i;
    Entry* e = (Entry*)(base + 0x970);
    p = (char*)e;
    for (i = 0; i < 2; i++, p += 0x150, e++) {
        if ((((unsigned int)fn_800BA3D8(p) >> 31) ^ 1) != 0) {
            for (int j = 0; j < e->count; j++) {
                if (target == e->values[j]) return j;
            }
        }
    }
    return -1;
}
inline int available2(char* obj, int index, int value) {
    if (findEntry2(obj, value) >= 0) return 0;
    for (int i = index - 1; i >= 0; i--) {
        if (value == ((Object*)obj)->entries[i].pad2) return 0;
    }
    return 1;
}
extern "C" int fn_40_40800(char* obj, int arg1, int arg2, int arg3, int arg4) {
    char* sub = obj + arg2 * 0xac;
    int total = *(int*)(sub + 0xe4);
    int q = total / 7;
    int r = total % 7;
    int empty = (r == 0);
    if (empty) r = 7;
    if (!empty) q++;
    int colLimit = (arg3 >= q - 1) ? r : 7;
    int valPlus;
    int valMinus;
    int rowMinus;
    int rowPlus;
    rowPlus = arg4 + 1;
    rowMinus = arg4 - 1;
    valPlus = rowPlus + arg3 * 7;
    valMinus = rowMinus + arg3 * 7;
    while (rowPlus < colLimit || rowMinus >= 0) {
        if (rowPlus < colLimit && valPlus < *(int*)(sub + 0xe4)) {
            if (available(obj, arg1, valPlus)) return rowPlus;
        }
        if (rowMinus >= 0 && valMinus < *(int*)(sub + 0xe4)) {
            if (available2(obj, arg1, valMinus)) return rowMinus;
        }
        valPlus++;
        rowPlus++;
        valMinus--;
        rowMinus--;
    }
    return -1;
}