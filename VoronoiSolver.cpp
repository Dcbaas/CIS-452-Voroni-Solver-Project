#include <iterator>
#include <map>
#include <utility>
#include <thread>

#include <limits.h>

#include "VoronoiSolver.hpp"

Coordinate::Coordinate(const int x, const int y) : x(x), y(y) {}

size_t Coordinate::findDistance(Coordinate& other){
    return 0;
}

//bool operator<(Coordinate& other){
    //size_t thisSize = this->x * this->y;
    //size_t otherSize = other.x * other.y;
    //return thisSize < otherSize;
//}
//bool operator<(Coordinate& lhs, Coordinate& rhs){
    //return true;
//}
VoroniStructures::VoroniStructures(std::map<seed, Coordinate>& seedToLocationMap){
    this->seedToLocationMap = std::move(seedToLocationMap);
}

void VoroniStructures::addCoordinate(const int x, const int y){
    Coordinate coord(x, y);
    std::pair<seed, Coordinate>* closestCoord = nullptr;
    size_t closestDistance = ULLONG_MAX;
    for(const auto& [key, value]: seedToLocationMap){
        continue;
    }

    VoroniStructures::structuresLock.lock();
    coordinateToSeedMap.emplace(coord, closestCoord->first);
    VoroniStructures::structuresLock.unlock();
}

//std::map<Coordinate, seed>& VoroniStructures::getCoordinateToSeedMap(){
    //return coordinateToSeedMap;
//}
