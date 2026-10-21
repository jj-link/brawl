#pragma force_active on
extern unsigned char lbl_805A024E;

class mvMoviePlayer {
public:
    unsigned char isPause() const;
};

unsigned char mvMoviePlayer::isPause() const {
    return lbl_805A024E;
}
