#pragma force_active on
typedef unsigned char u8;
class muSelCharPlayerArea {
public:
    bool isTeamBattle();
    void setCharPic(int, int, int, bool, int, int);
};
extern "C" u8 lbl_10_rodata_568[];
extern "C" void fn_10_12070(muSelCharPlayerArea* self, int arg1) {
    u8* base = (u8*)self;
    u8* tbl = lbl_10_rodata_568;
    int color;
    int player;
    int kind = *(int*)(base + 0x1B8);
    *(int*)(base + 0x1E8) = arg1;
    if (kind == 14) {
        switch (kind) {
        case 14: tbl = (u8*)((unsigned int)tbl + 0x18); kind = tbl[arg1]; break;
        case 3: tbl = (u8*)((unsigned int)tbl + 0x1C); kind = tbl[*(int*)(base+0x1EC)]; break;
        case 27: tbl = (u8*)((unsigned int)tbl + 0x20); kind = tbl[*(int*)(base+0x1F0)]; break;
        }
        color = *(int*)(base+0x1BC);
        player = *(int*)(base+0x1B4);
        self->setCharPic(kind, player, color, self->isTeamBattle(), *(int*)(base+0x1C0), *(u8*)(base+0x1C4));
    }
}
