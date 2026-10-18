#pragma force_active on
struct FtYoshiState {
    char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 6;
};

extern "C" {
bool fn_95_172CC(FtYoshiState* p)
{
    return p->b;
}
}
