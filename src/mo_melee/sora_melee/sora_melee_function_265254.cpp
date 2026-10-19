#pragma force_active on
extern "C" void fn_27_263750(void* p, unsigned long v);

class grYakumono {
public:
    bool disableAttack(unsigned long v);
};

bool grYakumono::disableAttack(unsigned long v) {
    void* p = *(void**)((char*)this + 0x14c);
    if (p == 0) {
        return 0;
    }
    if ((long)v >= 0) {
        fn_27_263750(p, v);
    }
    return 1;
}
