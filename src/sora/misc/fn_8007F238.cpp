#pragma force_active on
extern "C" void fn_8007C944(void);
extern "C" int fn_8007D1AC(void);
extern int lbl_805A0214;
extern unsigned char lbl_805A024E;

class mvMoviePlayer {
public:
    void resetPause();
};

void mvMoviePlayer::resetPause() {
    if (lbl_805A0214 != 0) {
        if (fn_8007D1AC() == 4) {
            fn_8007C944();
        }
    }
    lbl_805A024E = 0;
}
