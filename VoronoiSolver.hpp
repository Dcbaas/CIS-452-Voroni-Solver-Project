#pragma once

#include <map>
#include <mutex>

using seed = int;

class Coordinate{
public:
    Coordinate(const int x, const int y);
    size_t findDistance(Coordinate& other);
    int x;
    int y;
};

struct coordCompare{
    bool operator()(const Coordinate& lhs, const Coordinate& rhs)const{
        return true;
    }
};

class VoroniStructures{
public:
    VoroniStructures(std::map<seed, Coordinate>& seedToLocationMap);
    void addCoordinate(const int x, const int y);
    std::map<Coordinate, seed>& getCoordinateToSeedMap();
private:
    // This structure holds the entire bitmap and represents what seed a coordinate is closest to.
    std::map<Coordinate, seed, coordCompare> coordinateToSeedMap;

    // This structre represents  the seeds and where they are located.
    std::map<seed, Coordinate> seedToLocationMap;

    static std::mutex structuresLock;
};


