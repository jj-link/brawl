#pragma force_active on
class emBase {
public:
    char _0[0x1c];
};

class emManager : public emBase {
public:
    virtual void v0(short);
    static void remove();
};

extern emManager* lbl_41_bss_30;

void emManager::remove() {
    if (lbl_41_bss_30) {
        lbl_41_bss_30->v0(1);
    }
    lbl_41_bss_30 = 0;
}
