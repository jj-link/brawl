#pragma force_active on
class soSoundIdExchanger {
public:
    virtual ~soSoundIdExchanger();
};

class soSoundIdExchangerNull : public soSoundIdExchanger {
public:
    virtual ~soSoundIdExchangerNull();
};

extern soSoundIdExchangerNull g_soSoundIdExchangerNull;

extern "C" {
soSoundIdExchanger* fn_27_281628() {
    return &g_soSoundIdExchangerNull;
}
}
