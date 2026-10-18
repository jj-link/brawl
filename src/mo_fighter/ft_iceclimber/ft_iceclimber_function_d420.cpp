#pragma force_active on
struct AccesserView;
struct EnumView;

struct FighterView {
    char pad[0x60];
    AccesserView* accesser;
};

struct AccesserView {
    char pad[0xD8];
    EnumView* enumeration;
};

struct GroundNull {
    unsigned int pad[2];
};

struct StatusView {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int getStatus();
};

struct GroundView : GroundNull {
    virtual void s000(); virtual void s001(); virtual void s002(); virtual void s003();
    virtual void s004(); virtual void s005(); virtual void s006(); virtual void s007();
    virtual void s008(); virtual void s009(); virtual void s010(); virtual void s011();
    virtual void s012(); virtual void s013(); virtual void s014(); virtual void s015();
    virtual void s016(); virtual void s017(); virtual void s018(); virtual void s019();
    virtual void s020(); virtual void s021(); virtual void s022(); virtual void s023();
    virtual void s024(); virtual void s025(); virtual void s026(); virtual void s027();
    virtual void s028(); virtual void s029(); virtual void s030(); virtual void s031();
    virtual void s032(); virtual void s033(); virtual void s034(); virtual void s035();
    virtual void s036(); virtual void s037(); virtual void s038(); virtual void s039();
    virtual void s040(); virtual void s041(); virtual void s042(); virtual void s043();
    virtual void s044(); virtual void s045(); virtual void s046(); virtual void s047();
    virtual void s048(); virtual void s049(); virtual void s050(); virtual void s051();
    virtual void s052(); virtual void s053(); virtual void s054(); virtual void s055();
    virtual void s056(); virtual void s057(); virtual void s058(); virtual void s059();
    virtual void s060(); virtual void s061(); virtual void s062(); virtual void s063();
    virtual void s064(); virtual void s065(); virtual void s066(); virtual void s067();
    virtual void s068(); virtual void s069(); virtual void s070(); virtual void s071();
    virtual void s072(); virtual void s073(); virtual void s074(); virtual void s075();
    virtual void s076(); virtual void s077(); virtual void s078(); virtual void s079();
    virtual void s080(); virtual void s081(); virtual void s082(); virtual void s083();
    virtual void s084(); virtual void s085(); virtual void s086(); virtual void s087();
    virtual void s088(); virtual void s089(); virtual void s090(); virtual void s091();
    virtual void s092(); virtual void s093(); virtual void s094(); virtual void s095();
    virtual void s096(); virtual void s097(); virtual void s098(); virtual void s099();
    virtual void s100(); virtual void s101();
    virtual void getBounds(float*, float*, float*, float*, int);
};

struct EnumView {
    char pad[0x10];
    GroundView* ground;
    char pad2[0x5C];
    StatusView* status;
};

extern "C" void fn_105_D420(FighterView* fighter, void*, float* range) {
    int status = fighter->accesser->enumeration->status->getStatus();

    switch (status) {
    case 0x117:
    case 0x11A: {
        float a, b, c, d;
        fighter->accesser->enumeration->ground->getBounds(&a, &b, &c, &d, 0);
        if (c < range[2])
            range[2] = c;
        if (d > range[3])
            range[3] = d;
    }
    }
}
