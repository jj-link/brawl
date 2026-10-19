#pragma force_active on
extern "C" int fn_27_263A88(void*, int, int, int);

struct grYakumono {
    unsigned char unk[0x14C];
    void* area;

    bool enableArea();
};

bool grYakumono::enableArea() {
    if (!area)
        return false;

    fn_27_263A88(area, 1, 0, -1);
    return true;
}
