#pragma force_active on

extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__10grYakumonoFv(void*, int);
extern char lbl_40_data_4DF8[];
}

extern "C" void* fn_40_1C140(void* self, int flag) {
    if (self != 0) {
        void* p0x154 = *(void**)((char*)self + 0x154);
        *(char**)((char*)self + 0x3C) = lbl_40_data_4DF8;
        if (p0x154 != 0) {
            __dla__FPv(p0x154);
            *(void**)((char*)self + 0x154) = 0;
        }
        void* p0x160 = *(void**)((char*)self + 0x160);
        if (p0x160 != 0) {
            __dla__FPv(p0x160);
            *(void**)((char*)self + 0x160) = 0;
        }
        void* p0x164 = *(void**)((char*)self + 0x164);
        if (p0x164 != 0) {
            __dla__FPv(p0x164);
            *(void**)((char*)self + 0x164) = 0;
        }
        void* p0x168 = *(void**)((char*)self + 0x168);
        if (p0x168 != 0) {
            if (p0x168 != 0) {
                __dla__FPv((char*)p0x168 - 0x10);
            }
            *(void**)((char*)self + 0x168) = 0;
        }
        void* p0x16C = *(void**)((char*)self + 0x16C);
        if (p0x16C != 0) {
            __dl__FPv(p0x16C);
            *(void**)((char*)self + 0x16C) = 0;
        }
        __dt__10grYakumonoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
