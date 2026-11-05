#include <it/item.h>
#pragma force_active on

extern "C" int fn_27_28C7D0(BaseItem*);
extern "C" int fn_27_28CCF0(BaseItem*, int);
extern int lbl_27_data_71BF0[];
extern const int lbl_27_rodata_50D8[];
extern unsigned int lbl_27_bss_64A0[];
extern const short lbl_27_rodata_53A0[];

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual void fn_27_FF68();
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};

inline int category(int kind) {
    if (kind == -3) return 1;
    if (kind < 0 || kind >= 0xB2) return -1;
    return lbl_27_data_71BF0[kind];
}

inline int parentKind(int kind) {
    if (kind == -3) return kind;
    if (kind < 0 || kind >= 0xB2) return kind;
    return lbl_27_rodata_50D8[kind];
}

inline int hasSpecial(int kind) {
    int cached = lbl_27_bss_64A0[kind];
    if (cached != 0) return (cached - 1) == 0;
    int i = 0;
    const short* p = (const short*)((const char*)lbl_27_rodata_53A0 + kind * 14);
    while (i < 7 && *p != -1) {
        if (*p == -2) {
            lbl_27_bss_64A0[kind] = 1;
            return 1;
        }
        ++p;
        ++i;
    }
    lbl_27_bss_64A0[kind] = 2;
    return 0;
}

extern "C" int fn_27_2A7E08(void*, BaseItem* item) {
    if (!item) return -1;
    int score = 0;
    if (item->isHaved()) return 10000;
    if (!fn_27_28C7D0(item)) return 10000;
    int kind = *(int*)((char*)item + 0x8C0);
    switch (category(kind)) {
    case 4:
    case 6:
    case 7:
        return 10000;
    case 2:
    case 3: {
        int parent = parentKind(kind);
        if (parent == kind) return 10000;
        score = 5000;
        break;
    }
    case 0:
    case 5:
        return 10000;
    case 8:
        score = 4000;
        break;
    default:
        if (kind == 0x37) return 10000;
        if (kind == 0x17 || kind == 0x33 || kind == 0xB) score = 1000;
        void* acc = *(void**)((char*)item + 0x1A4);
        if ((*(Class_C80**)((char*)acc + 0x14))->fn_27_FFF0() == 2) score += 1000;
        if (hasSpecial(kind)) score += 1000;
        int life = fn_27_28CCF0(item, 0x10000009);
        if (life < 0 || life > 1000) score += 1000;
        else score += life;
        break;
    }
    return score;
}
