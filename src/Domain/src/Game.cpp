#include <Domain/Game.h>
#include <algorithm>
#include <stdexcept>

namespace Domain
{

Game::Game(vector_ptr<int> pars) : _pars(std::move(pars))
{
}

Game::~Game() = default;

void Game::AddPlayer(const std::string &name)
{
    if (_players.find(name) != _players.end())
        return;
    _players[name] = std::make_shared<ScoreCard>(name, _pars);
}

void Game::RemovePlayer(const std::string &name)
{
    if (_players.find(name) != _players.end())
    {
        _players.erase(name);
    }
}

void Game::AddHole(int par)
{
    _pars->push_back(par);
}

void Game::RecordStroke(const std::string &playerName, int holeNumber, int stroke)
{
    auto playerIt = _players.find(playerName);
    if (playerIt == _players.end())
    {
        throw std::runtime_error("Player not found");
    }
    playerIt->second->RecordStrokes(holeNumber, stroke);
}

std::unordered_map<std::string, std::shared_ptr<ScoreCard>> Game::GetScoreCards()
{
    return _players;
}

const vector_ptr<int> Game::GetPars()
{
    return _pars;
}
ScoreCardPtr Game::GetPlayerCard(const std::string &playerName)
{
    auto player = _players.find(playerName);
    if (player == _players.end())
    {
        throw std::runtime_error("Player not found");
    }

    return player->second;
}

vector_ptr<std::pair<std::string, int>> Game::MakeLeaderBoard() const
{
    auto leaderBoard = std::make_shared<std::vector<std::pair<std::string, int>>>(_players.size());

    std::transform(_players.begin(), _players.end(), leaderBoard->begin(), [](const auto &player) {
        return std::make_pair(player.first, player.second->GetTotalScoreWithHandicaps());
    });

    std::sort(leaderBoard->begin(), leaderBoard->end(),
              [](const auto &a, const auto &b) { return a.second < b.second; });

    return leaderBoard;
}

} // namespace Domain
