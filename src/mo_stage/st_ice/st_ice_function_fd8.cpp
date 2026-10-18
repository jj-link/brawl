#pragma force_active on
struct Ground {
    char pad[0x3c];

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
    virtual void startup(void*, int, int);
    virtual void unusedA0();
    virtual void setData(void*);
    virtual void gap0();
    virtual void gap1();
    virtual void gap2();
    virtual void gap3();
    virtual void gap4();
    virtual void gap5();
    virtual void gap6();
    virtual void gap7();
    virtual void gap8();
    virtual void gap9();
    virtual void gap10();
    virtual void gap11();
    virtual void gap12();
    virtual void gap13();
    virtual void gap14();
    virtual void gap15();
    virtual void gap16();
    virtual void gap17();
    virtual void gap18();
    virtual void gap19();
    virtual void gap20();
    virtual void gap21();
    virtual void gap22();
    virtual void gap23();
    virtual void gap24();
    virtual void gap25();
    virtual void gap26();
    virtual void gap27();
    virtual void gap28();
    virtual void gap29();
    virtual void gap30();
    virtual void gap31();
    virtual void gap32();
    virtual void gap33();
    virtual void gap34();
    virtual void gap35();
    virtual void gap36();
    virtual void gap37();
    virtual void gap38();
    virtual void gap39();
    virtual void gap40();
    virtual void gap41();
    virtual void gap42();
    virtual void gap43();
    virtual void gap44();
    virtual void gap45();
    virtual void gap46();
    virtual void gap47();
    virtual void gap48();
    virtual void gap49();
    virtual void gap50();
    virtual void gap51();
    virtual void gap52();
    virtual void gap53();
    virtual void gap54();
    virtual void gap55();
    virtual void gap56();
    virtual void gap57();
    virtual void gap58();
    virtual void gap59();
    virtual void gap60();
    virtual void gap61();
    virtual void gap62();
    virtual void gap63();
    virtual void gap64();
    virtual void gap65();
    virtual void gap66();
    virtual void gap67();
    virtual void gap68();
    virtual void gap69();
    virtual void gap70();
    virtual void gap71();
    virtual void gap72();
    virtual void gap73();
    virtual void gap74();
    virtual void gap75();
    virtual void gap76();
    virtual void set3F0(void*);
    virtual void set420(void*);
    virtual void set4CC(void*);
    virtual void setIndex(int);
    virtual void set4D0(void*);
};

struct Stage {
    char pad0[0x9c];
    void* data9C;
    char padA0[0x100];
    void* archive;
    char pad1A4[0x24c];
    char data3F0[0x30];
    char data420[0xac];
    char data4CC[4];
    char data4D0[4];
};

extern "C" {
extern char lbl_62_data_0[];

Ground* fn_62_DB20(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_62_FD8(Stage* self, int kind) {
    char* data = lbl_62_data_0;
    Ground* ground;
    int index;

    switch (kind) {
    case 8:
        ground = fn_62_DB20(8, data + 0x128, data + 0x130);
        index = 0;
        break;
    case 9:
        ground = fn_62_DB20(9, data + 0x140, data + 0x130);
        index = 1;
        break;
    case 10:
        ground = fn_62_DB20(10, data + 0x148, data + 0x130);
        index = 2;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->startup(self->archive, 0, 0);
        ground->setData(self->data9C);
        ground->set3F0(self->data3F0);
        ground->set420(self->data420);
        ground->set4CC(self->data4CC);
        ground->setIndex(index);
        ground->set4D0(self->data4D0);
    }
}
}
