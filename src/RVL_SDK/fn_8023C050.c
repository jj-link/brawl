#pragma force_active on
extern char lbl_80529CF8[];
extern unsigned char fn_8023A5A4(void);
extern void* fn_8022EFF8(int);
extern void fn_80246E54(void*, int);

int fn_8023C050(unsigned int arg0) {
    if (arg0 != 0 && arg0 != 1) {
        return 5;
    }
    if (!(*(unsigned char*)(lbl_80529CF8 + 0x643) & 0x10)) {
        return 4;
    }
    if (arg0 != *(unsigned short*)(lbl_80529CF8 + 0x16A4)) {
        if (fn_8023A5A4()) {
            void* p = fn_8022EFF8(2);
            if (p) {
                fn_80246E54(p, (unsigned char)arg0);
                *(unsigned short*)(lbl_80529CF8 + 0x16A4) = arg0;
            } else {
                return 3;
            }
        } else {
            return 6;
        }
    }
    return 0;
}
