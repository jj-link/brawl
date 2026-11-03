#pragma force_active on
extern "C" {
extern char lbl_79_data_708[1][0x144];
int setNode__9grGimmickFv(void*);
}

struct NodeNameTable {
    char data[0x144];
};

struct Base {
    char pad0[0x3C];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual int getNodeIndex(unsigned long, const char*);
};

struct Object : Base {
    char pad1[0x1D0];
    int nodes[30];
};

#pragma push
#pragma opt_propagation off
extern "C" int fn_79_21E4(Object* self) {
    NodeNameTable* const names =
        reinterpret_cast<NodeNameTable*>(&lbl_79_data_708[0][0]);

    if (!setNode__9grGimmickFv(self)) {
        return 0;
    }

    self->nodes[0] = self->getNodeIndex(0, "BlockN3");
    self->nodes[1] = self->getNodeIndex(0, "BlockN4");
    self->nodes[2] = self->getNodeIndex(0, "BlockN9");
    self->nodes[3] = self->getNodeIndex(0, "BlockN10");
    self->nodes[4] = self->getNodeIndex(0, "BlockN15");
    self->nodes[5] = self->getNodeIndex(0, "BlockN2");
    self->nodes[6] = self->getNodeIndex(0, "BlockN5");
    self->nodes[7] = self->getNodeIndex(0, "BlockN8");
    self->nodes[8] = self->getNodeIndex(0, "BlockN11");
    self->nodes[9] = self->getNodeIndex(0, "BlockN14");
    self->nodes[10] = self->getNodeIndex(0, "BlockN1");
    self->nodes[11] = self->getNodeIndex(0, "BlockN6");
    self->nodes[12] = self->getNodeIndex(0, "BlockN7");
    self->nodes[13] = self->getNodeIndex(0, "BlockN12");
    self->nodes[14] = self->getNodeIndex(0, "BlockN13");
    self->nodes[15] = self->getNodeIndex(0, "BlockN28");
    self->nodes[16] = self->getNodeIndex(0, "BlockN27");
    self->nodes[17] = self->getNodeIndex(0, "BlockN22");
    self->nodes[18] = self->getNodeIndex(0, "BlockN21");
    self->nodes[19] = self->getNodeIndex(0, "BlockN16");
    self->nodes[20] = self->getNodeIndex(0, "BlockN29");
    self->nodes[21] = self->getNodeIndex(0, "BlockN26");
    self->nodes[22] = self->getNodeIndex(0, "BlockN23");
    self->nodes[23] = self->getNodeIndex(0, "BlockN20");
    self->nodes[24] = self->getNodeIndex(0, "BlockN17");
    self->nodes[25] = self->getNodeIndex(0, "BlockN30");
    self->nodes[26] = self->getNodeIndex(0, "BlockN25");
    self->nodes[27] = self->getNodeIndex(0, "BlockN24");
    self->nodes[28] = self->getNodeIndex(0, "BlockN19");
    self->nodes[29] = self->getNodeIndex(0, "BlockN18");

    return 1;
}
#pragma pop