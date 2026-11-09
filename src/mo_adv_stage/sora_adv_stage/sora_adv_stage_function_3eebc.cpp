#pragma force_active on
#pragma fp_contract on
#pragma strict_ieee_fp off
#pragma opt_loop_invariants off

extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
int exchangeGmCharacterKind2Something__6muMenuFi(int);
int exchangeMuSelchkind2MuStockchkind__6muMenuFi(int);
void setFrameTex__8MuObjectFf(void*, float);
int sprintf(char*, const char*, ...);
extern const char lbl_40_data_17C50[];
}

extern "C" void fn_40_3EEBC(void* arg0) {
    char* obj;
    char* sp = (char*)arg0;
    char* ep = (char*)arg0;
    char* kp = (char*)arg0;
    char* ip;
    int k = 0;
    int i = 0;

    goto outer_test;

outer_body:
    {
        void* scn = *(void**)(sp + 0x93C);
        ip = ep;
        int j = 0;
        *(int*)(ep + 0xE8) = k;
        goto inner_test;

inner_body:
        {
            int sel = *(int*)(ip + 0x44);
            obj = *(char**)(kp + 0x744);

            if (sel == 0x1B) {
                sel = *(int*)((char*)arg0 + 0xC30);
            } else if (sel == 0x1B) {
                sel = *(int*)((char*)arg0 + 0xC30);
            } else if (sel == 0xE) {
                sel = *(int*)((char*)arg0 + 0xC34);
            } else if (sel == 3) {
                sel = *(int*)((char*)arg0 + 0xC38);
            }

            int mu = exchangeMuSelchkind2MuStockchkind__6muMenuFi(sel);
            int g = exchangeGmCharacterKind2Something__6muMenuFi(mu);
            setFrameTex__8MuObjectFf(obj, (float)(g * 10 + 1));

            char buf[8];
            sprintf(buf, lbl_40_data_17C50, j);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                scn, *(void**)(obj + 0x10), buf);

            kp += 4;
            k++;
            ip += 4;
            j++;
        }

inner_test:
        if (j < *(int*)(ep + 0xE4))
            goto inner_body;

        sp += 4;
        ep += 0xAC;
        i++;
    }

outer_test:
    if (i < *(int*)((char*)arg0 + 0x6F8))
        goto outer_body;
}
