#pragma force_active on

struct BssObj {
    char pad0[0x48];
    unsigned char f48;
    char pad49[0x33F];
    int f388;
    int f38C;
    int f390;
    int f394;
    unsigned char f398;
};

struct SelStageObj {
    char pad0[0x40];
    int f40;
    char pad44[0x1E0];
    int f224;
    char pad228[0x2C];
    int f254;
    int f258;
    char pad25C[8];
    unsigned long long* p264;
    unsigned int* p268;
    unsigned long long* p26C;
    int f270;
    int f274;
    char pad278[0x5EDC];
    int f6154;
    int f6158;
    int f615C;
    int f6160;
    char pad6164[4];
    unsigned char f6168;
};

struct Ret3 {
    int a;
    int b;
    int c;
};

extern "C" {
void* __memcpy(void*, const void*, unsigned long);
void OSReport(const char*, ...);
int exchangeMuStageKindToSrStageKind__6muMenuFiii(int);
int fn_11_7CD0(void*, unsigned int);
void fn_11_6B6C(Ret3*, SelStageObj*, int);
void fn_11_6C94(Ret3*, SelStageObj*);
void fn_800CA73C(void*, int);
unsigned long long fn_803F1798(unsigned long long, unsigned int);
extern void* g_muWifiInterfaceTask;
extern void* lbl_11_bss_8;
extern char lbl_11_data_36C[];
}

inline void recordStage(int value) {
    ((BssObj*)lbl_11_bss_8)->f398 = 1;
    BssObj* bss = (BssObj*)lbl_11_bss_8;
    if (bss->f390 == 0) {
        bss->f390 = 1;
        bss->f388 = 0;
        bss->f38C = value;
    }
}

inline bool isWifiMode(int mode) {
    int flag = 0;
    unsigned int m = mode - 1;
    if (m <= 5U && ((1 << m) & 0x29)) flag = 1;
    return flag != 0;
}

extern "C" void fn_11_722C(SelStageObj* self) {
    switch (self->f6160) {
    case 0: {
        BssObj* bss = (BssObj*)lbl_11_bss_8;
        int flag = 0;
        if (bss != 0 && ((((unsigned int)bss->f48 >> 7) & 1U) == 1U)) {
            flag = 1;
            if (fn_11_7CD0((void*)bss, 0) <= 0)
                return;
        }
        Ret3 r;
        if ((unsigned int)(self->f40 - 3) <= 1U) {
            int choice;
            if (self->f6168 == 0) {
                int bit = 0;
                unsigned int n = self->f40 - 1;
                if (n <= 5U && ((1 << n) & 0x29)) bit = 1;
                if (bit == 0 && flag != 0) goto choose_one;
            }
            choice = 0;
            goto chosen;
        choose_one:
            choice = 1;
        chosen:;
            Ret3 r1;
            fn_11_6B6C(&r1, self, choice);
            __memcpy(&r, &r1, sizeof(r));
        } else {
            Ret3 r2;
            fn_11_6C94(&r2, self);
            __memcpy(&r, &r2, sizeof(r));
        }
        if (r.a != 2) {
            self->f254 = 1;
            self->f258 = exchangeMuStageKindToSrStageKind__6muMenuFiii(r.c);
        } else {
            self->f254 = 3;
            self->f258 = r.b;
        }
        if (r.a == 2) {
            recordStage(r.b);
            self->f6160 = 1;
            int v = self->f258;
            unsigned int* p = self->p268;
            p[v / 32] |= 1 << (v % 32);
        } else {
            self->f6160 = 3;
            if ((unsigned int)(self->f40 - 3) <= 1U) {
                unsigned long long x = fn_803F1798(1ULL, r.c);
                *self->p264 |= x;
            } else {
                unsigned long long x = fn_803F1798(1ULL, r.c);
                *self->p26C |= x;
            }
        }
        self->f6154 = r.a;
        self->f6158 = r.b;
        self->f615C = r.c;
        break;
    }
    case 1: {
        BssObj* bss = (BssObj*)lbl_11_bss_8;
        if (bss->f390 != 0) return;
        {
            int v = self->f258;
            self->p268[v / 32] |= 1 << (v % 32);
            bss = (BssObj*)lbl_11_bss_8;
            if (bss->f394 != 0) {
                OSReport(lbl_11_data_36C);
                self->f6168 = 1;
                self->f6160 = 0;
                return;
            }
            self->f6160 = 3;
        }
        break;
    }
    }
    if (self->f6160 == 3 && self->f274 != 1) {
        int flag = 0;
        unsigned int m = self->f40 - 1;
        if (m <= 5U && ((1 << m) & 0x29))
            flag = 1;
        if (flag != 0)
            fn_800CA73C(g_muWifiInterfaceTask, self->f258);
        self->f274 = 1;
        self->f224 = 0xB;
    }
}
