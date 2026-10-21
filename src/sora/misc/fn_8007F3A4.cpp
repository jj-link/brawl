// main/mv_movie_player.cpp

#include <mv/mv_movie_player.h>
#pragma force_active on

extern mvMoviePlayer* lbl_805A025C;

mvMoviePlayer* mvMoviePlayer::getInstance() {
    return lbl_805A025C;
}
