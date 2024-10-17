#include <Domain/Game.h>
#include <gtest/gtest.h>


namespace Domain
{
namespace
{

class GameTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        pars = std::make_shared<std::vector<int>>(18, 4);
        game = std::make_unique<Game>(pars);
    }

    vector_ptr<int> pars;
    std::unique_ptr<Game> game;
};

TEST_F(GameTest, AddPlayer)
{
    game->AddPlayer("Alice");
    auto scorecards = game->GetScoreCards();
    EXPECT_EQ(scorecards.size(), 1);
    EXPECT_NE(scorecards.find("Alice"), scorecards.end());
}

TEST_F(GameTest, RemovePlayer)
{
    game->AddPlayer("Bob");
    game->RemovePlayer("Bob");
    auto scorecards = game->GetScoreCards();
    EXPECT_EQ(scorecards.size(), 0);
}

TEST_F(GameTest, AddHole)
{
    game->AddHole(5);
    auto pars = game->GetPars();
    EXPECT_EQ(*(--pars->end()), 5);
}

TEST_F(GameTest, RecordStroke)
{
    game->AddPlayer("Charlie");
    game->RecordStroke("Charlie", 1, 3);
    auto scorecards = game->GetScoreCards();
    EXPECT_EQ(scorecards["Charlie"]->GetTotalScore(), 3);
}

TEST_F(GameTest, MakeLeaderBoard)
{
    game->AddPlayer("David");
    game->AddPlayer("Eve");
    for (int i = 0; i < 18; ++i)
    {
        {
            game->RecordStroke("David", i, 4);
            game->RecordStroke("Eve", i, 3);
        }
    }

    auto leaderboard = game->MakeLeaderBoard();
    ASSERT_EQ(leaderboard->size(), 2);

    std::sort(leaderboard->begin(), leaderboard->end(),
              [](const auto &a, const auto &b) { return a.second < b.second; });

    EXPECT_EQ(leaderboard->at(0).first, "Eve");
    EXPECT_EQ(leaderboard->at(0).second, -1 * 18); // 1 under par *18
    EXPECT_EQ(leaderboard->at(1).first, "David");
    EXPECT_EQ(leaderboard->at(1).second, 0); // at par
}

TEST_F(GameTest, GetPars)
{
    auto pars = game->GetPars();
    EXPECT_EQ(pars->size(), 18);
    EXPECT_EQ((*pars)[0], 4);
}

TEST_F(GameTest, RecordStrokeForNonExistentPlayer)
{
    EXPECT_THROW(game->RecordStroke("Harry", 1, 3), std::runtime_error);
}

} // namespace
} // namespace Domain
