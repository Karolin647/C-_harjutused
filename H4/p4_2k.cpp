#include "p4_2k.h"
#include <filesystem>
using namespace std;

int main() {
    auto asukoht = filesystem::path("elemendid.txt");
    string elemendid[] = {"üks", "kaks", "kolm", "neli"};
    looFailJaKirjuta<string>(asukoht, elemendid, 4);
    return 0;
}
