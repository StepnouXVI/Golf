#pragma once

#include <Domain/Help.h>
#include <memory>
#include <string>
#include <vector>


namespace Domain
{

/**
 * @class ScoreCard
 * @brief Represents a score card for a player in a game of golf.
 */
class ScoreCard
{
  private:
    /**
     * @brief The name of the player who owns this score card.
     */
    std::string _playerName;

    /**
     * @brief The handicaps for each hole.
     */
    std::vector<int> _handicaps;

    /**
     * @brief The strokes taken for each hole.
     */
    std::vector<int> _strokes;

    /**
     * @brief The pars for each hole.
     */
    vector_ptr<int> _pars;

  public:
    /**
     * @brief Constructs a new score card for the given player with the given pars.
     * @param playerName The name of the player who owns this score card.
     * @param pars A vector of integers representing the pars for each hole.
     */
    ScoreCard(const std::string &playerName, vector_ptr<int> pars);

    /**
     * @brief Destroys the score card object.
     */
    ~ScoreCard() = default;

    /**
     * @brief Retrieves the name of the player who owns this score card.
     * @return The player's name.
     */
    std::string GetPlayerName() const;

    /**
     * @brief Sets the handicap for a specific hole.
     * @param holeIndex The index of the hole to set the handicap for.
     * @param handicap The handicap to set.
     */
    void SetHandicap(size_t holeIndex, int handicap);

    /**
     * @brief Records the strokes taken for a specific hole.
     * @param holeIndex The index of the hole to record strokes for.
     * @param strokes The number of strokes taken.
     */
    void RecordStrokes(size_t holeIndex, int strokes);

    /**
     * @brief Sets the par for a specific hole.
     * @param holeIndex The index of the hole to set the par for.
     * @param par The par to set.
     */
    void SetPar(size_t holeIndex, int par);

    /**
     * @brief Retrieves the total score for the player.
     * @return The total score.
     */
    int GetTotalScore() const;

    /**
     * @brief Retrieves the total score for the player, taking into account handicaps.
     * @return The total score with handicaps.
     */
    int GetTotalScoreWithHandicaps() const;

    /**
     * @brief Retrieves the score relative to par for the player.
     * @return The score relative to par.
     */
    int GetScoreRelativeToPar() const;

    /**
     * @brief Retrieves the number of holes in the score card.
     * @return The number of holes.
     */
    size_t GetHoleCount() const;

    /**
     * @brief Retrieves the par for a specific hole.
     * @param holeIndex The index of the hole to retrieve the par for.
     * @return The par for the hole.
     */
    int GetParForHole(size_t holeIndex) const;

    /**
     * @brief Retrieves the score for a specific hole.
     * @param holeIndex The index of the hole to retrieve the score for.
     * @return The score for the hole.
     */
    int GetScoreForHole(size_t holeIndex) const;
};

/**
 * @typedef ScoreCardPtr
 * @brief A shared pointer to a ScoreCard object.
 */
using ScoreCardPtr = std::shared_ptr<ScoreCard>;

} // namespace Domain
