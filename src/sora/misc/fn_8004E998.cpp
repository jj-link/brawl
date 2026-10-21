#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[9];
    u8 rate;
};

class GameGlobal {
public:
    Inner* unk0;
    void setSlowRate(u8);
};

inline u8 clampRate(u8 x) {
    u8 low = 1;
    if (x > 1) {
        low = x;
    }
    u8 result = 100;
    if (low < 100) {
        result = low;
    }
    return result;
}

void GameGlobal::setSlowRate(u8 x) {
    Inner* p = unk0;
    p->rate = clampRate(x);
}
