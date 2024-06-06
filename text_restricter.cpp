#include "text_restricter.h"
int main()
{
    TextRestricter textRestricter(std::make_unique<NoRestrictionStrategy>());

    std::cout << "[*] Test with 'NoRestrictionStrategy'." << std::endl;
    Test(textRestricter);

    std::cout << "\n[*] Test with 'CurseRestrictionStrategy'." << std::endl;
    textRestricter.ChangeStrategy(std::make_unique<CurseRestrictionStrategy>());
    Test(textRestricter);

    std::cout << "\n[*] Test with 'LengthRestrictionStrategy'." << std::endl;
    textRestricter.ChangeStrategy(std::make_unique<LengthRestrictionStrategy>(0, 8));
    Test(textRestricter);
}
