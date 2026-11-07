#pragma force_active on
extern "C" {
extern unsigned char lbl_49_data_ED8[];
void __dl__FPv(void*);
void fn_49_1414(void*, int);
}

extern "C" void* fn_49_43AC(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x160);
        *(void**)(base + 0x3C) = lbl_49_data_ED8;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x164);
        *(void**)(base + 0x160) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x168);
        *(void**)(base + 0x164) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x16C);
        *(void**)(base + 0x168) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x170);
        *(void**)(base + 0x16C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x170) = 0;
        fn_49_1414(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
