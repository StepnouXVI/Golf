#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>


#include <Domain/Help.h>
#include <Domain/ScoreCard.h>


namespace Domain
{

/**
 * @class Game
 * @brief Represents a game of golf, managing players, holes, and scores.
 */
class Game
{
  public:
    /**
     * @brief Constructs a new game with the given pars.
     * @param pars A vector of integers representing the pars for each hole.
     */
    Game(vector_ptr<int> pars);

    /**
     * @brief Destroys the game object.
     */
    ~Game();

    /**
     * @brief Adds a new player to the game.
     * @param name The name of the player to add.
     */
    void AddPlayer(const std::string &name);

    /**
     * @brief Removes a player from the game.
     * @param name The name of the player to remove.
     */
    void RemovePlayer(const std::string &name);

    /**
     * @brief Adds a new hole to the game with the given par.
     * @param par The par for the new hole.
     */
    void AddHole(int par);

    /**
     * @brief Records a stroke for a player on a specific hole.
     * @param playerName The name of the player who made the stroke.
     * @param holeNumber The number of the hole where the stroke was made.
     * @param stroke The number of strokes taken.
     */
    void RecordStroke(const std::string &playerName, int holeNumber, int stroke);

    /**
     * @brief Retrieves the score card for a specific player.
     * @param playerName The name of the player whose score card to retrieve.
     * @return A shared pointer to the player's score card.
     */
    ScoreCardPtr GetPlayerCard(const std::string &playerName);

    /**
     * @brief Retrieves a map of all score cards for all players.
     * @return An unordered map of player names to shared pointers to their score cards.
     */
    std::unordered_map<std::string, std::shared_ptr<ScoreCard>> GetScoreCards();

    /**
     * @brief Retrieves the pars for all holes in the game.
     * @return A vector of integers representing the pars for each hole.
     */
    const vector_ptr<int> GetPars();

    /**
     * @brief Generates a leaderboard for the game, ranking players by their scores.
     * @return A vector of pairs containing the player name and their score.
     */
    vector_ptr<std::pair<std::string, int>> MakeLeaderBoard() const;

  private:
    std::unordered_map<std::string, std::shared_ptr<ScoreCard>> _players; ///< Map of player names to their score cards.
    vector_ptr<int> _pars;                                                ///< Vector of pars for each hole.
};

/**
 * @typedef GamePtr
 * @brief A shared pointer to a Game object.
 */
using GamePtr = std::shared_ptr<Game>;

} // namespace Domain