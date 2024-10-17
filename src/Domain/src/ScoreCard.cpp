#include <Domain/ScoreCard.h>
#include <stdexcept>

using namespace Domain;

ScoreCard::ScoreCard(const std::string &playerName, vector_ptr<int> pars) : _playerName(playerName), _pars(pars)
{
    if (!pars || pars->empty())
    {
        throw std::invalid_argument("Pars must be provided and non-empty");
    }
    _handicaps = std::move(std::vector(pars->size(), 0));
    _strokes = std::move(std::vector(pars->size(), 0));
}

std::string ScoreCard::GetPlayerName() const
{
    return _playerName;
}

void ScoreCard::SetHandicap(size_t holeIndex, int handicap)
{
    if (holeIndex < _handicaps.size())
    {
        _handicaps[holeIndex] = handicap;
    }
    else
    {
        throw std::out_of_range("Invalid hole index");
    }
}

void ScoreCard::RecordStrokes(size_t holeIndex, int strokes)
{
    if (holeIndex < _strokes.size())
    {
        _strokes[holeIndex] = strokes;
    }
    else
    {
        throw std::out_of_range("Invalid hole index");
    }
}

int ScoreCard::GetTotalScore() const
{
    int total = 0;
    for (auto stroke : _strokes)
    {
        total += stroke;
    }
    return total;
}

int ScoreCard::GetTotalScoreWithHandicaps() const
{
    int total = 0;
    for (int i = 0; i < _strokes.size(); ++i)
    {
        total += _strokes[i] - (*_pars)[i] - _handicaps[i];
    }
    return total;
}

int ScoreCard::GetScoreRelativeToPar() const
{
    int relativeScore = 0;
    for (size_t i = 0; i < _strokes.size(); ++i)
    {
        relativeScore += (_strokes[i] - (*_pars)[i]);
    }
    return relativeScore;
}

size_t ScoreCard::GetHoleCount() const
{
    return _pars->size();
}

int ScoreCard::GetParForHole(size_t holeIndex) const
{
    if (holeIndex < _pars->size())
    {
        return (*_pars)[holeIndex];
    }
    else
    {
        throw std::out_of_range("Invalid hole index");
    }
}

int ScoreCard::GetScoreForHole(size_t holeIndex) const
{
    if (holeIndex < _strokes.size())
    {
        return _strokes[holeIndex];
    }
    else
    {
        throw std::out_of_range("Invalid hole index");
    }
}

void ScoreCard::SetPar(size_t holeIndex, int par)
{
    if (holeIndex < _pars->size() && par >= 0)
    {
        (*_pars)[holeIndex] = par;
    }
    else
    {
        throw std::out_of_range("Invalid hole index");
    }
}
