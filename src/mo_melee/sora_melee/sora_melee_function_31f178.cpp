#pragma force_active on
extern "C" {
void __dt__16acCmdInterpreterFv(void* p, short flag);
void __dl__FPv(void* p);

void* fn_27_31F178(void* p, int flag) {
    if (p != 0) {
        void* a = (char*)p + 0x4b0;
        if (a != 0 && a != 0) {
            __dt__16acCmdInterpreterFv(a, 0);
        }
        if ((char*)p + 0x384 != 0) {
            void* b = (char*)p + 0x460;
            if (b != 0) {
                __dt__16acCmdInterpreterFv(b, 0);
            }
        }
        if ((char*)p + 0x258 != 0) {
            void* c = (char*)p + 0x334;
            if (c != 0) {
                __dt__16acCmdInterpreterFv(c, 0);
            }
        }
        if ((char*)p + 0x12c != 0) {
            void* d = (char*)p + 0x208;
            if (d != 0) {
                __dt__16acCmdInterpreterFv(d, 0);
            }
        }
        if (p != 0) {
            void* e = (char*)p + 0xdc;
            if (e != 0) {
                __dt__16acCmdInterpreterFv(e, 0);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
