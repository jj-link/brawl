#pragma force_active on
extern "C" {

struct SelCharVoiceEntry {
    unsigned char data[16];
};

extern const SelCharVoiceEntry lbl_804556D8[];

int exchangeSelCharVoice2SelCharVoiceLengthE__6muMenuFi(int idx) {
    return lbl_804556D8[idx].data[12];
}

}
