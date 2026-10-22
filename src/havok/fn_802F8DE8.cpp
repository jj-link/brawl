#pragma force_active on
extern "C" void fn_802FAD24(void* arg0, void* arg1);

struct Node {
    char pad[0x20];
    unsigned short unk20;
};

struct Owner {
    char pad[0x28];
    Node** unk28;
    int unk2C;
    char pad30[4];
    Node** unk34;
    int unk38;
};

struct Key {
    char pad[0x20];
    unsigned short unk20;
    char pad22[4];
    unsigned char unk26;
};

extern "C" void fn_802F8DE8(Owner* arg0, Key* arg1) {
    if ((arg1->unk26 & 3) == 0) {
        arg0->unk34[arg1->unk20] = arg0->unk34[arg0->unk38 - 1];
        arg0->unk34[arg1->unk20]->unk20 = arg1->unk20;
        arg0->unk38--;
    } else {
        arg0->unk28[arg1->unk20] = arg0->unk28[arg0->unk2C - 1];
        arg0->unk28[arg1->unk20]->unk20 = arg1->unk20;
        arg0->unk2C--;
    }
    fn_802FAD24(arg0, arg1);
}
