#include <Domain/ScoreCard.h>
#include <gtest/gtest.h>

using namespace Domain;

class ScoreCardTest : public ::testing::Test
{
  protected:
    vector_ptr<int> pars;
    ScoreCardPtr scoreCard;

    void SetUp() override
    {
        pars = std::make_shared<std::vector<int>>(18, 4); // 18 holes, all par 4
        scoreCard = std::make_shared<ScoreCard>("John Doe", pars);
    }
};

TEST_F(ScoreCardTest, GetPlayerName)
{
    EXPECT_EQ(scoreCard->GetPlayerName(), "John Doe");
}

TEST_F(ScoreCardTest, GetTotalScore)
{
    for (size_t i = 0; i < 18; ++i)
    {
        scoreCard->RecordStrokes(i, 4);
    }
    EXPECT_EQ(scoreCard->GetTotalScore(), 72);
}

TEST_F(ScoreCardTest, GetTotalScoreWithHandicaps)
{
    for (size_t i = 0; i < 18; ++i)
    {
        scoreCard->SetHandicap(i, 1);
        scoreCard->RecordStrokes(i, 4);
    }
    EXPECT_EQ(scoreCard->GetTotalScoreWithHandicaps(), -18);
}

TEST_F(ScoreCardTest, GetScoreRelativeToPar)
{
    for (size_t i = 0; i < 18; ++i)
    {
        scoreCard->RecordStrokes(i, 5);
    }
    EXPECT_EQ(scoreCard->GetScoreRelativeToPar(), 18);
}

TEST_F(ScoreCardTest, GetHoleCount)
{
    EXPECT_EQ(scoreCard->GetHoleCount(), 18);
}

TEST_F(ScoreCardTest, GetParForHole)
{
    EXPECT_EQ(scoreCard->GetParForHole(0), 4);
}
