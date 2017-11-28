#include "PerfectPlayer.h"
#include <algorithm>
#include <vector>

PerfectPlayer::PerfectPlayer(Board::Player player):Player(player) {}

Board::Player other(Board::Player p){
    if(p == Board::Player::PLAYER_X){
        return Board::Player::PLAYER_O;
    }
    return Board::Player::PLAYER_X;
}

int PerfectPlayer::eval(Board b){
    if(b.winner() == mPlayer){
        return 1;
    }
    if(b.winner() == other(mPlayer)){
        return -1;
    }
    return 0;
}

std::vector<Board> nextMoves(Board b, Board::Player p){
    std::vector<Board> next;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(b(i,j) == Board::Player::EMPTY){
                next.push_back(b.move(i, j, p));
            }
        }
    }
    return next;
}

int PerfectPlayer::minMax(Board b, bool curPlayer){
    if(!b.movesRemain()) {
        return eval(b);
    }

    std::vector<int> score;
    std::vector<Board> next;

    if(curPlayer){
        next = nextMoves(b, mPlayer);
    }
    else{
        next = nextMoves(b, other(mPlayer));
    }
    for(auto && n:next){
        score.push_back(minMax(n, !curPlayer));
    }

    if(curPlayer){
        return *(std::max_element(score.begin(), score.end()));
    }
    else{
        return *(std::min_element(score.begin(), score.end()));
    }
}

Board PerfectPlayer::best(Board b){
    std::vector<Board> next = nextMoves(b, mPlayer);
    std::vector<int> score;

    for(auto && n : next){
        score.push_back(minMax(n, false));
    }

    return next[std::distance(score.begin(),std::max_element(score.begin(), score.end()))];
}

Board PerfectPlayer::move(Board b) {
    return best(b);
}
