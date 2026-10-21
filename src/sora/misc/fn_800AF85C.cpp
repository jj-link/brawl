#pragma force_active on
typedef struct {
    int a;
    int b;
    int c;
    int d;
} SelVoiceEntry;

extern SelVoiceEntry lbl_804556D8[];

class muMenu {
public:
    static int exchangeSelchkind2SelCharVoice(int idx);
};

int muMenu::exchangeSelchkind2SelCharVoice(int idx)
{
    return lbl_804556D8[idx].c;
}
