#pragma force_active on
extern "C" void fn_27_263A88(void*, int, int, int);

class grYakumono {
public:
    unsigned char unk000[0x14C];
    void* unk14C;

    bool disableArea();
};

bool grYakumono::disableArea() {
    if (!unk14C)
        return false;
    fn_27_263A88(unk14C, 0, 0, -1);
    return true;
}
