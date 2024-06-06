#include <gtest/gtest.h>
#include "text_restricter.h" // Include the original implementation file

TEST(TextRestricterTests, NoRestrictionStrategyTest) {
    TextRestricter textRestricter(std::make_unique<NoRestrictionStrategy>());
    std::string concatedText;
    EXPECT_TRUE(textRestricter.ConcatText("hello", " world", concatedText));
    EXPECT_EQ(concatedText, "hello world");
}

TEST(TextRestricterTests, CurseRestrictionStrategyTest) {
    TextRestricter textRestricter(std::make_unique<CurseRestrictionStrategy>());
    std::string concatedText;
    EXPECT_FALSE(textRestricter.ConcatText("hello", " fuck", concatedText));
    EXPECT_TRUE(textRestricter.ConcatText("hello", " world", concatedText));
    EXPECT_EQ(concatedText, "hello world");
}

TEST(TextRestricterTests, LengthRestrictionStrategyTest) {
    TextRestricter textRestricter(std::make_unique<LengthRestrictionStrategy>(5, 10));
    std::string concatedText;
    EXPECT_TRUE(textRestricter.ConcatText("short", "text", concatedText));
    EXPECT_TRUE(textRestricter.ConcatText("good", " text", concatedText));
    EXPECT_EQ(concatedText, "good text");
    EXPECT_FALSE(textRestricter.ConcatText("thisis", "toolong", concatedText));
}
