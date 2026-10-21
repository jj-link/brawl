#pragma force_active on
extern "C" {
typedef struct {
    unsigned char a[13];
    unsigned char b;
    unsigned char c[2];
} SelCharVoiceEntry;

extern const SelCharVoiceEntry lbl_804556D8[];

unsigned char exchangeSelCharVoice2SelCharVoiceLengthJ__6muMenuFi(int idx) {
    return lbl_804556D8[idx].b;
}
}
