#include <iterator>
#include <map>
#include <utility>
#include <thread>

#include <limits.h>

#include "VoronoiSolver.hpp"

Coordinate::Coordinate(const int x, const int y) : x(x), y(y) {}

size_t Coordinate::findDistance(const Coordinate& other){
    return 0;
}

VoroniStructures::VoroniStructures(std::map<seed, Coordinate>& seedToLocationMap){
    this->seedToLocationMap = std::move(seedToLocationMap);
}

void VoroniStructures::addCoordinate(const int x, const int y){
    Coordinate coord(x, y);
    seed closestSeed{0};
    size_t closestDistance{ULLONG_MAX};
    for(const auto& [key, value]: seedToLocationMap){
        size_t calculatedDistance = coord.findDistance(value);

        if(calculatedDistance < closestDistance){
            closestDistance = calculatedDistance;
            closestSeed = key;
        }
    }

    VoroniStructures::structuresLock.lock();
    coordinateToSeedMap.emplace(coord, closestSeed);
    VoroniStructures::structuresLock.unlock();
}

